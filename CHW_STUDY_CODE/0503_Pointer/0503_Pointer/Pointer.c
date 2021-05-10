#include<stdio.h>
#define PI 3.14	//상수

int wwmain(void)
{

	const double pi = 3.141592; //상수형 변수
	//pi = 4.14;

	int aaa = 1;
	int bbb = 2;

	const int* p = NULL;		//값을 못바꾼다.
	int* const pp = NULL;		
	//const int* const pp = NULL; //*p = 대입, p = 대입 둘다 불가능하고 반드시 초기값으로 해야한다.


	//const가 맨앞에
	p = &aaa;
	printf("1. p의 값 %d\n", *p);
	aaa = 100;
	printf("2. p의 값 %d\n", *p);
	//*p = 1000; //에러
	//printf("3. p의 값 %d\n", *p);
	p = &bbb;
	printf("3. p의 값 %d\n", *p);

	//cosnt가 중간에
	//pp = &aaa;
	//printf("1. p의 값 %d\n", *pp);
	aaa = 100;
//	printf("2. p의 값 %d\n", *pp);
	//*pp = 1000; //에러
	//printf("3. p의 값 %d\n", *p);
	//pp = &bbb;
	//printf("3. p의 값 %d\n", *pp);



	int a[3]; //> a[2] == *(a+2);
	int arr[2][3] = { 10,20,30,40,50,60 };	// > arr[1][2] , **arr,  *arr[1]
	printf("arr의 size : %d\n", sizeof(arr));	//24byte

	int* ptr0;


	printf("ptr0의 size : %d\n", sizeof(ptr0));	//4byte

	ptr0 = arr;
	printf("1.값 : %d , 주소 : %d\n", *ptr0, ptr0); //10 , 주소

	ptr0++;
	printf("2.값 : %d , 주소 : %d\n", *ptr0, ptr0); //20 , 주소

	ptr0++;
	printf("3.값 : %d , 주소 : %d\n", *ptr0, ptr0); //30 , 주소
	ptr0++;
	printf("4.값 : %d , 주소 : %d\n", *ptr0, ptr0); //40 , 주소

	
	int* ptr1[3]; //포인터의 배열

	printf("ptr1의 size : %d\n", sizeof(ptr1));	//4byte

	ptr1[1] = arr;
	printf("값 : %d , 값 : %d\n", *ptr1[1], *(ptr1[1]+3)); // *(*(ptr1+1)+3))
	

	int(*ptr2)[3];	//int[3] 을 가르키는 포인터(배열의 포인터, 1개)

	printf("ptr2의 size : %d\n", sizeof(ptr2));	//4byte

	ptr2 = arr;
	printf("11.값 : %d , 주소 : %d\n", **ptr2, *ptr2); //10, 주소

	ptr2++;
	printf("22.값 : %d , 주소 : %d\n", **ptr2, *ptr2); // 40, 주소

	//ptr2++; 한번더하면 여기서 죽음
	//printf("22.값 : %d , 주소 : %d\n", **ptr2, *ptr2); // 40, 주소


	ptr2 = arr;
	printf("%d\n", ptr2[0]);	//주소
	printf("%d\n", ptr2[1]);	//주소
	printf("%d\n", ptr2[0][0]);	//10
	printf("%d\n", ptr2[1][0]); //40



	return 0;
}