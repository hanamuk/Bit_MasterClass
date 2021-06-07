//cmynet.cpp

#include <stdio.h>
#include "CMyNet.h"
#include <ws2tcpip.h> //inet_pton()
#include"Control.h"

//구조체를 정의해서 전역변수를 없애고 싶으면.. (구조체 맴버 : CMyNet*, SOCKET)
//CreateThread할 때 구조체 주소를 전달!
CMyNet* g_mynet = NULL;

CMyNet::CMyNet() : listen_socket(0)
{
    //1. 라이브러리 초기화(Winsock 2.2버전)
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        printf("윈도우 소켓 초기화 실패 \n");
        exit(-1);
    }
    g_mynet = this;
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
    addr.sin_addr.s_addr = htonl(INADDR_ANY); //long형을 network byte order로.. INADDR_ANY:현재 pc 기본주소.
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
        GetAddress(clientsocket, ip, &port);    //상대주소 가져오기.
        printf("[클라이언트 접속] %s:%d\n", ip, port);
        
        //vector에 저장 , 0번쨰 인덱스부터 차곡차곡 저장. 배열의 크기가 자동적으로 증가
        clients.push_back(clientsocket);

        //통신쓰레드 생성(접속한 소켓 전달)
        CloseHandle(CreateThread(0,0,WorkThread,(LPVOID)clientsocket,0,0));
       
    }
}

DWORD WINAPI CMyNet::WorkThread(LPVOID value)
{
    SOCKET sock = (SOCKET)value;

    while (1)
    {
        //수신
        char buf[48];
        int retval = g_mynet->Recvn(sock, buf, sizeof(buf), 0);     //Recvn은 3번쨰 인자 만큼 받아야 리턴됨?

        if (retval == -1 || retval == 0)
        {
            printf("소켓오류 or 상대방이 종류함\n");
            //closesocket(sock);
            break;
        }

      
        Control::getInstance()->RecvData(buf,retval);

        //개인에게 전달
        retval = send(sock, buf, retval, 0);
        printf("[1대 1 송신]%dbyte\n", retval);


        //전체 전송(1대 다 통신)
        //for (int i = 0; i < (int)g_mynet->clients.size(); i++)
        //{
        //    SOCKET s = g_mynet->clients[i]; //연산자 재정의 []
        //    int retval1 = send(s, buf, retval, 0);
        //}
        //printf("[1대 다 송신]%dbyte\n", retval);
       
    }
    
    //vector삭제.
    for (int i = 0; i < (int)g_mynet->clients.size(); i++)
    {
        SOCKET s = g_mynet->clients[i]; //연산자 재정의 []
        if (s == sock)
        {
            //erase는 삭제할 주소(배열의 주소(위치))를 요구한다.
            //g_mynet->clients.begin() 는 배열의 시작주소 반환.
            g_mynet->clients.erase(g_mynet->clients.begin() + i);
            closesocket(sock);
            return 0;

        }
    }
 


    return 0;
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

