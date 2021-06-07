#pragma once
//프로그램의 흐름 관리하는 클래스.
#include "Control.h"

class App
{

public : 
	void Init(); //logo
	void Run();	//print
	void Exit(); //endig 호출

private:
	void Logo();
	char MenuPrint();
	void Ending();
	

};

