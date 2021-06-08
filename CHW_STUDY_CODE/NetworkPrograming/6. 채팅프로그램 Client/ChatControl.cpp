//control.cpp
#include "pch.h"
#include <stdio.h>

#include "ChatControl.h"
#include "packet.h"
#include"CChatDlg.h"

ChatControl* ChatControl::instance = NULL;

ChatControl::ChatControl()
{
	client.CreateSocket("192.168.0.93", 8000);
}

void ChatControl::ParentForm(CChatDlg* pDlg)
{
	pForm = pDlg;
}

void ChatControl::RecvData(const char* msg, int size)
{
	printf(">> [���ŵ�����] %dbyte\n", size);
	int* p = (int*)msg;
	if (*p == ACK_SHORTMESSAGE)
	{
		PACKETSHORTMESSAGE* smsg = (PACKETSHORTMESSAGE*)msg;
		pForm->ShortMessage(smsg);	//�޴¾�
	}
	if (*p == ACK_MEMOMESSAGE)
	{
		PACKETMEMO* smsg = (PACKETMEMO*)msg;
		pForm->MemoMessage(smsg);	//�޴¾�
	}


}

void ChatControl::ShortMessage(const char* name, const char* msg)
{
	PACKETSHORTMESSAGE pack = PACKETSHORTMESSAGE::CreatePacket(name, msg);
	client.SendData((const char*)&pack, sizeof(pack));
}

void ChatControl::MemoMessage(const char* name, const char* msg)
{
	PACKETMEMO pack = PACKETMEMO::CreatePacket(name, msg,false);
	client.SendData((const char*)&pack, sizeof(pack));
}

