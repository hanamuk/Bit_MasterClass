#include<stdio.h>


int Add(int , int );
int Sub(int , int );


void self_service() //재귀함수.
{
	
	printf("self_service\n");
	//self_service();

}

void count()
{
	static int ct = 0;
	ct++;
	printf("불린횟수 : %d\n", ct);

}

int facto(int x)
{
	int sum = 1;
	for (int i = 1; i <=x; i++)
	{
		sum *= i;
	}

	printf("factorial : %d!  = %d\n", x,sum);
	return sum;
}

int facto2(int n)
{
	if (n <= 1)
	{
		printf("1 리턴\n");
		return 1;
	}
	else
	{
		printf("%d * 함수호출%d\n", n, n - 1);
		return n * facto2(n - 1);
	}

}
void swap(int a, int b);
void swap2(int* a, int* b);

//void swap3(int& a, int& b);
int main(void)
{

	//열거형
	enum season {SPRING, SUMMER, FALL, WINTER};
	enum week { SUN, MON, TUE, WED, THU,FRI, SAT  };

	int mybirth = SPRING;
	int today = MON;
	printf("내생일은 %d , %d\n\n", mybirth, today);


	int aaa = 10;
	int bbb = 20;
	printf("호출전 aaa : %d , bbb : %d\n", aaa, bbb);
	swap(aaa, bbb);
	printf("호출후 aaa : %d , bbb : %d\n", aaa, bbb);

	printf("swap2호출전 aaa : %d , bbb : %d\n", aaa, bbb);
	swap2(&aaa, &bbb);
	printf("swap2호출후 aaa : %d , bbb : %d\n", aaa, bbb);




	int (*p1)(int, int) = NULL;	//함수 포인터. (사용할 함수의 리턴, 매개변수의 타입이 다 똑같아야 함수포인터를 선언할 수 있다.) 
	p1 = Add;
	int ret1 = p1(10, 60);
	printf("%d\n", ret1);

	p1 = Sub;
	int ret2 = p1(10, 60);
	printf("%d\n", ret2);

	p1 = self_service;
	//p1();//error

	void (*p2)(void) = NULL;
	p2 = self_service;
	p2();	
	

	return 0;

	/*
	int y = facto2(5);
	printf("factorial :%d\n", y);
	self_service();

	count();
	count();
	count();
	count();
	count();

	int a = 10;
	int b = 20;
	int c = Add(a,b);

	printf("%d\n", c);

	c = Sub(b, a);
	printf("%d\n", c);

	return 0;
	*/
}

void swap(int a, int b)//call by value
{

	printf("\t swap전 aaa : %d , bbb : %d\n", a,b);

	int temp;
	temp = a;
	a = b;
	b = temp;

	printf("\t swap후 aaa : %d , bbb : %d\n",a,b);


}

void swap2(int* a, int* b)//call by adress
{

	printf("\t swap전 aaa : %d , bbb : %d\n", *a, *b);

	int temp;
	temp = *a;
	*a = *b;
	*b = temp;

	printf("\t swap후 aaa : %d , bbb : %d\n", *a, *b);


}

/*
//위의 swap2 에서는 int* a, int* b의 stack에 메모리가 잡히는데 아래의 swap3에서 처럼 call by reference을 사용하면 메모리를 잡지않고 사용가능하다.
void swap3(int& a, int& b)//call by reference 넘길떄 주소가아닌 닉네임을 넘겨주는것. 문법은 call by value를 사용하는데 효과는 call by adress와 같다.
{

	printf("\t swap전 aaa : %d , bbb : %d\n", a, b);

	int temp;
	temp = a;
	a = b;
	b = temp;

	printf("\t swap후 aaa : %d , bbb : %d\n", a, b);

}
*/
int Add(int x, int y)
{

	int sum = x + y;
	return sum;
}

int Sub(int x, int y)
{

	int sum = x - y;
	return sum;
}