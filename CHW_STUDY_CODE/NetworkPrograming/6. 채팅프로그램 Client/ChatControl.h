
#pragma once
#include "CMyClient.h"
//#include "FriendDemoDlg.h" ,�������������� �ּ�ó��.

class CFriendDemoDlg;	//Ŭ���� ����!(��������), CFriendDemoDlg�� ����ϱ����ؼ�... /�̰ɻ���ϸ� #include "FriendDemoDlg.h"�� cpp���� ������Ѵ�.
class CChatDlg;

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
	CChatDlg* pForm = NULL;

public:
	void RecvData(const char* msg, int size);
	void ParentForm(CChatDlg* pDlg);

	//Form���� control�� ȣ���ϴ� �޼���.
public:
	void ShortMessage(const char* name, const char* msg);
	void MemoMessage(const char* name, const char* msg);
};

