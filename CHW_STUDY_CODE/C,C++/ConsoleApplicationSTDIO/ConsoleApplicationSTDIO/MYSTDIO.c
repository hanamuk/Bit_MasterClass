#include<stdio.h>
/* #�� ��ó������ �� ���⼭ ó����� �����Ϸ��� ���Ѵ�. �� �������ϱ����� ������ �ؾ��ҋ� #�� ����Ѵ�..*/

#pragma onece
/* �ش����Ͽ��� �̹� ���ԵǾ������� �ѹ��� ���Խ��Ѷ�� ��ɾ� */

#define MAX 40
#define MY_ARRAY

/*  #ifdef �� �Ʒ��� ����ġ�� MY_ARRAY�� �ִٸ� �ٷξƷ��� �ҽ��ڵ尡 ����ǰ� ����  #define MY_ARRAY ó��  MY_ARRAY�� ���ٸ� else�� ��Ϻκ��� �ҽ��ڵ尡 ����ȴ�. 
	#ifdef ������ ���̻��ȴٰ��Ѵ�..*/
#ifndef MY_ARRAY //////////////////////////////////////////// �ߺ��̰� �ϱ����� ������ �ּ����� ���̰��Ѵ�.

int main(void)
{


	printf("Hello, World");

	return 0;
}

#else ////////////////////////////////////////////

/*���α׷��� OS�� �޸𸮿� �ø��� OS�� Main�Լ��� ȣ�����ش� �����Ϸ��� �ƴϰ� OS�� ȣ�����ִ°�.*/
int stdio_main(void)
{


	printf("Hello, World\n\n");
	printf("Hello, World\n");

	int a = 255;
	printf("������ : %#d\n", a); // % ���̿� #�� ���� �ش������� ���� ��ȣ�� �־ ǥ�����ش�..
	printf("������ : %#o\n", a);
	printf("�������� : %#x\n", a);

	double b = 89.567;

	printf("%#f\n", b); 
	printf("%#F\n", b);
	printf("%#e\n", b);	//89�� ǥ���ҋ� 8.9���ϱ� 10�� 1������ ǥ��,. �� ���� ������� ǥ���ϴ� ��.
	printf("%#E\n", b);


	printf("a �� �ּ� : %p\n", &a);
	printf("main �� �ּ� : %p\n", &stdio_main);
	printf("printf �� �ּ� : %p\n", &printf);


	printf("enter a char : ");
	char ch = getchar();

	printf("��� : %d , %c \n", ch, ch);
	printf("�빮�ڷ� ��ȯ : %d , %c \n", ch-32, ch-32);



	return 0;
}

#endif ////////////////////////////////////////////