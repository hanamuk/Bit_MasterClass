//���� ���Ǳ�
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
	Drink drink[MAX] = { {1000 ,"�ݶ�"},  {1500,"�������꽺"}, {700,"����"} ,{1800, "�Ƹ޸�ī��"} };

	int nMenu = -1;

	int nMoney; //�Աݵ� �ݾ�
	int nChange; // �Ž�����.
	

	test(drink);
	
	
	//while (1)
	//while (nMenu!=0)
	for(;;) //���������� �̰ŷ� ���ѷ����� ���̾��ٴµ�?
	{
		if (nMenu == 0)
		{
			printf("�� \n\n");

			break;
		}


		menu(drink);


	
		input(&nMoney, &nMenu);

		Print(nMoney, nMenu, drink);

		Sleep(2000);
		system("cls");

		//����ġ�� ������ �񱳰����ϱ⶧���� �������� ����Ѵ�.
		/*
		switch (nMenu)
		{

		case 1:
			printf("�ݶ� �������� \n");
			break;
		case 2:
			printf("�������꽺 �������� \n");
			break;
		case 3:
			printf("���� �������� \n");
			break;
		case 0:
			printf("���� \n");
			power = 0;
			break;

		default:
			printf("�ٽ��Է� \n");


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
	printf("���Ǳ� \n");

	for (int i = 0; i < MAX; i++)
	{
		printf("%d. %s \t %d��\n", i+1, drink[i].szLabel, drink[i].nPrice);

	}
		

	printf("0. ���� \n"); 


}
void Print(int Money, int choice,  Drink drink[])
{
	int change;
	change = cal(Money, choice, drink[choice-1].nPrice);

	if (change != 0 && change > 0)
	{
		printf("�ܵ� %d ���� �������� \n", change);
		printf("%s �������� \n", drink[choice - 1].szLabel);
	}
	else if(change == 0)
	{
		printf("%s �������� \n", drink[choice - 1].szLabel);
	}
	else
	{
		printf("���� ����������");

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
		printf("���� %d�� ���ڶ��ϴ�.", need);
		return -1;
	}


	return Change;

}

void input(int* nMoney, int* nMenu)
{

	printf("============= \n");
	printf("���ϴ� �����ư�� �����ϼ��� : ");
	scanf_s("%d", nMenu);

	printf("�Է��� �ݾ��� �Է��ϼ��� : ");
	scanf_s("%d", nMoney);
	getchar();



}

