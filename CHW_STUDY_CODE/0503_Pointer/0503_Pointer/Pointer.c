#include<stdio.h>
#define PI 3.14	//���

int wwmain(void)
{

	const double pi = 3.141592; //����� ����
	//pi = 4.14;

	int aaa = 1;
	int bbb = 2;

	const int* p = NULL;		//���� ���ٲ۴�.
	int* const pp = NULL;		
	//const int* const pp = NULL; //*p = ����, p = ���� �Ѵ� �Ұ����ϰ� �ݵ�� �ʱⰪ���� �ؾ��Ѵ�.


	//const�� �Ǿտ�
	p = &aaa;
	printf("1. p�� �� %d\n", *p);
	aaa = 100;
	printf("2. p�� �� %d\n", *p);
	//*p = 1000; //����
	//printf("3. p�� �� %d\n", *p);
	p = &bbb;
	printf("3. p�� �� %d\n", *p);

	//cosnt�� �߰���
	//pp = &aaa;
	//printf("1. p�� �� %d\n", *pp);
	aaa = 100;
//	printf("2. p�� �� %d\n", *pp);
	//*pp = 1000; //����
	//printf("3. p�� �� %d\n", *p);
	//pp = &bbb;
	//printf("3. p�� �� %d\n", *pp);



	int a[3]; //> a[2] == *(a+2);
	int arr[2][3] = { 10,20,30,40,50,60 };	// > arr[1][2] , **arr,  *arr[1]
	printf("arr�� size : %d\n", sizeof(arr));	//24byte

	int* ptr0;


	printf("ptr0�� size : %d\n", sizeof(ptr0));	//4byte

	ptr0 = arr;
	printf("1.�� : %d , �ּ� : %d\n", *ptr0, ptr0); //10 , �ּ�

	ptr0++;
	printf("2.�� : %d , �ּ� : %d\n", *ptr0, ptr0); //20 , �ּ�

	ptr0++;
	printf("3.�� : %d , �ּ� : %d\n", *ptr0, ptr0); //30 , �ּ�
	ptr0++;
	printf("4.�� : %d , �ּ� : %d\n", *ptr0, ptr0); //40 , �ּ�

	
	int* ptr1[3]; //�������� �迭

	printf("ptr1�� size : %d\n", sizeof(ptr1));	//4byte

	ptr1[1] = arr;
	printf("�� : %d , �� : %d\n", *ptr1[1], *(ptr1[1]+3)); // *(*(ptr1+1)+3))
	

	int(*ptr2)[3];	//int[3] �� ����Ű�� ������(�迭�� ������, 1��)

	printf("ptr2�� size : %d\n", sizeof(ptr2));	//4byte

	ptr2 = arr;
	printf("11.�� : %d , �ּ� : %d\n", **ptr2, *ptr2); //10, �ּ�

	ptr2++;
	printf("22.�� : %d , �ּ� : %d\n", **ptr2, *ptr2); // 40, �ּ�

	//ptr2++; �ѹ����ϸ� ���⼭ ����
	//printf("22.�� : %d , �ּ� : %d\n", **ptr2, *ptr2); // 40, �ּ�


	ptr2 = arr;
	printf("%d\n", ptr2[0]);	//�ּ�
	printf("%d\n", ptr2[1]);	//�ּ�
	printf("%d\n", ptr2[0][0]);	//10
	printf("%d\n", ptr2[1][0]); //40



	return 0;
}