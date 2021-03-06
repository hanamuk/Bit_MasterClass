#include "Control.h"
#include<stdio.h>
#include"packet.h"

Control* Control::instance = NULL;

void Control::RecvData(const char* msg , int size)
{
	printf(">> [수신데이터] : %dbyte", size);

	int* p = (int*)msg;

	if (*p == PACK_NEWMEMBER)
	{
		printf("회원가입\n");
		if (NewMember((NEWMEMBER*)msg))// 회원가입 성공여부 
		{
			NEWMEMBER* pmem = (NEWMEMBER*)msg;
			pmem->flag = ACK_NEWMEMBER_S;
		}
		else
		{
			NEWMEMBER* pmem = (NEWMEMBER*)msg;
			pmem->flag = ACK_NEWMEMBER_F;

		}
	}
	else if (*p == PACK_LOGIN)
	{
		printf("로그인\n");
		if (Login((LOGIN*)msg) == true)
		{
			LOGIN* plogin = (LOGIN*)msg;
			plogin->flag = ACK_LOGIN_S;
		}
		else
		{
			LOGIN* plogin = (LOGIN*)msg;
			plogin->flag = ACK_LOGIN_F;
		}
	}

	else if (*p == PACK_LOGOUT)
	{
		printf("로그아웃\n");
		if (Logout((LOGIN*)msg) == true)
		{
			LOGIN* plogout = (LOGIN*)msg;
			plogout->flag = ACK_LOGOUT_S;
		}
		else
		{
			LOGIN* plogout = (LOGIN*)msg;
			plogout->flag = ACK_LOGOUT_F;
		}
	}
}
bool Control::NewMember(NEWMEMBER* pMem)
{
	NEWMEMBER mem;
	mem.flag = 0;	//login 여부의 값으로 활용
	strcpy_s(mem.name, sizeof(mem.name), pMem->name);
	strcpy_s(mem.id, sizeof(mem.id), pMem->id);
	strcpy_s(mem.pw, sizeof(mem.pw), pMem->pw);
	mem.age = pMem->age;

	memberlist.push_back(mem);
	return true;
}

bool Control::Login(LOGIN* pLogin)
{
	//로그인에 대한 판단.
	for (int i = 0; i < memberlist.size(); i++)
	{
		NEWMEMBER member = memberlist[i];
		if (strcmp(member.id, pLogin->id) == 0 && strcmp(member.pw, pLogin->pw) == 0)
		{
			//로그인성공, 내부 정보 수정.
			memberlist[i].flag = 1;
			return true;

		}
	}
	return false;
}
bool Control::Logout(LOGIN* pLogout)
{
	for (int i = 0; i < (int)memberlist.size(); i++)
	{
		NEWMEMBER member = memberlist[i];
		if (strcmp(member.id, pLogout->id) == 0 && member.flag == 1)
		{
			//내부 정보 수정!
			memberlist[i].flag = 0;
			PrintMemberData();
			return true;
		}
	}
	return false;
}

void Control::PrintMemberData()
{
	system("cls");

	printf("회원수 : %d\n", memberlist.size());
	for (int i = 0; i < (int)memberlist.size(); i++)
	{
		NEWMEMBER mem = memberlist[i];
		printf("[%d] %s\t%s\t%s\t%d\n",
			mem.flag, mem.name, mem.id, mem.pw, mem.age);
	}
}