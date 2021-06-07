
#include "pch.h"
#include "CMyClient.h"
#include<stdio.h>
#include <winsock2.h>				//선언부
#include <ws2tcpip.h>	
#pragma comment(lib, "ws2_32.lib")  //dll import 정보
#include"Control.h"


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
	CloseHandle(CreateThread(0, 0, RecvThread, (LPVOID)this, 0, 0));

	printf("\t연결성공");


}

DWORD __stdcall CMyClient::RecvThread(LPVOID value)
{
	CMyClient* pclient = (CMyClient*)value;
	SOCKET sock = (SOCKET)pclient->sock;
	while (true)
	{
		//수신
		char buf[288];		//꼭 바꾸자.
		int retval = pclient->Recvn(sock, buf, sizeof(buf), 0);
		if (retval == -1 || retval == 0)
		{
			printf("소켓 오류 or 상대방이 종료함\n");
			closesocket(sock);
			return 0;
		}

		Control::getInstance()->RecvData(buf, retval);

		//printf(">> [수신데이터] %s\n", buf);
	}

	return 0;
}

void CMyClient::SendData(const char* msg, int lenth)
{

	int retval = send(sock, msg, lenth, 0);
	printf("    [송신]%dbyte\n", retval);


}

int CMyClient::Recvn(SOCKET s, char* buf, int len, int flags)
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


