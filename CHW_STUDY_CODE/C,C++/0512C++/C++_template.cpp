#include <iostream>

using namespace std;

//int mymax(int a, int b)
//{
//	return a > b ? a : b;
//	
//}
//char mymax(char a, char b)
//{
//	return a > b ? a : b;
//
//}
//
//double mymax(double a, double b)
//{
//	return a > b ? a : b;
//}
 

//���ø� �Լ� ����
template <typename T> T mymax(T a, T b)//template <typename T, typename S> ó�� ��ε� ��밡��.
{
	return a > b ? a : b;
}

template <typename T> void myswap(T& a, T& b)
{
	T temp;
	temp = a; 
	a = b;
	b = temp;
	
}

int main(void)
{
	//�Լ� ���ø� 1
	cout << mymax(10, 20) << endl;
	cout << mymax(3.14, 0.2) << endl;
	cout << mymax('a', 'b') << endl;

	//cout << mymax(10, 13.14) << endl; //error
	cout << mymax<int>(10, 13.14) << endl;//���� �ΰ��� Ÿ���� �ٸ��� ��������Ѵ�. T == int
	cout << mymax<double>(10, 13.14) << endl;// T == double

	//�Լ� ���ø� 2
	int i = 50;
	int j = 10;
	cout << "�ٲ�� �� i�� : " << i<<" "<< "j�� :" << j << endl;
	myswap(i, j);
	cout << "�ٲ� �� i�� : " << i<<" "<< "j�� :" << j << endl;


	char c1 = 'a';
	char c2 = 'f';
	cout << "�ٲ�� �� c1�� : " << c1 << " " << "c2�� :" << c2 << endl;
	myswap(c1, c2);
	cout << "�ٲ� �� c1�� : " << c1 << " " << "c2�� :" << c2 << endl;

	return 0;
}
