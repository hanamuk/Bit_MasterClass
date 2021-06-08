//control.cpp
#include "pch.h"
#include <stdio.h>
#include "FriendDemoDlg.h"

#include "Control.h"
#include "packet.h"


Control* Control::instance = NULL;

Control::Control()
{
	client.CreateSocket("192.168.0.93", 9000);
}

void Control::ParentForm(CFriendDemoDlg* pDlg)
{
	pForm = pDlg;
}

void Control::RecvData(const char* msg, int size)
{
	printf(">> [���ŵ�����] %dbyte\n", size);
	int* p = (int*)msg;
	if (*p == ACK_PERSON_S)
	{
		MessageBox(0, "�˸�", ">> ȸ������ ����", MB_OK);
	}
	else if (*p == ACK_PERSON_F)
	{
		MessageBox(0, "�˸�", ">> ȸ������ ����", MB_OK);
	}
	else if (*p == ACK_LISTALL)
	{
		printf(">> ȸ�� ����Ʈ ó�� ����\n");
		PACKLISTALL* plist = (PACKLISTALL*)msg;
		pForm->PersonList(plist);
	}
}

void Control::InsertMember(const char* name, int age, char gender)
{
	//���� ����(1. ��Ŷ ����, 2. ����)
	PACKETPERSON pack = pack_NewPerson(name, age, gender);
	client.SendData((const char*)&pack, sizeof(pack));
}

void Control::MemberList()
{	
	//���� ����
	PACKLISTALL pack = pack_PersonList();
	client.SendData((const char*)&pack, sizeof(pack));
}