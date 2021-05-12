//음료 자판기
#include<stdio.h>
#include<windows.h>
#define MAX 4


typedef struct Drink {

	int nPrice;
	char szLabel[12];

}Drink;

int cal(int Money, int choice, int price);
void Print(int Money, int choice,  Drink drink[]);
void menu(Drink drink[]);
void input(int* nMoney, int* nMenu);




int main(void)
{
	Drink drink[MAX] = { {1000 ,"콜라"},  {1500,"오렌지쥬스"}, {700,"생수"} ,{1800, "아메리카노"} };

	int nMenu = -1;

	int nMoney; //입금된 금액
	int nChange; // 거스름돈.
	

	test(drink);
	
	
	//while (1)
	//while (nMenu!=0)
	for(;;) //실전에서는 이거로 무한루프를 많이쓴다는데?
	{
		if (nMenu == 0)
		{
			printf("끝 \n\n");

			break;
		}


		menu(drink);


	
		input(&nMoney, &nMenu);

		Print(nMoney, nMenu, drink);

		Sleep(2000);
		system("cls");

		//스위치는 정수만 비교가능하기때문에 이프문을 사용한다.
		/*
		switch (nMenu)
		{

		case 1:
			printf("콜라 받으세요 \n");
			break;
		case 2:
			printf("오렌지쥬스 받으세요 \n");
			break;
		case 3:
			printf("생수 받으세요 \n");
			break;
		case 0:
			printf("종료 \n");
			power = 0;
			break;

		default:
			printf("다시입력 \n");


		}
		*/

	}


	return 0;
}

void test(Drink* drink)
{

	drink->nPrice;
	(drink + 1)->nPrice;
}

void menu(Drink drink[])

{
	printf("자판기 \n");

	for (int i = 0; i < MAX; i++)
	{
		printf("%d. %s \t %d원\n", i+1, drink[i].szLabel, drink[i].nPrice);

	}
		

	printf("0. 종료 \n"); 


}
void Print(int Money, int choice,  Drink drink[])
{
	int change;
	change = cal(Money, choice, drink[choice-1].nPrice);

	if (change != 0 && change > 0)
	{
		printf("잔돈 %d 원을 받으세요 \n", change);
		printf("%s 받으세요 \n", drink[choice - 1].szLabel);
	}
	else if(change == 0)
	{
		printf("%s 받으세요 \n", drink[choice - 1].szLabel);
	}
	else
	{
		printf("돈을 더넣으세요");

	}
	



}

int cal(int Money, int choice, int price)
{
	int Change=0;

	Change = Money - price;

	if (Change < 0)
	{
		int need = 0;
		need = price- Money;
		printf("돈이 %d원 모자랍니다.", need);
		return -1;
	}


	return Change;

}

void input(int* nMoney, int* nMenu)
{

	printf("============= \n");
	printf("원하는 음료버튼을 선택하세요 : ");
	scanf_s("%d", nMenu);

	printf("입력할 금액을 입력하세요 : ");
	scanf_s("%d", nMoney);
	getchar();



}

