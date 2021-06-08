//Control.cpp

#include <stdio.h>
#include "packet.h"
#include "Control.h"

Control* Control::instance = NULL;

void Control::Run()
{
	try
	{
		FileLoad();			//<========================== FileLoad
		PrintMemberData();
		net.CreateSocket(9000);
	}
	catch (const char* msg)
	{
		printf("���� : %s\n", msg);
	}
}

void Control::RecvData(int sock, const char* msg, int size)
{
	printf(">> [���ŵ�����] %dbyte\n", size);
	int* p = (int*)msg;
	if (*p == PACK_NEWMEMBER)
	{
		printf("ȸ������\n");
		PACKETNEWMEMBER* member = (PACKETNEWMEMBER*)msg;
		if (NewMember(member) == true)
		{
			member->flag = ACK_NEWMEMBER_S;
		}
		else
		{
			member->flag = ACK_NEWMEMBER_F;
		}
		net.SendData(sock, msg, size);	//<=======����!!!!!!!!!!
	}
	else if (*p == PACK_LOGIN)
	{
		printf("�α���\n");
		PACKLOGIN* login = (PACKLOGIN*)msg;
		if (LoginMember(login) == true)
		{
			login->flag = ACK_LOGIN_S;	//�̸� �߰�!
		}
		else
		{
			login->flag = ACK_LOGIN_F;
		}
		net.SendData(sock, msg, size);	//<=======����!!!!!!!!!!
	}
	else if (*p == PACK_LOGOUT)
	{
		printf("�α׾ƿ�\n");
		PACKETLOGOUT* logout = (PACKETLOGOUT*)msg;
		if (LogOutMember(logout) == true)
		{
			logout->flag = ACK_LOGOUT_S;
		}
		else
		{
			logout->flag = ACK_LOGOUT_F;
		}
	}
}

bool Control::NewMember(PACKETNEWMEMBER* pMem)
{
	Member member(pMem->name,pMem->id, pMem->pw);
	personlist.push_back(member);
	PrintMemberData();
	FildSave();						//<================= FileSave
	return true;
}

bool Control::LoginMember(PACKLOGIN* plogin)
{
	for (int i = 0; i < (int)personlist.size(); i++)
	{
		Member mem = personlist[i];
		if (strcmp(mem.getID(), plogin->id) == 0 &&
			strcmp(mem.getPW(), plogin->pw) == 0)
		{
			//plogin�� ������ ���� ä���
			strcpy_s(plogin->name, sizeof(plogin->name), mem.getName());

			//vector�� �α��� ���°� �����ϱ�
			personlist[i].setIsLogin(true);
			PrintMemberData();		//<====================
			return true;
		}
	}
	return false;
}

bool Control::LogOutMember(PACKETLOGOUT *plogout)
{
	for (int i = 0; i < (int)personlist.size(); i++)
	{
		Member mem = personlist[i];
		if (strcmp(mem.getID(), plogout->id)==0  && mem.getIsLogin() == true)
		{		
			//vector�� �α��� ���°� �����ϱ�
			personlist[i].setIsLogin(false);
			PrintMemberData();		//<====================
			return true;
		}
	}
	return false;
}

void Control::PrintMemberData()
{
	system("cls");

	printf("ȸ���� : %d\n", personlist.size());
	for (int i = 0; i < (int)personlist.size(); i++)
	{
		Member person = personlist[i];
		printf("[%d] %s\t%s\t%s\t%c\n",
			i, person.getName(), person.getID(), person.getPW(),
			(person.getIsLogin()?'O':'X'));
	}
}


void Control::FildSave()
{
	FILE* fp;
	fopen_s(&fp, "members.ccm", "w");
	if (fp == NULL)
		return;

	int size = personlist.size();
	fwrite(&size, sizeof(int), 1, fp);
	for (int i = 0; i < (int)personlist.size(); i++)
	{
		Member mem = personlist[i];
		mem.setIsLogin(false);
		fwrite(&mem, sizeof(mem), 1, fp);
	}

	fclose(fp);
}

void Control::FileLoad()
{
	FILE* fp;
	fopen_s(&fp, "members.ccm", "r");
	if (fp == NULL)
		return;

	int size;
	fread(&size, sizeof(int), 1, fp);
	for (int i = 0; i < size; i++)
	{
		Member mem("","","");
		fread(&mem, sizeof(mem), 1, fp);	
		personlist.push_back(mem);
	}

	fclose(fp);
}