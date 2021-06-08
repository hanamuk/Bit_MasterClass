
#pragma once
#include "CMyClient.h"
//#include "FriendDemoDlg.h" ,전방참조로인한 주석처리.

class CFriendDemoDlg;	//클래스 선언!(전방참조), CFriendDemoDlg를 사용하기위해서... /이걸사용하면 #include "FriendDemoDlg.h"를 cpp에서 해줘야한다.
class CChatDlg;

class ChatControl
{
	//싱글톤 패턴 적용 ---------------------------------------------
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

	//Form에서 control을 호출하는 메서드.
public:
	void ShortMessage(const char* name, const char* msg);
	void MemoMessage(const char* name, const char* msg);
};

