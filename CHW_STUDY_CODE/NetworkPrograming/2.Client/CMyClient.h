#pragma once
#include <winsock2.h>				//�����
#pragma comment(lib, "ws2_32.lib")  //dll import ����


class CMyClient
{
	//������ & �Ҹ���
private:
	SOCKET sock;

public:
	CMyClient();
	~CMyClient();

	// �޼���
public:
	void CreateSocket(const char* ip ,int port);
	void SendData(const char* ip, int port);

private : 
	static DWORD WINAPI RecvThread(LPVOID value);
};

