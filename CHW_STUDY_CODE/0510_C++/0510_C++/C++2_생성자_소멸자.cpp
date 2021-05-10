#include<iostream>

#define ON_MAIN
using namespace std;
#ifdef ON_MAIN 


//생성자 소멸자
class CTest
{
public:

	int m_nA;
	int m_nB;
	const int m_nMax =50; //C++11 부터 값을 받아줌

	CTest()
		: m_nA(0), //초기화 목록 , 이건 const 변수나 ref변수를 초기화해줄때 사용한다. 왜나면 생성자의 {}가 열리기도 전이기때문에 가능.
		  m_nMax(100)
	{
		cout << "CTest 생성자" << endl;
	}
	CTest(int a)
		: m_nA(a)//초기화 목록
	{
		cout << "CTest 생성자 int" << endl;
		//m_nA = a;
	}

	CTest(int a, int b)
	{
		cout << "CTest 생성자 int, int" << endl;
		m_nA = a + b;
	}
	~CTest()
	{
		cout << "CTest 소멸자" << endl;
	
	}

};

int main(void)
{
	//생성자와 초기화 목록
	CTest b(200);
	cout << b.m_nA << endl;

	CTest b2(50);
	cout << b2.m_nA << endl;

	CTest c(20,99);
	cout << c.m_nA << endl;



	//객체의 동적생성		: 동적으로 할때는 소멸자가 delete메서드를 사용할때 호출된다.
	cout << "메인시작" << endl;
	CTest* pData = new CTest;
	cout << "Test" << endl;
	delete(pData);
	cout << "메인종료" << endl;


	//생성자 소멸자(정적 생성) : 정적으로 할떄는 소멸자가 메인이 끝날때 호출된다
	cout << "메인시작" << endl;
	CTest a(100);
	cout << "메인종료" << endl;

	return 0;
}
#endif