#include<iostream>

//#define ON_MAIN

#ifdef ON_MAIN //���� #define ON_MAIN �� ����Ǿ��ִٸ� �Ʒ� �ڵ� �����.

using namespace std;

class USERDATA2
{
public:	//�⺻���� private
	int nAge;
	char szName[32];

	void PrintData();
};

void  USERDATA2::PrintData()
{
	cout << "Ŭ���� : " << nAge << " " << szName << endl;
}


//����ü
typedef struct USERDATA
{

	int nAge;
	char szName[32];

	void (*Print)(USERDATA*); //�Լ������� �߰�

}USERDATA;

void PrintData(USERDATA* pUser)
{

	cout << pUser->nAge<<" "<< pUser->szName << endl;
}



int main(void)
{
	USERDATA user = { 20, "ö��",PrintData};

	cout << user.nAge << " " << user.szName << endl; //1�ܰ�
	PrintData(&user);								 //2�ܰ�
	user.nAge = 30;
	user.Print(&user);								 //3�ܰ�



	//��ü
	USERDATA2 his = { 33,"ȫ�浿" };
	his.PrintData();

	//Getter , Setter �Լ�
	{
		class CMyData
		{
		public:
			int m_nID;
			

		private :
			int m_nMoney;



		public:

			void PrintMoney() const //����� �޼���
			{
				cout << "������ : " << m_nMoney << endl;

			}
			int GetMoney(void) const //����� �޼���
			{ 
				//m_nMoney++; const�� ���� ����. read only �Լ�
				return m_nMoney; 
			}
			void SetMoney(int Money){
				if(m_nMoney >0)// üũ
				m_nMoney = Money;
			}
		};

		

		CMyData a;
		a.SetMoney(100);
		a.PrintMoney();
		cout << a.GetMoney()<<"�� �Դϴ�." << endl;


	}


	return 0;
}

#endif
