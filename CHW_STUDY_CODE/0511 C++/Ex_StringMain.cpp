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
	name = name + "����";
	cout << name << endl;
	*/

	CMyString strData;
	strData.SetString("������");
	cout << strData.GetString() << endl;

	//1 ���ʿ��� �޸� �ذ��ʿ�.
	strData.SetString("�ٺ��ٹ�");
	cout << strData.GetString() << endl;
	
	//2 �������� �ذ� �ʿ� 
	CMyString strData2=strData; //== CMyString strData2(strData);
	cout << strData2.GetString() << endl;

	

	//3. ���ڿ��� �־ ����� ������ ����.
	CMyString strData33("ȣ��");
	cout << strData33.GetString() << endl;

	//4.���Կ�����
	CMyString strData4 = strData;
	cout << strData4.GetString() << endl;


	return 0;
}
#endif
