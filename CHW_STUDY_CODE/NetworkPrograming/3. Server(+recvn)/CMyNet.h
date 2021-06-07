#pragma once
#include <winsock2.h>				//선언부
#pragma comment(lib, "ws2_32.lib")  //dll import 정보
#include <vector>
using namespace std;

class CMyNet
{
	
private: 
	SOCKET listen_socket;
	vector<SOCKET> clients;		//SOCKET를 저장하는 배열 크기는가변적으로 관리
	//생성자 & 소멸자
public:
	CMyNet();
	~CMyNet();

// 메서드
public :
	void CreateSocket(int port);

private :
	void Run();
	void GetAddress(SOCKET sock, char* ip, int* port);
	int Recvn(SOCKET s, char* buf, int len, int flags);

	static DWORD WINAPI WorkThread(LPVOID valud);	//디스포인터르 사용하지못함

};

