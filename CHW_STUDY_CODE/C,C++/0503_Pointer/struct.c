#include<stdio.h>

typedef struct point
{
	int x;
	int y;

}MYPOINT;


typedef struct rect
{
	int x;
	int y;
	int w;
	int h;

}MYRECT;

//typedef�� ����ü���� ���°��� �ƴϴ�.


//typedef struct point MYPOINT;	�̰͵�����. 
//typedef ���ϸ� �Ʒ� �ڵ忡�� struct�� �������� , �����ݷ� �տ� �̸��� �ۼ��ϸ� ���̸����� ����ü�� �̸��� ����� �� ����



/*
//#pragma pack(push,1)
//#pragma pack(pop) ��ɾ�� �޸𸮸� 1����Ʈ������ ��ƶ� ��� ���̴�. 8����Ʈ�� �޸𸮸� ��Ƽ� �������� �޸𸮰� �ʹ� ���ٰų� �ҋ� �̷��� ��ɾ �ָ� 
					1����Ʈ ������ �޸𸮸� ��´�.
*/
#pragma pack(push,1)
struct USERDATA {

	char ch;
	int age;

};
struct MYDATA {
	char ch;
	int age;
	double hight;


};
#pragma pack(pop)

struct score {

	int kor;
	int math;
	int eng;

	int sum;
	double evg;

};

struct student {

	int no;
	char name[20];
	struct score s;

};
typedef struct student STUDENT;



struct worker {

	int no;
	char name[20];
	
	struct worker* pLink;

};
typedef struct worker WORKER;


//����� 4����Ʈ�� ������. ��? ����ü�� �޸𸮸� �������� ����??..  , 
union shape {
	
	int x;
	int y;
	
};


//����ü �ȿ��ִ� �ɹ����߿� ���� ū �������� ������ ũ��� �޸𸮸� ��Ƽ� ���� , ���⼭�� 8����Ʈ
union differ
{
	char a;
	int b;
	double c;


};


int ddmain(void)
{

	//����ü 
	{
	
		union shape test;
		union differ test2;

		test.x = 10;
		printf("union %d, %d\n", test.x, test.y);
		test.y = 20;
		printf("union %d, %d\n", test.x, test.y);
		printf("union������ %d\n",sizeof(test));
		printf("union������ %d\n", sizeof(union shape));

		printf("union������ %d\n", sizeof(test2));
		printf("union������ %d\n", sizeof(union differ));
	
	
	}


	//����ü�� �ڱ����� ������ linked list(������ ���Ѿ���, ��������)---------------------------------------------
	{

		WORKER a = { 1,"ȫ�浿",NULL };
		WORKER b = { 2,"���õ��",NULL };
		WORKER c = { 3,"��������",NULL };
		WORKER d = { 2,"����",NULL };
		WORKER e = { 3,"����",NULL };

		a.pLink = &b;
		b.pLink = &c;
		c.pLink = &d;
		d.pLink = &e;

		WORKER* pHead = &a;
		while (pHead != NULL)
		{
			printf("[%p] %d %s %p\n", pHead, pHead->no, pHead->name, pHead->pLink);
			pHead = pHead->pLink;
		}
	}





	//����ü�� ������ ---------------------------------------------

	STUDENT choi1 = { 1,"choi",{100,100,100} };
	STUDENT* pStu = NULL;

	pStu = &choi1;

	pStu->s.sum = pStu->s.kor + +pStu->s.eng + pStu->s.math;
	pStu->s.evg = pStu->s.sum / 3;

	printf("%d�� %s1�� ���� kor %d, eng %d, math %d, sum : %d evg : %f\n",
		pStu->no, pStu->name, pStu->s.kor, pStu->s.eng, pStu->s.math, pStu->s.sum, pStu->s.evg);



	//��ø ����ü --------------------------------------------------

	struct student choi = { 1,"choi",{100,100,100}};
	choi.s.sum = choi.s.kor + +choi.s.eng + choi.s.math;
	choi.s.evg = choi.s.sum / 3;

	printf("%d�� %s�� ���� kor %d, eng %d, math %d, sum : %d evg : %f\n",
		choi.no,choi.name ,choi.s.kor, choi.s.eng, choi.s.math, choi.s.sum, choi.s.evg);



	//����ü�� �迭 -------------------------------------------------
	struct score Myclass[5] = {
		{100, 50, 40},
		{70,15,8},
		{60,80,70},
		{21,87,63},
		{18,87,16}
	
	};

	struct score kim = { 100,20,70};

	kim.sum = kim.kor + kim.eng + kim.math;
	kim.evg = kim.sum/3;

	printf("kims kor %d, eng %d, math %d, sum : %d evg : %f\n", kim.kor, kim.eng, kim.math, kim.sum, kim.evg);


	for (int i = 0; i < sizeof(Myclass) / sizeof(struct score); i++)
	{
		Myclass[i].sum = Myclass[i].kor + Myclass[i].eng + Myclass[i].math;
		Myclass[i].evg = Myclass[i].sum / 3;
		printf("%d���� ���� kor %d, eng %d, math %d, sum : %d evg : %f\n",i+1, Myclass[i].kor, Myclass[i].eng, Myclass[i].math, Myclass[i].sum, Myclass[i].evg);
	}
	


	//����ü ---------------------------------------------------------------
	int a = 10;
	a = 100;

	struct point pt1 = {10,20};
	struct point pt2;
	MYPOINT pt3;
	MYRECT rect;


	pt2.x = 100;
	pt2.y = 200;

	printf("%d , %d\n", pt1.x, pt1.y);
	printf("%d , %d\n", pt2.x, pt2.y);

	struct rect rect1 = { 10, 20,30,40 };
	printf("%d , %d , %d, %d\n", rect1.x, rect1.y, rect1.w, rect1.h);

	printf(" MYPOINT size %d\n", sizeof(MYPOINT));
	printf(" MYPOINT size %d\n", sizeof(MYRECT));

	printf(" USERDATA size %d\n", sizeof(struct USERDATA));//8 , 5�ϰŰ����� �޸𸮸� ��°� 8byte�� ��°� ���ؼ� ������ 8����Ʈ�� ���缭 ����ش�.
															//�޸𸮰� �ʹ� �������� ���� ��������. 

	printf(" MYDATA size %d\n", sizeof(struct MYDATA));//16

	

	return 0;
}