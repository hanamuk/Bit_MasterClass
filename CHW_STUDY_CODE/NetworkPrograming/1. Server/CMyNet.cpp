//cmynet.cpp

#include <stdio.h>
#include "CMyNet.h"
#include <ws2tcpip.h> //inet_pton()
CMyNet::CMyNet() : listen_socket(0)
{
    //1. 라이브러리 초기화(Winsock 2.2버전)
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        printf("윈도우 소켓 초기화 실패 \n");
        exit(-1);
    }
}

CMyNet::~CMyNet()
{
    //2. 라이브러리 해제
    WSACleanup();
}


void CMyNet::CreateSocket(int port)
{
    listen_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (listen_socket == INVALID_SOCKET)
        throw "소켓 생성 오류";

    SOCKADDR_IN addr;
    memset(&addr, 0, sizeof(addr)); //API ZeroMemory(&addr,sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY); //long형을 network byte order로..
    int retval = bind(listen_socket, (SOCKADDR*)&addr, sizeof(addr));
    if (retval == SOCKET_ERROR)
        throw "bind 오류";

    retval = listen(listen_socket, SOMAXCONN);
    if (retval == SOCKET_ERROR)
        throw "listen 오류";
    Run();


}



void CMyNet::Run()
{
    SOCKET clientsocket;
    SOCKADDR_IN clientaddr;
    int addrlen = sizeof(clientaddr); //초기화 안하면 난리함

    while (true)
    {
        printf("클라이언트 연결대기\n");
        clientsocket = accept(listen_socket, (SOCKADDR*)&clientaddr, &addrlen);
        if (clientsocket == INVALID_SOCKET)
        {
            printf("accept 오류\n");
            continue;
        }

        char ip[20];
        int port;
        GetAddress(clientsocket, ip, &port);
        printf("[클라이언트 접속] %s:%d\n", ip, port);

        RecvMessage(clientsocket);
    }
}

//echo(메아리)
void CMyNet::RecvMessage(SOCKET sock)
{
    while (1)
    {
        //수신
        char buf[256];
        //소켓에 연결된 상대방으로부터 전달된 메시지를 수신한다
        // 단, 나는 수신을 위해 sizeof(buf)의 크기를 준비했고, 그 버퍼의 시작위치를 전달.
        //recv()의 return(retval) 을 통해서 실제 수신된 byte크기를 확인 할 수 있다.
        int retval = recv(sock, buf, sizeof(buf), 0);

        buf[retval] = '\0'; //상대방이 넘길떄 strlen만큼만 넘겼다고 가정하면 strlen은 널값을 빼고 주기때문에 마지막에 널값을 넣어준다.
        printf(">> [수신데이터] : %s", buf);

        if (retval == -1 || retval == 0)
        {
            printf("소켓오류 or 상대방이 종류함\n");
            closesocket(sock);
            break;
        }

        //수신된 정보를 그대로 송신
        //buf의 주소로부터 retval의 byte만큼 전송
        int retval1 = send(sock, buf, retval, 0);
        printf("    [송신]%dbyte\n", retval);
    }
    closesocket(sock);
}

//연결된 통신 소켓을 이용해서 주소를 획득
//getpeername(상대방), getsockname(자신)
void  CMyNet::GetAddress(SOCKET sock, char* ip, int* port)
{
    SOCKADDR_IN  addr;
    int addrlength = sizeof(addr);
    getpeername(sock, (SOCKADDR*)&addr, &addrlength);

    //inet_ntoa : 정수주소 -> 문자열
    //#include <ws2tcpip.h> //inet_ntop
    inet_ntop(AF_INET, &(addr.sin_addr.s_addr), ip, INET_ADDRSTRLEN);
    *port = ntohs(addr.sin_port);

}

