//비쥬얼스튜디오는 구조체를 만들떄 4바이트씩 메모리를 만든다. 구조체 맴버의 순서를 잡냐에 따라서 구조체 크기가 달라진다.
// char를 먼저 넣으면 1칸이 채워지고 3바이트가 남는데 그다음 int형을 넣는다면 구조체 는 총 8바이트가 된다
//이러한 문제를 해결하기 위해서 네트워크통신을 할때는 메모리를 1바이트씩 쌓기위해서 #pragma pack(1)을쓴다.
#pragma pack(1) //제일먼저 넣자

#include"packet.h"
#include<stdio.h>
#include<string.h>
NEWMEMBER pack_NewMember(const char* name, const char* id, const char* pw, int age)
{
	NEWMEMBER packet = { 0 };
	packet.flag = PACK_NEWMEMBER;
	strcpy_s(packet.name, sizeof(packet.name), name);
	strcpy_s(packet.id, sizeof(packet.id), id);
	strcpy_s(packet.pw, sizeof(packet.pw), pw);
	packet.age = age;
	return packet;
}

LOGIN pack_Login(const char* id, const char* pw)
{
	LOGIN packet = { 0 };
	packet.flag = PACK_LOGIN;
	strcpy_s(packet.id, sizeof(packet.id), id);
	strcpy_s(packet.pw, sizeof(packet.pw), pw);
	return packet;
}

LOGOUT  pack_Logout(const char* id)
{
	LOGOUT packet = { 0 };
	packet.flag = PACK_LOGOUT;
	strcpy_s(packet.id, sizeof(packet.id), id);
	return packet;
}

