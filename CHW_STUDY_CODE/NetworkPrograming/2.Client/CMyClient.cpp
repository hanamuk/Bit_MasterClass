#include "CMyClient.h"
#include<stdio.h>
#include <winsock2.h>				//선언부
#include <ws2tcpip.h>	
#pragma comment(lib, "ws2_32.lib")  //dll import 정보

CMyClient::CMyClient() : sock(0)
{
	//1. 라이브러리 초기화(Winsock 2.2버전)
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("윈도우 소켓 초기화 실패\n");
		exit(-1); //종료 코드 값
	}
}

CMyClient::~CMyClient()
{
	//2. 라이브러리 해제
	WSACleanup();
}
void CMyClient::CreateSocket(const char* ip, int port)
{
	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (sock == INVALID_SOCKET)
		throw "소켓 생성오류";

	SOCKADDR_IN addr;						
	memset(&addr, 0, sizeof(addr));			//API에서는 ZeroMemory(&addr, 0, sizeof(addr));	addr를 addr크기의 만큼 모두 0으로 만든다.
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	unsigned int numberaddr;
	inet_pton(AF_INET, ip, &numberaddr);
	addr.sin_addr.s_addr = numberaddr;

	int retval = connect(sock, (SOCKADDR*)&addr, sizeof(addr));
	if (retval == SOCKET_ERROR)
		throw "서버연결실패";

	//수신 Tread 생성 하는 위치
	CloseHandle(CreateThread(0, 0, RecvThread, (LPVOID)sock, 0, 0));

	printf("\t연결성공");


}

DWORD WINAPI CMyClient::RecvThread(LPVOID value)
{
	SOCKET sock = (SOCKET)value;
	while (true)
	{

		char buf[256];
		int retval = recv(sock, buf, sizeof(buf), 0);
		if (retval == -1 || retval == 0)
		{
			printf("소켓오류 or 상대방이 종류함\n");
			closesocket(sock);
			return 0;
		}

		buf[retval] = '\0';
		printf(">> [수신데이터] : %s\n", buf);

	}
	return 0;
}

void CMyClient::SendData(const char* msg, int lenth)
{
	
	int retval = send(sock, msg, lenth, 0);
	printf("    [송신]%dbyte\n", retval);


}



