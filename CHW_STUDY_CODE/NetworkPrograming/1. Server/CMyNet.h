#pragma once
#include <winsock2.h>				//�����
#pragma comment(lib, "ws2_32.lib")  //dll import ����


class CMyNet
{
	//������ & �Ҹ���
private: 
	SOCKET listen_socket;

public:
	CMyNet();
	~CMyNet();

// �޼���
public :
	void CreateSocket(int port);
	void RecvMessage(SOCKET sock);
private :
	void Run();
	void GetAddress(SOCKET sock, char* ip, int* port);
	
};

