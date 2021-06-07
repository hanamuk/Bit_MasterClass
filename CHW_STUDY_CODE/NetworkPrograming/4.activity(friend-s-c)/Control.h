
#pragma once
#include"CMyClient.h"

class CFriendDemoDlg;

class Control
{
	//½Ì±ÛÅæ ÆÐÅÏ Àû¿ë-------------------------------
private:
	Control();
	static Control* instance;
public:
	static Control* getInstance() {
		if (instance == NULL)
		{
			instance = new Control();
		}
		return instance;
	}
	//-----------------------------------------------

private:
	CMyClient client;
	CFriendDemoDlg* my =NULL;
	

public:
	void RecvData(const char* msg, int size);
	
public:
	void AddPerson(const char* Name, int Age, bool Gender);
	void GetListAll();
	void SetMy(CFriendDemoDlg* my);
};

