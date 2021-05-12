#include<iostream>

//#define ON_MAIN

#ifdef ON_MAIN //위에 #define ON_MAIN 가 선언되어있다면 아래 코드 실행됨.

using namespace std;

class USERDATA2
{
public:	//기본값은 private
	int nAge;
	char szName[32];

	void PrintData();
};

void  USERDATA2::PrintData()
{
	cout << "클래스 : " << nAge << " " << szName << endl;
}


//구조체
typedef struct USERDATA
{

	int nAge;
	char szName[32];

	void (*Print)(USERDATA*); //함수포인터 추가

}USERDATA;

void PrintData(USERDATA* pUser)
{

	cout << pUser->nAge<<" "<< pUser->szName << endl;
}



int main(void)
{
	USERDATA user = { 20, "철수",PrintData};

	cout << user.nAge << " " << user.szName << endl; //1단계
	PrintData(&user);								 //2단계
	user.nAge = 30;
	user.Print(&user);								 //3단계



	//객체
	USERDATA2 his = { 33,"홍길동" };
	his.PrintData();

	//Getter , Setter 함수
	{
		class CMyData
		{
		public:
			int m_nID;
			

		private :
			int m_nMoney;



		public:

			void PrintMoney() const //상수형 메서드
			{
				cout << "내돈은 : " << m_nMoney << endl;

			}
			int GetMoney(void) const //상수형 메서드
			{ 
				//m_nMoney++; const를 쓰면 에러. read only 함수
				return m_nMoney; 
			}
			void SetMoney(int Money){
				if(m_nMoney >0)// 체크
				m_nMoney = Money;
			}
		};

		

		CMyData a;
		a.SetMoney(100);
		a.PrintMoney();
		cout << a.GetMoney()<<"원 입니다." << endl;


	}


	return 0;
}

#endif
