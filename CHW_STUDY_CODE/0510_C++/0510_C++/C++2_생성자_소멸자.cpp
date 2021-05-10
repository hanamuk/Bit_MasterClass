#include<iostream>

#define ON_MAIN
using namespace std;
#ifdef ON_MAIN 


//������ �Ҹ���
class CTest
{
public:

	int m_nA;
	int m_nB;
	const int m_nMax =50; //C++11 ���� ���� �޾���

	CTest()
		: m_nA(0), //�ʱ�ȭ ��� , �̰� const ������ ref������ �ʱ�ȭ���ٶ� ����Ѵ�. �ֳ��� �������� {}�� �����⵵ ���̱⶧���� ����.
		  m_nMax(100)
	{
		cout << "CTest ������" << endl;
	}
	CTest(int a)
		: m_nA(a)//�ʱ�ȭ ���
	{
		cout << "CTest ������ int" << endl;
		//m_nA = a;
	}

	CTest(int a, int b)
	{
		cout << "CTest ������ int, int" << endl;
		m_nA = a + b;
	}
	~CTest()
	{
		cout << "CTest �Ҹ���" << endl;
	
	}

};

int main(void)
{
	//�����ڿ� �ʱ�ȭ ���
	CTest b(200);
	cout << b.m_nA << endl;

	CTest b2(50);
	cout << b2.m_nA << endl;

	CTest c(20,99);
	cout << c.m_nA << endl;



	//��ü�� ��������		: �������� �Ҷ��� �Ҹ��ڰ� delete�޼��带 ����Ҷ� ȣ��ȴ�.
	cout << "���ν���" << endl;
	CTest* pData = new CTest;
	cout << "Test" << endl;
	delete(pData);
	cout << "��������" << endl;


	//������ �Ҹ���(���� ����) : �������� �ҋ��� �Ҹ��ڰ� ������ ������ ȣ��ȴ�
	cout << "���ν���" << endl;
	CTest a(100);
	cout << "��������" << endl;

	return 0;
}
#endif