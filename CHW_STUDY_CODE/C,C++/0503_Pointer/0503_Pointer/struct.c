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

//typedef는 구조체에만 쓰는것이 아니다.


//typedef struct point MYPOINT;	이것도가능. 
//typedef 를하면 아래 코드에서 struct를 생략가능 , 세미콜론 앞에 이름을 작성하면 그이름으로 구조체의 이름을 대신할 수 있음



/*
//#pragma pack(push,1)
//#pragma pack(pop) 명령어는 메모리를 1바이트단위로 잡아라 라는 뜻이다. 8바이트씩 메모리를 잡아서 버려지는 메모리가 너무 많다거나 할떄 이렇게 명령어를 주면 
					1바이트 단위로 메모리를 잡는다.
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


//사이즈가 4바이트가 잡힌다. 왜? 공용체는 메모리를 공용으로 쓴다??..  , 
union shape {
	
	int x;
	int y;
	
};


//공용체 안에있는 맴버들중에 가장 큰 사이즈의 변수의 크기로 메모리를 잡아서 공용 , 여기서는 8바이트
union differ
{
	char a;
	int b;
	double c;


};


int ddmain(void)
{

	//공용체 
	{
	
		union shape test;
		union differ test2;

		test.x = 10;
		printf("union %d, %d\n", test.x, test.y);
		test.y = 20;
		printf("union %d, %d\n", test.x, test.y);
		printf("union사이즈 %d\n",sizeof(test));
		printf("union사이즈 %d\n", sizeof(union shape));

		printf("union사이즈 %d\n", sizeof(test2));
		printf("union사이즈 %d\n", sizeof(union differ));
	
	
	}


	//구조체의 자기참조 포인터 linked list(사이즈 제한없음, 삭제쉬움)---------------------------------------------
	{

		WORKER a = { 1,"홍길동",NULL };
		WORKER b = { 2,"김밥천국",NULL };
		WORKER c = { 3,"빌게이츠",NULL };
		WORKER d = { 2,"개송",NULL };
		WORKER e = { 3,"병원",NULL };

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





	//구조체의 포인터 ---------------------------------------------

	STUDENT choi1 = { 1,"choi",{100,100,100} };
	STUDENT* pStu = NULL;

	pStu = &choi1;

	pStu->s.sum = pStu->s.kor + +pStu->s.eng + pStu->s.math;
	pStu->s.evg = pStu->s.sum / 3;

	printf("%d번 %s1의 성적 kor %d, eng %d, math %d, sum : %d evg : %f\n",
		pStu->no, pStu->name, pStu->s.kor, pStu->s.eng, pStu->s.math, pStu->s.sum, pStu->s.evg);



	//중첩 구조체 --------------------------------------------------

	struct student choi = { 1,"choi",{100,100,100}};
	choi.s.sum = choi.s.kor + +choi.s.eng + choi.s.math;
	choi.s.evg = choi.s.sum / 3;

	printf("%d번 %s의 성적 kor %d, eng %d, math %d, sum : %d evg : %f\n",
		choi.no,choi.name ,choi.s.kor, choi.s.eng, choi.s.math, choi.s.sum, choi.s.evg);



	//구조체의 배열 -------------------------------------------------
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
		printf("%d번의 성적 kor %d, eng %d, math %d, sum : %d evg : %f\n",i+1, Myclass[i].kor, Myclass[i].eng, Myclass[i].math, Myclass[i].sum, Myclass[i].evg);
	}
	


	//구조체 ---------------------------------------------------------------
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

	printf(" USERDATA size %d\n", sizeof(struct USERDATA));//8 , 5일거같은데 메모리를 잡는게 8byte로 잡는게 편해서 무조건 8바이트에 맞춰서 잡아준다.
															//메모리가 너무 조각나는 것을 막기위해. 

	printf(" MYDATA size %d\n", sizeof(struct MYDATA));//16

	

	return 0;
}