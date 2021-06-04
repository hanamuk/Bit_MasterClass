#pragma once
#include <winsock2.h>				//선언부
#pragma comment(lib, "ws2_32.lib")  //dll import 정보


class CMyNet
{
	//생성자 & 소멸자
private: 
	SOCKET listen_socket;

public:
	CMyNet();
	~CMyNet();

// 메서드
public :
	void CreateSocket(int port);
	void RecvMessage(SOCKET sock);
private :
	void Run();
	void GetAddress(SOCKET sock, char* ip, int* port);
	
};

