//control.h

#pragma once
#include "CMyClient.h"
//#include "FriendDemoDlg.h" ,�������������� �ּ�ó��.

class CFriendDemoDlg;	//Ŭ���� ����!(��������), CFriendDemoDlg�� ����ϱ����ؼ�... /�̰ɻ���ϸ� #include "FriendDemoDlg.h"�� cpp���� ������Ѵ�.
class CMy0608ä�����α׷�ClientDlg;

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
	CMy0608ä�����α׷�ClientDlg* pForm = NULL;

public:
	void RecvData(const char* msg, int size);
	void ParentForm(CMy0608ä�����α׷�ClientDlg* pDlg);

	//Form���� control�� ȣ���ϴ� �޼���.
public:
	void InsertMember(const char* id, const char* pw, const char* name);
	void LoginMember(const char* id, const char* pw);
	void LogOutMember(const char* id);
};

