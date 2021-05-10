#include<stdio.h>

int ssmain(void)
{
	int nNum;


	printf("숫자를 입력하세요  : ");
	scanf_s("%d", &nNum);
	
	int num = nNum / 2 - 1; //4
	int num2 = num;
	for (int i = 0; i < nNum; i++) // 10
	{
		if (num == num2)
		{
			for (int j = 0; j < num; j++) //0 1 2 3
			{

				printf(" ");
			}

			printf("*");


			for (int j = 0; j < num; j++) //0 1 2 3
			{
				printf(" ");
			}

			printf("\n");
			num++;
		}
		else
		{
			for (int j = 0; j < num2; j++) //0 1 2 3
			{

				printf(" ");
			}

			printf("*");


			for (int j = 0; j < num2; j++) //0 1 2 3
			{
				printf(" ");
			}

			printf("\n");
			num++;


		}
		
		
	}
	




	return 0;
}