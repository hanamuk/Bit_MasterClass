
#include<stdio.h>
#include<vector>
using namespace std;
#include "packet.h"

//Control.h
/*
   디자인패턴(Gof) : 어떤 문제를 해결하기 위해 클래스를 어떻게 설계할 것인가?
				 모델에 관한 이야기.
   예) 싱글톤패턴
	  하나의 객체만 생성가능한 클래스 구조.
*/
#pragma once

class Control
{
	//싱글톤 패턴 적용-------------------------------
private:
	Control() { }
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
private :
	vector<NEWMEMBER> memberlist;

public:
	void RecvData(const char* msg, int size);

//기능함수
private:
	bool NewMember(NEWMEMBER* pMem);
	bool Login(LOGIN* pLogin);
	bool Logout(LOGIN* pLogout);

	void PrintMemberData();
	
};