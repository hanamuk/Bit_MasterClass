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
	void CreateSocket(const char* ip, int port);
	void SendData(const char* ip, int port);
	int Recvn(SOCKET s, char* buf, int len, int flags);

private:
	static DWORD __stdcall RecvThread(LPVOID value);
};

