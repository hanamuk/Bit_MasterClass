//cmynet.cpp

#include <stdio.h>
#include "CMyNet.h"
#include <ws2tcpip.h> //inet_pton()
CMyNet::CMyNet() : listen_socket(0)
{
    //1. ���̺귯�� �ʱ�ȭ(Winsock 2.2����)
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        printf("������ ���� �ʱ�ȭ ���� \n");
        exit(-1);
    }
}

CMyNet::~CMyNet()
    //2. ���̺귯�� ����
    WSACleanup();
}


void CMyNet::CreateSocket(int port)
{
    listen_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (listen_socket == INVALID_SOCKET)
        throw "���� ���� ����";

    SOCKADDR_IN addr;
    memset(&addr, 0, sizeof(addr)); //API ZeroMemory(&addr,sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY); //long���� network byte order��..
    int retval = bind(listen_socket, (SOCKADDR*)&addr, sizeof(addr));
    if (retval == SOCKET_ERROR)
        throw "bind ����";

    retval = listen(listen_socket, SOMAXCONN);
    if (retval == SOCKET_ERROR)
        throw "listen ����";
    Run();


}



void CMyNet::Run()
{
    SOCKET clientsocket;
    SOCKADDR_IN clientaddr;
    int addrlen = sizeof(clientaddr); //�ʱ�ȭ ���ϸ� ������

    while (true)
    {
        printf("Ŭ���̾�Ʈ ������\n");
        clientsocket = accept(listen_socket, (SOCKADDR*)&clientaddr, &addrlen);
        if (clientsocket == INVALID_SOCKET)
        {
            printf("accept ����\n");
            continue;
        }

        char ip[20];
        int port;
        GetAddress(clientsocket, ip, &port);
        printf("[Ŭ���̾�Ʈ ����] %s:%d\n", ip, port);

        RecvMessage(clientsocket);
    }
}

//echo(�޾Ƹ�)
void CMyNet::RecvMessage(SOCKET sock)
{
    while (1)
    {
        //����
        char buf[256];
        //���Ͽ� ����� �������κ��� ���޵� �޽����� �����Ѵ�
        // ��, ���� ������ ���� sizeof(buf)�� ũ�⸦ �غ��߰�, �� ������ ������ġ�� ����.
        //recv()�� return(retval) �� ���ؼ� ���� ���ŵ� byteũ�⸦ Ȯ�� �� �� �ִ�.
        int retval = recv(sock, buf, sizeof(buf), 0);

        buf[retval] = '\0'; //������ �ѱ拚 strlen��ŭ�� �Ѱ�ٰ� �����ϸ� strlen�� �ΰ��� ���� �ֱ⶧���� �������� �ΰ��� �־��ش�.
        printf(">> [���ŵ�����] : %s", buf);

        if (retval == -1 || retval == 0)
        {
            printf("���Ͽ��� or ������ ������\n");
            closesocket(sock);
            break;
        }

        //���ŵ� ������ �״�� �۽�
        //buf�� �ּҷκ��� retval�� byte��ŭ ����
        int retval1 = send(sock, buf, retval, 0);
        printf("    [�۽�]%dbyte\n", retval);
    }
    closesocket(sock);
}

//����� ��� ������ �̿��ؼ� �ּҸ� ȹ��
//getpeername(����), getsockname(�ڽ�)
void  CMyNet::GetAddress(SOCKET sock, char* ip, int* port)
{
    SOCKADDR_IN  addr;
    int addrlength = sizeof(addr);
    getpeername(sock, (SOCKADDR*)&addr, &addrlength);

    //inet_ntoa : �����ּ� -> ���ڿ�
    //#include <ws2tcpip.h> //inet_ntop
    inet_ntop(AF_INET, &(addr.sin_addr.s_addr), ip, INET_ADDRSTRLEN);
    *port = ntohs(addr.sin_port);

}

