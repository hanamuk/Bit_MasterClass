// C++Project.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
//using namespace TEST;


void Gugudan()
{

    cout << "Global::Gugudan()" << endl;

}
int g_nData = 1000;

/*
namespace TEST
{
    int g_nData = 100;


    void Gugudan(void)
    {

        cout << "TEST::Gugudan()" << endl;

    }

}
*/

void TestFuncRef1(int rParam)
{
    rParam = 100;
        

}


void TestFuncRef2(int& rParam)
{
    rParam = 100;


}


void TestFuncRef3(int* rParam)
{
    *rParam = 100;


}

int Sum(int a, int b)
{
    return a + b;
}

int Sum(int a, int b, int c)
{
    return a + b+ c;
}

double Sum(double a, double b)
{
    return a + b;
}


int TestFun2(int nParam = 99 )//아무 변수도 안들올 떄 nParam은 10
{
    return nParam *2;
}

int TestFun3(int a = 9, int b= 8 , int c = 99)//디폴트 값은 뒤쪽매개변수 먼저 줘야한다. c> b >a 순으로, 중간에 b가 빠지고 주면 안댐.
{
    return c * 2;
}


inline int add(int a, int b)    //inline을 사용하면 매크로와 일반함수의 장점을 합친것. 즉 연산자취급.. 작은함수에서만 사용하는게 좋다
{

    return a + b;
}

#define ADD(a,b)((a)+(b))//매크로함수

int main()
{   
    //inline함수 (vs 매크로 함수)

    cout << add(10, 20) << endl;
    cout << ADD(30, 40) << endl;    //함수처럼보이지만 얘는 연산자로 취급되서 바로 연산.






    /*

    //범위 기반 for문
    int aList[5] = { 10,20,30,40,50 };
    int sum = 0;

    //c스타일
    for (int i = 0; i < 5; i++)
    {

        sum += aList[i];
    }
    cout <<"결과출력 1. :"<< sum<<endl;

    sum = 0;


    //c++스타일
    for (auto n : aList)    //auto는 aList나오는 것의 자료형을 알아서 맞춰주라 라는 소리임. 확실하다면 다른자료형으로 바꿔도 됨
    {
        sum += n;
    }
    cout << "결과출력 1. :" << sum << endl;

    
    //문자열

    string name = " 홍길동";

    cout << name << endl;

    cout << name.size() << endl;

    name = "박태환";
    cout << name << endl;

    if (name == "박태환")
    {
        cout << "이름일치" << endl;
    }
    else
    {
        cout << "이름 불일치" << endl;
    }

    name += " 만세";

    cout << name << endl;


    
    //동적메모리 연산자
    //1.
    int* p1 = new int;
    *p1 = 10;

    cout << *p1 << endl;
    delete p1;

    //2.
    int* p2 = new int(100);

    cout << *p2 << endl;
    delete p2;

    //3.
    int* arr = new int[5];
    for (int i = 0; i < 5; i++)
    {
        arr[i] = i*10;
        cout << arr[i] << endl;
    }
    delete[] arr; //배열을지울떄.
    

    //디폴트 매개변수

    int a =TestFun2(10);
    cout << a << endl;

    int  b = TestFun2();
    cout << b << endl;

    
    //함수오버로딩(= 다중정의, 같은이름의 다중정의)-> C++가 네임맹글링을 통해 가능하게 해줌.>> 
    //근데 같은이름함수만 맹글링하는게아니고 모든 함수가 맹글링되기떄문에 라이브러리 개발자
    //같은사람들은 맹글링하면 안되기때문에 extern"C" (c스타일로 사용해라) 라고 DLL(라이브러리) 시작부분에 선언해주어야 한다
    cout << Sum(3, 4) << endl;
    cout << Sum(3, 4,5) << endl;
    cout << Sum(3.3, 4.4) << endl;

    
    
    //call by reference
    int nData = 0;

    nData = 0;
    TestFuncRef1(nData);
    cout <<"1."<< nData << endl;

    nData = 0;
    TestFuncRef2(nData);
    cout <<"2." << nData << endl;

 
    //포인터 VS 레퍼런스(별명)
    int nData = 10;
    int* pt = &nData; // 포인터의 선언과 초기화
    int& ref = nData;//레퍼런스의 선언과 초기화

    cout << nData << endl;
    //ref = 20;
    cout << nData << endl;
    nData = 30;
    cout <<"여기"<< ref << endl;


    int nAnter = 1000;
    //ref = nAnter;
    //ref++;
    cout << ref << endl;


 
    ::Gugudan();          //전역함수
    TEST::Gugudan();    //TEST 소속함수
    cout <<::g_nData<<endl;
    cout << ::g_nData << endl;
    cout << TEST::g_nData << endl;



   
    //auto 사용
    int a = 10;
    cout << a << endl;
    int b(a); // ==   b=a처럼 쓰는거와 같다.
    auto c(b);  //auto를 사용하면 할당값에 따라서 c의 자료형이 b이따라 달라진다.
    
    cout << a + b + c << endl;


 
  
    //cin, cout 사용
    std::cout << "Hello World!\n";

    int a = 3;
    std::cout << a <<"가 뭘까?"<< "\n";
    std::cout << __LINE__ << endl;

    cout << 3 + 4 << endl;


    int nAge;
    cout << "나이를 입력하세요" << endl;
    cin >> nAge;

    char szJab[32];     //sz는 char문자열로 만들떄 사용하고 str은 string일떄.
    cout << "직업을 입력하세요" << endl;
    cin >> szJab;

    string strName;
    cout << "이름을 입력하세요" << endl;
    cin >> strName;

    string nickname = "천재";
    
    strName += nickname;

    cout << "당신의 이름은 " << strName << "이고, " << "나이는" << nAge << "살이며" << "직업은" << szJab << "입니다" << endl;
    */



}
