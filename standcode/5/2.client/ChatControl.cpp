//chatcontrol.cpp

#include "pch.h"
#include "ChatControl.h"
#include <stdio.h>
#include "CChatDlg.h"					//<===============
#include "packet.h"

ChatControl* ChatControl::instance = NULL;

ChatControl::ChatControl()
{
	client.CreateSocket("192.168.0.93", 8000);
}

void ChatControl::ParentForm(CChatDlg* pDlg)	//<==================
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
		pForm->ShortMessage(smsg);		
	}
	else if (*p == ACK_MEMOMESSAGE)
	{
		PACKETMEMO* smsg = (PACKETMEMO*)msg;
		pForm->MemoMessage(smsg);
	}
}

void ChatControl::ShortMessage(const char* name, const char* msg)
{
	//���� ����(1. ��Ŷ ����, 2. ����)
	PACKETSHORTMESSAGE pack = PACKETSHORTMESSAGE::CreatePacket(name, msg);
	client.SendData((const char*)&pack, sizeof(pack));
}

void ChatControl::MemoMessage(const char* name, const char* msg)
{
	//���� ����(1. ��Ŷ ����, 2. ����)
	PACKETMEMO pack = PACKETMEMO::CreatePacket(name, msg, false);
	client.SendData((const char*)&pack, sizeof(pack));
}