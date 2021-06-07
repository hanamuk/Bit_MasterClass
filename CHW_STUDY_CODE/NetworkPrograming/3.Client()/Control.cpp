#include "Control.h"
#include<stdio.h>
#include"packet.h"
#include"CMyClient.h"


Control* Control::instance = NULL; //싱글톤이 메모리가 잡히려면 초기화를 해줘야한다.

Control::Control()
{
	client.CreateSocket("192.168.0.93", 9000);
}

void Control::InsertMember()
{
	char name[20], id[10], pw[10];
	int age;
	printf("이름 : ");		gets_s(name, sizeof(name));
	printf("아이디 : ");		gets_s(id, sizeof(id));
	printf("패스워드 : ");	gets_s(pw, sizeof(pw));
	printf("나이 : ");		scanf_s("%d", &age);
	char dummy = getchar(); //버퍼를 비우려고 씀.

	//비쥬얼스튜디오는 구조체를 만들떄 4바이트씩 메모리를 만든다. 구조체 맴버의 순서를 잡냐에 따라서 구조체 크기가 달라진다. char를 먼저 넣으면 1칸이 채워지고 3바이트가 남는데 그다음 int형을 넣는다면 구조체 는 총 8바이트가 된다
	//이러한 문제를 해결하기 위해서 네트워크통신을 할때는 메모리를 1바이트씩 쌓기위해서 #pragma pack(1)을쓴다.
	//서버로 전송(1. 패킷생성, 2전송)
	NEWMEMBER pack = pack_NewMember(name, id, pw, age);
	client.SendData((const char*)&pack, sizeof(pack));
}

void Control::Login()
{
	
	char id[10], pw[10];
	printf("아이디 : ");		gets_s(id, sizeof(id));
	printf("패스워드 : ");	gets_s(pw, sizeof(pw));

	//서버로 전송(1. 패킷생성, 2전송)
	LOGIN pack = pack_Login(id, pw);
	client.SendData((const char*)&pack, sizeof(pack));
}


void Control::Logout()
{

	char id[10];
	printf("아이디 : ");	gets_s(id, sizeof(id));

	//서버로 전송(1. 패킷생성, 2전송)
	LOGOUT pack = pack_Logout(id);
	client.SendData((const char*)&pack, sizeof(pack));
}

void Control::RecvData(const char* msg, int size)
{
	printf(">> [수신데이터] %d\n", size);
	int* p = (int*)msg;
	if (*p == ACK_NEWMEMBER_S)
	{
		printf(">> 회원가입 성공\n");
	}
	else if (*p == ACK_NEWMEMBER_F)
	{
		printf(">> 회원가입 실패\n");
	}
	else if (*p == ACK_LOGIN_S)
	{
		printf(">> 로그인 성공\n");
	}
	else if (*p == ACK_LOGIN_F)
	{
		printf(">> 로그인 실패\n");
	}
	else if (*p == ACK_LOGOUT_S)
	{
		printf(">> 로그아웃 성공\n");
	}
	else if (*p == ACK_LOGOUT_F)
	{
		printf(">> 로그아웃 실패\n");
	}

}