#include<stdio.h>
/* #은 전처리기라는 뜻 여기서 처리기는 컴파일러를 뜻한다. 즉 컴파일하기전에 무엇을 해야할떄 #을 사용한다..*/

#pragma onece
/* 해더파일에서 이미 포함되어있으면 한번만 포함시켜라는 명령어 */

#define MAX 40
#define MY_ARRAY

/*  #ifdef 는 아래를 예로치면 MY_ARRAY가 있다면 바로아래의 소스코드가 실행되고 만약  #define MY_ARRAY 처럼  MY_ARRAY가 없다면 else의 블록부분의 소스코드가 실행된다. 
	#ifdef 종류는 많이사용된다고한다..*/
#ifndef MY_ARRAY //////////////////////////////////////////// 잘보이게 하기위해 슬래시 주석으로 보이게한다.

int main(void)
{


	printf("Hello, World");

	return 0;
}

#else ////////////////////////////////////////////

/*프로그램을 OS가 메모리에 올릴때 OS는 Main함수를 호출해준다 컴파일러가 아니고 OS가 호출해주는것.*/
int stdio_main(void)
{


	printf("Hello, World\n\n");
	printf("Hello, World\n");

	int a = 255;
	printf("십진수 : %#d\n", a); // % 사이에 #을 쓰면 해당진수에 따른 기호를 넣어서 표시해준다..
	printf("팔진수 : %#o\n", a);
	printf("십육진수 : %#x\n", a);

	double b = 89.567;

	printf("%#f\n", b); 
	printf("%#F\n", b);
	printf("%#e\n", b);	//89를 표기할떄 8.9곱하기 10의 1승으로 표기,. 즉 십의 몇승으로 표기하는 것.
	printf("%#E\n", b);


	printf("a 의 주소 : %p\n", &a);
	printf("main 의 주소 : %p\n", &stdio_main);
	printf("printf 의 주소 : %p\n", &printf);


	printf("enter a char : ");
	char ch = getchar();

	printf("결과 : %d , %c \n", ch, ch);
	printf("대문자로 변환 : %d , %c \n", ch-32, ch-32);



	return 0;
}

#endif ////////////////////////////////////////////