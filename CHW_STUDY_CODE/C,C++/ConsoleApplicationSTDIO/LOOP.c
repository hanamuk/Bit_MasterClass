#include<stdio.h>

int asdmain(void)
{
	int nNum;
	int sum =0;

	printf("���ڸ� �Է��ϼ���  : ");
	scanf_s("%d", &nNum);

	//for(int i = 0; i<= nNum && i % 2 == 0; i++)
	for (int i = 0; i <= nNum; i+=2)
	{
			sum += i;
	}


	int j = 0;
	while(j <= nNum)
	{
		sum += j;
		j+=2;
	}


	for (int i = 0; i <= nNum; i ++)
	{
		
		for(int j =1 ;j <= i; j++)
		{
			printf("%d", j);
			
		}
		printf("\n");
		

	}

	for (int i = 0; i <= nNum; i++)
	{

		for (int j = 1; j <= i; j++)
		{
			printf("*" );

		}



		printf("\n");




	}

	//��������
	for (int i = 0; i < nNum; i++)
	{
		

		for (int j = 0; j< nNum-i-1; j++) {
			printf(" ");
			
		}

		for (int j = 0; j <= i; j++)
		{
			printf("*");

		}
		printf("\n");
		

	}



	//printf("����� %d �Դϴ� \n", sum);
	

	return 0;
}