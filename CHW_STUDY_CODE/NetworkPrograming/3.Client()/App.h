#pragma once
//���α׷��� �帧 �����ϴ� Ŭ����.
#include "Control.h"

class App
{

public : 
	void Init(); //logo
	void Run();	//print
	void Exit(); //endig ȣ��

private:
	void Logo();
	char MenuPrint();
	void Ending();
	

};

