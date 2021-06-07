//cmynet.cpp

#include <stdio.h>
#include "CMyNet.h"
#include <ws2tcpip.h> //inet_pton()
#include"Control.h"

//����ü�� �����ؼ� ���������� ���ְ� ������.. (����ü �ɹ� : CMyNet*, SOCKET)
//CreateThread�� �� ����ü �ּҸ� ����!
CMyNet* g_mynet = NULL;

CMyNet::CMyNet() : listen_socket(0)
{
    //1. ���̺귯�� �ʱ�ȭ(Winsock 2.2����)
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        printf("������ ���� �ʱ�ȭ ���� \n");
        exit(-1);
    }
    g_mynet = this;
}

CMyNet::~CMyNet()
{
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
    addr.sin_addr.s_addr = htonl(INADDR_ANY); //long���� network byte order��.. INADDR_ANY:���� pc �⺻�ּ�.
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
        GetAddress(clientsocket, ip, &port);    //����ּ� ��������.
        printf("[Ŭ���̾�Ʈ ����] %s:%d\n", ip, port);
        
        //vector�� ���� , 0���� �ε������� �������� ����. �迭�� ũ�Ⱑ �ڵ������� ����
        clients.push_back(clientsocket);

        //��ž����� ����(������ ���� ����)
        CloseHandle(CreateThread(0,0,WorkThread,(LPVOID)clientsocket,0,0));
       
    }
}

DWORD WINAPI CMyNet::WorkThread(LPVOID value)
{
    SOCKET sock = (SOCKET)value;

    while (1)
    {
        //����
        char buf[48];
        int retval = g_mynet->Recvn(sock, buf, sizeof(buf), 0);     //Recvn�� 3���� ���� ��ŭ �޾ƾ� ���ϵ�?

        if (retval == -1 || retval == 0)
        {
            printf("���Ͽ��� or ������ ������\n");
            //closesocket(sock);
            break;
        }

      
        Control::getInstance()->RecvData(buf,retval);

        //���ο��� ����
        retval = send(sock, buf, retval, 0);
        printf("[1�� 1 �۽�]%dbyte\n", retval);


        //��ü ����(1�� �� ���)
        //for (int i = 0; i < (int)g_mynet->clients.size(); i++)
        //{
        //    SOCKET s = g_mynet->clients[i]; //������ ������ []
        //    int retval1 = send(s, buf, retval, 0);
        //}
        //printf("[1�� �� �۽�]%dbyte\n", retval);
       
    }
    
    //vector����.
    for (int i = 0; i < (int)g_mynet->clients.size(); i++)
    {
        SOCKET s = g_mynet->clients[i]; //������ ������ []
        if (s == sock)
        {
            //erase�� ������ �ּ�(�迭�� �ּ�(��ġ))�� �䱸�Ѵ�.
            //g_mynet->clients.begin() �� �迭�� �����ּ� ��ȯ.
            g_mynet->clients.erase(g_mynet->clients.begin() + i);
            closesocket(sock);
            return 0;

        }
    }
 


    return 0;
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

int CMyNet::Recvn(SOCKET s, char* buf, int len, int flags)
{
    int received;
    char* ptr = buf;
    int left = len;
    while (left > 0)
    {
        received = recv(s, ptr, left, flags);
        if (received == SOCKET_ERROR)
            return SOCKET_ERROR;
        else if (received == 0)
            break;
        left -= received;
        ptr += received;
    }
    return (len - left);
}

