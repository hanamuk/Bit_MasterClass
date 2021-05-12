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
 

//템플릿 함수 정의
template <typename T> T mymax(T a, T b)//template <typename T, typename S> 처럼 몇개로도 사용가능.
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
	//함수 템플릿 1
	cout << mymax(10, 20) << endl;
	cout << mymax(3.14, 0.2) << endl;
	cout << mymax('a', 'b') << endl;

	//cout << mymax(10, 13.14) << endl; //error
	cout << mymax<int>(10, 13.14) << endl;//인자 두개가 타입이 다르면 정해줘야한다. T == int
	cout << mymax<double>(10, 13.14) << endl;// T == double

	//함수 템플릿 2
	int i = 50;
	int j = 10;
	cout << "바뀌기 전 i는 : " << i<<" "<< "j는 :" << j << endl;
	myswap(i, j);
	cout << "바꾼 후 i는 : " << i<<" "<< "j는 :" << j << endl;


	char c1 = 'a';
	char c2 = 'f';
	cout << "바뀌기 전 c1는 : " << c1 << " " << "c2는 :" << c2 << endl;
	myswap(c1, c2);
	cout << "바꾼 후 c1는 : " << c1 << " " << "c2는 :" << c2 << endl;

	return 0;
}
