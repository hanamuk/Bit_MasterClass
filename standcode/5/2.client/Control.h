//control.h

#pragma once
#include "CMyClient.h"


class CMy0608ClientDlg;	//Ŭ���� ����!(��������)		//<===========

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
	CMy0608ClientDlg* pForm = NULL;				//<====================

public:
	void RecvData(const char* msg, int size);
	void ParentForm(CMy0608ClientDlg* pDlg);	//<====================

	//Form-> Controlȣ���ϴ� �޼���
public:
	void InsertMember(const char* id, const char* pw, const char* name);
	void LoginMember(const char* id, const char* pw);
	void LogOutMember(const char* id);
};

