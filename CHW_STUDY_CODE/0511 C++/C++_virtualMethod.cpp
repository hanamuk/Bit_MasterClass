#include <iostream>
#define ON_MAIN
#ifdef ON_MAIN

using namespace std;

class CAniaml//virtual class
{
public:

    //순수 가상함수 pure virtual funtion
    //만드는 이유는 인터페이스 설계를 위해 > 자식들이 구현해야함.
    virtual void Cry() = 0;

    /*
    //가상함수 virtual funtion
    virtual void Cry()  
    {
        cout << "운다" << endl;
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
        cout << "멍멍멍" << endl;
    }

};
    
class CCat : public CAniaml
{
public:

    void Cry()
    {
        cout << "야옹" << endl;
    }

};

int main()
{
    //virtual class(pure virtual funtion)
    {
        //virtual class는 객체를 생성할 수 없다.
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
    //재정의 + virtual
    {
        CAniaml* p1 = new CCat;
        p1->Cry();
        delete p1;

        CAniaml* p2 = new CDog;
        p2->Cry();
        delete p2;
    }
    return 0;
    
    //재정의
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