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
private:    //���� ���ٰ���  
    int m_nData = 0;

public:     //������ ���ٰ���
    CParent() { cout << "CParent()" << endl; }
    CParent(int a) { cout << "CParent(int)" << endl; }
    CParent(double a) { cout << "CParent(double)" << endl; }

    int GetData() { return m_nData; }
    void SetData(int nParam) { m_nData = nParam; }

protected: //�Ļ� Ŭ���� ���ο����� ���ٰ���. main������ �ȴ�.
    void PrintData() { cout << "CParent::PrintData() : " << m_nData << endl; }
};

////////////////////////////////////////////////////


class CChild : public CParent
{
public:
    CChild() { cout << "CChild()" << endl; }
    CChild(int a) :CParent(a) //CChild(int a) �����ڰ� �Ҹ��� �θ� int ������ ȣ���ض�
    { 
        cout << "CChild(int)" << endl;
    }
    CChild(double a) :CParent()//CChild(double a) �����ڰ� �Ҹ��� �θ�� �⺻�����ڸ� ȣ���ض�
    {
        cout << "CChild(double)" << endl; 
    }

    void TestFunc()
    {
        SetData(5);//public
        PrintData();//protected
    }

    //������ �������̵�
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
    //�����ڸ� ������
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
        //���� Ŭ���� - ���� �����ϴ� ����̾���.
        CParent a;
        a.SetData(15);
        cout << a.GetData() << endl;

        //��� Ŭ���� - ���� �����ϴ� ����� �ִ�.
        CChild b;
        b.SetData(15);
        cout << b.GetData() << endl;


        CParent& ref = b; //���Ŭ������ ����Ŭ���������Ϳ� �־����� �����Ϸ��� �������� �ڷ����� ���� �Լ��� ȣ��ȴ�. �׷��� �Ʒ��� ����Ŭ������ �Լ�ȣ��.
        ref.SetData(20);
        cout << ref.GetData() << endl;

        //protected�� ��������
        //a.PrintData(); error , protected �̹Ƿ� ����
        //a.TestFunc();

        return 0;
    }



    //���
    {
        cout << "*****Main Begin*****" << endl;
        CMyData_C xxx;
        cout << "*****Main End*****" << endl;
    }

    return 0;
}
#endif