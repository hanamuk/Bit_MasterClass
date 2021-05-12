#include<iostream>
#include"CMyString.h"

//#define ON_MAIN
using namespace std;
#ifdef ON_MAIN 

int CMyString::m_nCount = 0;

int main(void)
{

	/*
	string name = "kkk";
	name = name + "만세";
	cout << name << endl;
	*/

	CMyString strData;
	strData.SetString("최현우");
	cout << strData.GetString() << endl;

	//1 불필요한 메모리 해결필요.
	strData.SetString("바보바바");
	cout << strData.GetString() << endl;
	
	//2 깊은복사 해결 필요 
	CMyString strData2=strData; //== CMyString strData2(strData);
	cout << strData2.GetString() << endl;

	

	//3. 문자열을 넣어서 만드는 생성자 생성.
	CMyString strData33("호동");
	cout << strData33.GetString() << endl;

	//4.대입연산자
	CMyString strData4 = strData;
	cout << strData4.GetString() << endl;


	return 0;
}
#endif
