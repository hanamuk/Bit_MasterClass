#include<stdio.h>
#define MYADD(a, b) (a+b) //��ũ�� �Լ�
#define MYMEL(a, b) ((a)*(b))
// #define MYMEL(a, b) (a*b)
#define MYMAKESTREAM(a) #a   // # : ���ڿ��� �������  (# -> ���ڿ��� ������ִ� ��ó����
#define MYPASTER(a,b) a##b   // ## : �ѵ���� �������

#define AAA
#ifdef AAA
#define MYMESSAGE "I am a boy"
#else
#define MYMESSAGE "You are a boy"
#endif

int myadd(int a, int b) // �Լ�
{
	return a + b;
}

int mymel(int a, int b)
{
	return a * b;
}

int main()
{
	printf("1. %s\n", __FILE__);
	printf("2. %s\n", __DATE__);
	printf("3. %s\n", __TIME__);
	printf("4. %d\n", __LINE__);

	return 0;

	puts(MYMESSAGE);

	int nData = 10;

	printf("%d\n", MYPASTER(11, 22));
	printf("%d\n", MYPASTER(nDa, ta));

	printf("%d\n", nData);
	printf("%s\n", MYMAKESTREAM(nData));
	printf("%s\n", MYMAKESTREAM(11));
	printf("%s\n", MYMAKESTREAM(3.14));

	return 0;

	printf("��ũ�� �Լ� : %d\n", MYADD(3, 5));
	printf("��¥ �Լ� : %d\n", myadd(3, 5));

	printf("��ũ�� �Լ� : %f\n", MYADD(3, 5.8)); //��ũ�� �Լ��� Ÿ���� �����ص� ����ȴ�
	printf("��¥ �Լ� : %f\n", myadd(3, 5.8));

	printf("��ũ�� �Լ� : %d\n", MYMEL(3, 5));
	printf("��¥ �Լ� : %d\n", mymel(3, 5));

	printf("��ũ�� �Լ� : %d\n", MYMEL(3 + 2, 5)); // #define MYMEL(a, b) (a*b) --> 3+2*5
	printf("��¥ �Լ� : %d\n", mymel(3 + 2, 5));


	return 0;
}