
#include "pch.h"
#include "Control.h"
#include<stdio.h>
#include"packet.h"
#include"CMyClient.h"
#include"FriendDemoDlg.h"

Control* Control::instance = NULL; //�̱����� �޸𸮰� �������� �ʱ�ȭ�� ������Ѵ�.

Control::Control()
{
	client.CreateSocket("192.168.0.93", 9000);
}

void Control::AddPerson(const char* Name, int Age, bool Gender)
{

	//������ ����(1. ��Ŷ����, 2����)
	PACKETPERSON pack = pack_AddPerson(Name, Age, Gender);
	client.SendData((const char*)&pack, sizeof(pack));
}

void Control::GetListAll()
{

	//������ ����(1. ��Ŷ����, 2����)
	PACKETPERSON pack = pack_ListAll();
	client.SendData((const char*)&pack, sizeof(pack));
}



void Control::RecvData(const char* msg, int size)
{
	
	//  printf(">> [���ŵ�����] %d\n", size);
	int* p = (int*)msg;
	if (*p == ACK_PERSON_S)
	{
		PACKETPERSON* pack = (PACKETPERSON*)msg;
		AfxMessageBox(_T("�߰� ����"));
		Control::my->AddList(pack->per->name, pack->per->age, pack->per->gender);
		//printf(">> �߰� ����\n");
	}
	if (*p == ACK_LISTALL)
	{
		PACKLISTALL* pack = (PACKLISTALL*)msg;
		//AfxMessageBox(_T(pack->per->name));
		Control::my->ListAll(pack);
		
		//����Ʈ�� �߰�
		//m_ctrlLIst.DeleteAllItems();//ȭ���ʱ�ȭ
	}
}


void Control::SetMy(CFriendDemoDlg* my)
{
	Control::my = my;
}