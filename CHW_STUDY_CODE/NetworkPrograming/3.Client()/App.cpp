#include<stdio.h>
#include<conio.h>
#include "App.h"
#include"Control.h"
void App::Init()
{
	Logo();
}
void App::Run()
{
	Control* pcon = Control::getInstance();
	while (true)
	{
		switch (MenuPrint())
		{
		case '1':  pcon->InsertMember(); break;
		case '2':  pcon->Login();		 break;
		case '3':  pcon->Logout();		 break;
		case '4': return;
		}
		Sleep(2000);
	}
	
	
}
void App::Exit()
{
	Ending();
}

void App::Logo()
{
	printf("*****************************************************\n");
	printf(" 기업맞춤 교육- WinNet 과정 \n");
	printf(" 고정패킷을 사용한 Net 프로그램 \n");
	printf(" 2021- 06- 07 \n");
	printf(" 최 현 우\n");
	printf("*****************************************************\n");
}
char App::MenuPrint()
{
	printf("*****************************************************\n");
	printf(" [1] 회원가입\n");
	printf(" [2] 로그인\n");
	printf(" [3] 로그아웃\n");
	printf(" [4] 종료\n");
	printf("*****************************************************\n");

	return _getch();
}
void App::Ending()
{
	printf("*****************************************************\n");
	printf(" 프로그램을 종료합니다.\n");
	printf("*****************************************************\n");
}