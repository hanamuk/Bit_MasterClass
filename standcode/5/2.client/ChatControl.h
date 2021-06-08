//chatcontrol.h

#pragma once

#include "CMyClient.h"

class CChatDlg;	//Ŭ���� ����!(��������)		//<===========

class ChatControl
{
	//�̱��� ���� ���� ---------------------------------------------
private:
	ChatControl();
	static ChatControl* instance;
public:
	static ChatControl* getInsatnce()
	{
		if (instance == NULL)
		{
			instance = new ChatControl();
		}
		return instance;
	}
	//------------------------------------------------------------
	CMyClient client;
	CChatDlg* pForm = NULL;				//<====================

public:
	void RecvData(const char* msg, int size);
	void ParentForm(CChatDlg* pDlg);	//<====================

	//Form-> Controlȣ���ϴ� �޼���
public:
	void ShortMessage(const char* name, const char* msg);
	void MemoMessage(const char* name, const char* msg);	
};

