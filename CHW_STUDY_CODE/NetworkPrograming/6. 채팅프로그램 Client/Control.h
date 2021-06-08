//control.h

#pragma once
#include "CMyClient.h"
//#include "FriendDemoDlg.h" ,전방참조로인한 주석처리.

class CFriendDemoDlg;	//클래스 선언!(전방참조), CFriendDemoDlg를 사용하기위해서... /이걸사용하면 #include "FriendDemoDlg.h"를 cpp에서 해줘야한다.
class CMy0608채팅프로그램ClientDlg;

class Control
{
	//싱글톤 패턴 적용 ---------------------------------------------
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
	CMy0608채팅프로그램ClientDlg* pForm = NULL;

public:
	void RecvData(const char* msg, int size);
	void ParentForm(CMy0608채팅프로그램ClientDlg* pDlg);

	//Form에서 control을 호출하는 메서드.
public:
	void InsertMember(const char* id, const char* pw, const char* name);
	void LoginMember(const char* id, const char* pw);
	void LogOutMember(const char* id);
};

