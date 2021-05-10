#include<stdio.h>
#define MYADD(a, b) (a+b) //매크로 함수
#define MYMEL(a, b) ((a)*(b))
// #define MYMEL(a, b) (a*b)
#define MYMAKESTREAM(a) #a   // # : 문자열로 만들어줌  (# -> 문자열로 만들어주는 전처리기
#define MYPASTER(a,b) a##b   // ## : 한덩어리로 만들어줌

#define AAA
#ifdef AAA
#define MYMESSAGE "I am a boy"
#else
#define MYMESSAGE "You are a boy"
#endif

int myadd(int a, int b) // 함수
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

	printf("매크로 함수 : %d\n", MYADD(3, 5));
	printf("진짜 함수 : %d\n", myadd(3, 5));

	printf("매크로 함수 : %f\n", MYADD(3, 5.8)); //매크로 함수는 타입을 안정해도 적용된다
	printf("진짜 함수 : %f\n", myadd(3, 5.8));

	printf("매크로 함수 : %d\n", MYMEL(3, 5));
	printf("진짜 함수 : %d\n", mymel(3, 5));

	printf("매크로 함수 : %d\n", MYMEL(3 + 2, 5)); // #define MYMEL(a, b) (a*b) --> 3+2*5
	printf("진짜 함수 : %d\n", mymel(3 + 2, 5));


	return 0;
}