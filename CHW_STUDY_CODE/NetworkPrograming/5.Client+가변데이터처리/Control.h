//control.h

#pragma once
#include "CMyClient.h"
//#include "FriendDemoDlg.h" ,�������������� �ּ�ó��.

class CFriendDemoDlg;	//Ŭ���� ����!(��������), CFriendDemoDlg�� ����ϱ����ؼ�... /�̰ɻ���ϸ� #include "FriendDemoDlg.h"�� cpp���� ������Ѵ�.

class Control
{
	//�̱��� ���� ���� ---------------------------------------------
private:
	Control();
	static Control* instance;
public:
	static Control* getInsatnce()
	{
		if (instance == NULL)
		{
			instance = new Control();
		}
		return instance;
	}
	//------------------------------------------------------------
	CMyClient client; 
	CFriendDemoDlg* pForm = NULL;		//<============================

public:
	void RecvData(const char* msg, int size);
	void ParentForm(CFriendDemoDlg* pDlg);

public:
	void InsertMember(const char* msg, int age, char gender);
	void MemberList();
};

