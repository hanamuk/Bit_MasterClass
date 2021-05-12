#include <iostream>
#define ON_MAIN
#ifdef ON_MAIN

using namespace std;

class CMyData_A
{

protected:
    char* m_pData;
public:

    CMyData_A() 
    { 
        cout << "CMyData_A()" << endl;
        m_pData = new char[32];
    }
    ~CMyData_A() 
    { 
        cout << "~CMyData_A()" << endl; 
        if(m_pData!=NULL)
            delete[] m_pData;
    }
};

class CMyData_B : public CMyData_A
{
public:
    CMyData_B() { cout << "CMyData_B()" << endl; }
    ~CMyData_B() { cout << "~CMyData_B()" << endl; }
};

class CMyData_C : public CMyData_B
{
public:
    CMyData_C() { cout << "CMyData_C()" << endl; }
    ~CMyData_C() 
    { 
        cout << "~CMyData_C()" << endl; 
        delete[] m_pData;
        m_pData = NULL;
    }
};
//////////////////////////////////////////////////

class CParent
{
private:    //나만 접근가능  
    int m_nData = 0;

public:     //누구나 접근가능
    CParent() { cout << "CParent()" << endl; }
    CParent(int a) { cout << "CParent(int)" << endl; }
    CParent(double a) { cout << "CParent(double)" << endl; }

    int GetData() { return m_nData; }
    void SetData(int nParam) { m_nData = nParam; }

protected: //파생 클래스 내부에서만 접근가능. main에서는 안댐.
    void PrintData() { cout << "CParent::PrintData() : " << m_nData << endl; }
};

////////////////////////////////////////////////////


class CChild : public CParent
{
public:
    CChild() { cout << "CChild()" << endl; }
    CChild(int a) :CParent(a) //CChild(int a) 생성자가 불리면 부모도 int 생성자 호출해라
    { 
        cout << "CChild(int)" << endl;
    }
    CChild(double a) :CParent()//CChild(double a) 생성자가 불리면 부모는 기본생성자를 호출해라
    {
        cout << "CChild(double)" << endl; 
    }

    void TestFunc()
    {
        SetData(5);//public
        PrintData();//protected
    }

    //재정의 오버라이딩
    void SetData(int nParam)
    {
        if (nParam < 0)
            CParent::SetData(0);
        else if (nParam > 10)
            CParent::SetData(10);
        else
            CParent::SetData(nParam);
  
    }
 
};

int main()
{
    //생성자를 선택함
    {
        CChild a;
        cout << "***************" << endl;
        CChild b(5);
        cout << "***************" << endl;
        CChild c(3.3);
        cout << "***************" << endl;
    
        return 0;
    }




    {
        //구형 클래스 - 값을 보정하는 기능이없다.
        CParent a;
        a.SetData(15);
        cout << a.GetData() << endl;

        //상속 클래스 - 값을 보정하는 기능이 있다.
        CChild b;
        b.SetData(15);
        cout << b.GetData() << endl;


        CParent& ref = b; //상속클래스를 구형클래스포인터에 넣었을떄 컴파일러는 포인터의 자료형에 따라 함수가 호출된다. 그래서 아래는 구형클래스의 함수호출.
        ref.SetData(20);
        cout << ref.GetData() << endl;

        //protected의 접근주의
        //a.PrintData(); error , protected 이므로 에러
        //a.TestFunc();

        return 0;
    }



    //상속
    {
        cout << "*****Main Begin*****" << endl;
        CMyData_C xxx;
        cout << "*****Main End*****" << endl;
    }

    return 0;
}
#endif