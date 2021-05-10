#include<stdio.h>

int sdsmain(void)
{


	int aList[4][5] = {
		{10,20,30,40},
		{50,60,70,80},
		{90,100,110,120}

	};

	int sum = 0;
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

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			

			if (i == 3) //a°¡ 3ÀÏ‹š 
			{
				for (int k = 0; k <= 4; k++)  // 0 1 2 3 4
				{
					for (int j = 2; j >= 0; j--) //  2 1 0
					{
						lsum += aList[j][k];
					}

					aList[i][k] = lsum;

					lsum = 0;
				}
			}

			if (j == 4)
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


	return 0;
}
