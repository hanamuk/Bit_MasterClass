#include<stdio.h>

int sdmain(void)
{


	int aList[4][5] = {
		{10,20,30,40},
		{50,60,70,80},
		{90,100,110,120}

	};
	
	int sum=0;
	int lsum = 0;
		/*
;	for (int i = 0; i < sizeof(aList) / sizeof(aList[0]); i++)
	{
		for (int j = 0; j < sizeof(aList[0]) / sizeof(int); j++)
		{
			printf("%d\t" ,aList[i][j]);

		}
		printf("\n");

	}
*/

	for (int i = 0; i < sizeof(aList) / sizeof(aList[0]); i++)
	{
		for (int j = 0; j < sizeof(aList[0]) / sizeof(int); j++)
		{
			


			int a = (sizeof(aList[0]) / sizeof(int)) - 2;

			
			if (i == a) //a�� 3�ϋ� 
			{
				for (int k = 0; k < sizeof(aList) / sizeof(aList[0]); k++)  // 0 1 2 3 4
				{

					for (int j = a-1; j >= 0; j--) // 3 2 1 
					{

						lsum += aList[j][k];

					}
					aList[i][k] = lsum;
					lsum = 0;
				}
					
				
			}


			if (j + 1 == sizeof(aList[0]) / sizeof(int))
			{
				aList[i][j] = sum;
				printf("%d	", aList[i][j]);
				sum = 0;



			}
			else
			{
				printf("%d	", aList[i][j]);
				sum += aList[i][j];
			}

			
		}

		

		printf("\n");

	}


	/*

	///////////////////////////////////////
	int arrGrade[2][3] = { 1,2,3,4,5,6 };
	printf("�ּ� : %d\n", arrGrade);
	printf("�ּ� : %d\n", arrGrade[0]);
	printf("�� : %d\n", arrGrade[0][1]);
	printf("�� : %d\n", *(*(arrGrade)+1));

	printf("�ּ� : %d\n", arrGrade[1]);
	printf("�� : %d\n", arrGrade[1][1]);
	printf("�� : %d\n", *(*(arrGrade+1)+1));


	//////////////////////////////////////////


	int arNumbers[] = { 10, 22, 32, 5, 6, -1, 10 };
	int max;

	int arr[3] = { 1,2,3 };
	char latter[3] = { 'A', 'B', 'C' };

	max = arNumbers[0];

	// arNumbers�� �ϳ��� 4����Ʈ �̱⶧���� 4����Ʈ�� ������ ����Ѵ�. 
	for (int i = 1; i < sizeof(arNumbers)/sizeof(int); i++)
	{
		if (max < arNumbers[i])
			max = arNumbers[i];

	}

	printf("max ���� : %d\n", max);


	int min = *arNumbers;

	// arNumbers�� �ϳ��� 4����Ʈ �̱⶧���� 4����Ʈ�� ������ ����Ѵ�. 
	for (int i = 1; i < sizeof(arNumbers) / sizeof(int); i++)
	{
		if (min > *(arNumbers+i))
			min = *(arNumbers+i);

	}

	printf("min ���� : %d\n", min);

	printf("�� : %d, %d, %d\n", arr[0], arr[1], arr[2]);
	printf("��1 : %d, %d, %d\n", *arr, *(arr+1), *(arr+2));

	printf("�ּ� : %d, %d, %d\n", &arr[0],&arr[1], &arr[2]);
	printf("�ּ�1 : %d, %d, %d\n", arr, arr+1, arr+2);

	
	printf("-------------------------------------------\n");

	printf("�� : %d, %d, %d\n", latter[0], latter[1], latter[2]);
	printf("��1 : %d, %d, %d\n", *latter, *(latter+1), *(latter+2));

	printf("�ּ� : %d, %d, %d\n", &latter[0], &latter[1], &latter[2]);
	printf("�ּ�1 : %d, %d, %d\n", latter, latter + 1, latter + 2);



	*/


	return 0;
}
