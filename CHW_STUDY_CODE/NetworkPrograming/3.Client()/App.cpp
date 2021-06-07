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
	printf(" ������� ����- WinNet ���� \n");
	printf(" ������Ŷ�� ����� Net ���α׷� \n");
	printf(" 2021- 06- 07 \n");
	printf(" �� �� ��\n");
	printf("*****************************************************\n");
}
char App::MenuPrint()
{
	printf("*****************************************************\n");
	printf(" [1] ȸ������\n");
	printf(" [2] �α���\n");
	printf(" [3] �α׾ƿ�\n");
	printf(" [4] ����\n");
	printf("*****************************************************\n");

	return _getch();
}
void App::Ending()
{
	printf("*****************************************************\n");
	printf(" ���α׷��� �����մϴ�.\n");
	printf("*****************************************************\n");
}