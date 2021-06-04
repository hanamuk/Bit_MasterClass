#pragma once
#include <winsock2.h>				//선언부
#pragma comment(lib, "ws2_32.lib")  //dll import 정보


class CMyClient
{
	//생성자 & 소멸자
private:
	SOCKET sock;

public:
	CMyClient();
	~CMyClient();

	// 메서드
public:
	void CreateSocket(const char* ip ,int port);
	void SendData(const char* ip, int port);

private : 
	static DWORD WINAPI RecvThread(LPVOID value);
};

