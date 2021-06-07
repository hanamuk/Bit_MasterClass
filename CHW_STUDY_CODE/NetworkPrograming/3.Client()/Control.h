
#pragma once
#include"CMyClient.h"
class Control 
{
//�̱��� ���� ����-------------------------------
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


public:
	void RecvData(const char* msg, int size);

public:
	void InsertMember();
	void Login();
	void Logout();

};

