#include <iostream>
#define ON_MAIN
#ifdef ON_MAIN

using namespace std;

class CAniaml//virtual class
{
public:

    //���� �����Լ� pure virtual funtion
    //����� ������ �������̽� ���踦 ���� > �ڽĵ��� �����ؾ���.
    virtual void Cry() = 0;

    /*
    //�����Լ� virtual funtion
    virtual void Cry()  
    {
        cout << "���" << endl;
    }
    */
    void TestFun()
    {
        cout << "TestFun()" << endl;
        Cry();
        cout << "***************" << endl;
    }
};

class CDog : public CAniaml
{
public:

    void Cry()
    {
        cout << "�۸۸�" << endl;
    }

};
    
class CCat : public CAniaml
{
public:

    void Cry()
    {
        cout << "�߿�" << endl;
    }

};

int main()
{
    //virtual class(pure virtual funtion)
    {
        //virtual class�� ��ü�� ������ �� ����.
        //CAniaml zzz; //error
    }

    //Refernce+ virtual
    {
        CCat a;
        a.Cry();

        CAniaml& ref = a;
        ref.Cry();
    
    
    }
    return 0;
    //������ + virtual
    {
        CAniaml* p1 = new CCat;
        p1->Cry();
        delete p1;

        CAniaml* p2 = new CDog;
        p2->Cry();
        delete p2;
    }
    return 0;
    
    //������
    {
    
        CCat* a = new CCat;
        a->Cry();
        a->TestFun();
        delete a;

        CDog* b = new CDog;
        b->Cry();
        b->TestFun();
        delete b;
    }
    
    return 0;
}
#endif