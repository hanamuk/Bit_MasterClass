
#include "pch.h"
#include "Control.h"
#include<stdio.h>
#include"packet.h"
#include"CMyClient.h"
#include"FriendDemoDlg.h"

Control* Control::instance = NULL; //싱글톤이 메모리가 잡히려면 초기화를 해줘야한다.

Control::Control()
{
	client.CreateSocket("192.168.0.93", 9000);
}

void Control::AddPerson(const char* Name, int Age, bool Gender)
{

	//서버로 전송(1. 패킷생성, 2전송)
	PACKETPERSON pack = pack_AddPerson(Name, Age, Gender);
	client.SendData((const char*)&pack, sizeof(pack));
}

void Control::GetListAll()
{

	//서버로 전송(1. 패킷생성, 2전송)
	PACKETPERSON pack = pack_ListAll();
	client.SendData((const char*)&pack, sizeof(pack));
}



void Control::RecvData(const char* msg, int size)
{
	
	//  printf(">> [수신데이터] %d\n", size);
	int* p = (int*)msg;
	if (*p == ACK_PERSON_S)
	{
		PACKETPERSON* pack = (PACKETPERSON*)msg;
		AfxMessageBox(_T("추가 성공"));
		Control::my->AddList(pack->per->name, pack->per->age, pack->per->gender);
		//printf(">> 추가 성공\n");
	}
	if (*p == ACK_LISTALL)
	{
		PACKLISTALL* pack = (PACKLISTALL*)msg;
		//AfxMessageBox(_T(pack->per->name));
		Control::my->ListAll(pack);
		
		//리스트에 추가
		//m_ctrlLIst.DeleteAllItems();//화면초기화
	}
}


void Control::SetMy(CFriendDemoDlg* my)
{
	Control::my = my;
}