#include<stdio.h>


int Add(int , int );
int Sub(int , int );


void self_service() //����Լ�.
{
	
	printf("self_service\n");
	//self_service();

}

void count()
{
	static int ct = 0;
	ct++;
	printf("�Ҹ�Ƚ�� : %d\n", ct);

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
		printf("1 ����\n");
		return 1;
	}
	else
	{
		printf("%d * �Լ�ȣ��%d\n", n, n - 1);
		return n * facto2(n - 1);
	}

}
void swap(int a, int b);
void swap2(int* a, int* b);

//void swap3(int& a, int& b);
int main(void)
{

	//������
	enum season {SPRING, SUMMER, FALL, WINTER};
	enum week { SUN, MON, TUE, WED, THU,FRI, SAT  };

	int mybirth = SPRING;
	int today = MON;
	printf("�������� %d , %d\n\n", mybirth, today);


	int aaa = 10;
	int bbb = 20;
	printf("ȣ���� aaa : %d , bbb : %d\n", aaa, bbb);
	swap(aaa, bbb);
	printf("ȣ���� aaa : %d , bbb : %d\n", aaa, bbb);

	printf("swap2ȣ���� aaa : %d , bbb : %d\n", aaa, bbb);
	swap2(&aaa, &bbb);
	printf("swap2ȣ���� aaa : %d , bbb : %d\n", aaa, bbb);




	int (*p1)(int, int) = NULL;	//�Լ� ������. (����� �Լ��� ����, �Ű������� Ÿ���� �� �Ȱ��ƾ� �Լ������͸� ������ �� �ִ�.) 
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

	printf("\t swap�� aaa : %d , bbb : %d\n", a,b);

	int temp;
	temp = a;
	a = b;
	b = temp;

	printf("\t swap�� aaa : %d , bbb : %d\n",a,b);


}

void swap2(int* a, int* b)//call by adress
{

	printf("\t swap�� aaa : %d , bbb : %d\n", *a, *b);

	int temp;
	temp = *a;
	*a = *b;
	*b = temp;

	printf("\t swap�� aaa : %d , bbb : %d\n", *a, *b);


}

/*
//���� swap2 ������ int* a, int* b�� stack�� �޸𸮰� �����µ� �Ʒ��� swap3���� ó�� call by reference�� ����ϸ� �޸𸮸� �����ʰ� ��밡���ϴ�.
void swap3(int& a, int& b)//call by reference �ѱ拚 �ּҰ��ƴ� �г����� �Ѱ��ִ°�. ������ call by value�� ����ϴµ� ȿ���� call by adress�� ����.
{

	printf("\t swap�� aaa : %d , bbb : %d\n", a, b);

	int temp;
	temp = a;
	a = b;
	b = temp;

	printf("\t swap�� aaa : %d , bbb : %d\n", a, b);

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