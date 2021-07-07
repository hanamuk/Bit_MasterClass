using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using static System.Console;

namespace _0707_Cshape06
{
    class Program
    {
        /*
        static int num = 10;
        static void m1()
        {
            WriteLine(1000);
        }
        */
        /*
        //int printf(int* p)
        int printf(const int* p)
        {
            if ( Random() == 99999 )
            {
                //*(p + 3) = '토';
            }
        }
        void memcpy(char *dest, const char *src);
        */
        /*
        enum Color
        {
            RED,
            GREEN = 100,
            BLUE
        };
        static void m1(Color color)
        { 
            switch (color)
            {
                case Color.RED:
                    break;
                case Color.GREEN:
                    break;
            }
        }
        */
        /*
        enum Day
        {
            일, 월, 화, 수, 목, 금, 토
        };
        */

        class Tiger
        {
            public void m1()
            {
                WriteLine("test");
            }
        }
        static void m1(Tiger t)
        {
            if (t != null)
            {
                t.m1();
            }
        }
        /*
        // C 문법
        static void f1(int a, int b)
        {
            int t; t = a; a = b; b = t;
        }
        static void f2(int* a, int* b)
        {
            if (a==null && b== null)
            {
                return;
            }
            int t; t = *a; *a = *b; *b = t;
        }
        static void f3(int& a, int& b)
        {
            int t; t = a; a = b; b = t;
        }
        */
        static void f1(int num)
        {
            int check;
            for (int i = 0; i < 32; i++)
            {
                check = 1 << (31 - i);
                if (i % 4 == 0 && i != 0)
                {
                    Write(" ");
                }
                Write((num & check) == 0 ? 0 : 1);
            }
            WriteLine();
        }
        static void m1(int a, int b)
        {
            int t = a;
            a = b;
            b = t;
        }
        static void m2(ref int a, ref int b)
        {
            int t = a;
            a = b;
            b = t;
        }
        class Lion
        {
            public int a = 10;
            public ref int f1()
            {
                //return 10;
                return ref a;   // a는 메모리 공유가 일어남
            }
        }
        static void Main(string[] args)
        {
            //////////////////////////////////////////////////////////////////////
            //WriteLine(num);
            //m1();
            //////////////////////////////////////////////////////////////////////
            /*
            Write(1000);
            WriteLine(2000);
            WriteLine("{0} {1}", 10, "호랑이");

            int a = 10;
            string s = "호랑이";
            WriteLine("{0} {1}", a, s);
            WriteLine($"{a} {s}");
            */
            //////////////////////////////////////////////////////////////////////
            /*
            int a = 10;
            string s = "호랑이";
            float f = 3.14f;
            double d = 3.14;
            WriteLine(a.GetType());
            WriteLine(s.GetType());
            WriteLine(f.GetType()); // double의 반대 type인 Single로 나타남.
            WriteLine(d.GetType());
            */
            //////////////////////////////////////////////////////////////////////
            //const int a = 10;   // 값을 갱신시킬 수 없다.
            //a = 20; // error

            /* C에서 사용되는 포인터 문법
            char* p = new char;

            // 1
            char* p;
            *p = 10;        // O
            p = new char;   // O

            // 2
            const char* p;
            *p = 10;        // X
            p = new char;   // O

            // 3
            char* const p;
            *p = 10;        // O
            p = new char;   // X

            // 4
            const char* const p;    // 값 변경 불가, 주소 변경 불가
            *p = 10;        // X
            p = new char;   // X
            */

            //printf("호 %d 랑 %s 이\n");
            //////////////////////////////////////////////////////////////////////
            /*
            WriteLine(Color.RED);
            WriteLine((int)Color.GREEN);
            WriteLine((int)Color.BLUE);

            Color c = Color.RED;
            WriteLine(c);
            m1(Color.RED);
            */
            //////////////////////////////////////////////////////////////////////
            /*
            // string 타입일 뿐이다.
            string a = "1000";

            // 컴파일 할 때 타입이 결정된다.
            // 컴파일이 끝나면, string 타입이다.
            var b = "2000";
            //b = 3000; // 타입을 바꿀 수 없음.

            // 컴파일 할 때 타입이 결정된다.
            object c = "3000";
            c = 4000;   // 타입을 바꿀 수 있음. 바꿀 때 타입이 다시 결정된다.

            // 실행할 때 타입이 결정된다.
            // danamic은 컴파일 할 때 에러를 발생시키지 않는 것이 목적
            // danamic은 다른 언어에 이식해서 사용할 때 사용
            dynamic d = "5000";
            d = 6000;
            string s = d;
            */
            //////////////////////////////////////////////////////////////////////
            //string a = "tiger";
            //WriteLine(a.Length);

            /*
            string b = null;
            if ( b != null )
            {
                WriteLine(b.Length);    // 방어적인 프로그래밍. (if문이 없으면, exception 발생함)
            }

            string b = null;
            WriteLine(b?.Length);   // null이면 exception을 내부적으로 처리

            string c = null;
            WriteLine(c.Length);    // exception 발생
            */

            //int[] ar = null;    // 객체 아님
            //WriteLine(ar[0]);   // exception 발생

            //int[] ar = null;    // 객체 아님
            //WriteLine(ar?[0]);  // null이면 exception을 내부적으로 처리

            //int? a = null;      // 객체가 정수 타입이지만, null 값을 가질 수 있다.
            //WriteLine(a ?? 0);  //a가 null이면 0을 선택한다.

            //int? b = 10;
            //WriteLine(b ?? 0);  //b가 null이면 0을 선택한다.
            //////////////////////////////////////////////////////////////////////
            //배열 사용법
            //int[] ar = new int[5];
            //int[] br = new int[] { 3, 4, 5 };
            //int[] cr = { 3, 4, 5 };
            //////////////////////////////////////////////////////////////////////
            /*
            WriteLine(DateTime.Now.DayOfWeek);
            WriteLine((int)DateTime.Now.DayOfWeek);

            string[] str = new string[] { "일", "월", "화", "수", "목", "금", "토" };
            int dw = (int)DateTime.Now.DayOfWeek;
            WriteLine(str[dw] + "요일");
            WriteLine("--------------");

            Day day = (Day)dw;
            WriteLine(day + "요일");
            WriteLine("--------------");

            WriteLine("{0} {1}", 10, "호랑이");
            string s = string.Format("{0} {1}", 10, "호랑이");
            WriteLine(s);
            WriteLine("--------------");

            //
            for (int i = 0; i < 10; i++)
            {
                string fileName = string.Format("{0:d4}.bmp", i);
                // file open(fileName, "read")
                WriteLine(fileName);
            }
            WriteLine("--------------");

            string name = "이순신";
            int age = 20;
            WriteLine($"{(age > 17 ? "성인" : "미성년")}");
            WriteLine($"{name} {(age > 17 ? "성인" : "미성년")}");

            int a = 0, b = 0, num = 0;
            _ = (num % 2 == 0) ? a++ : b++; // 받을 값이 없을 때 _ 사용(파이썬 문법?)
            _ = 100;
            */
            //////////////////////////////////////////////////////////////////////
            /*
            int a = 10;
            //int c = a++;    // ++a;

            if (true || ++a > 10)   // false 일 때만 뒤에 문장을 실행한다.
            {

            }
            WriteLine(a);   // 10
            */
            //////////////////////////////////////////////////////////////////////
            /*
            bool a = true;
            int b = 0;
            int c = 1;
            for (int i = 0; i < 10; i++)
            {
                //WriteLine(a);
                //a = !a;
                //WriteLine(b);
                //b = 1 - b;
                WriteLine(c);
                //c = -c;
                c = -1 * c;
            }
            */
            //////////////////////////////////////////////////////////////////////
            /*
            m1(null);
            Tiger t1 = null;

            if (t1 != null) // 방어적인 프로그래밍
            {
                t1.m1();
            }

            Tiger t2 = null;
            t2?.m1();   // 스스로 exception 처리
            WriteLine("--------------");
            t2 = new Tiger();
            t2?.m1();   // 함수 호출
            */
            //////////////////////////////////////////////////////////////////////
            /*
            // C 문법
            int x = 10, int y = 20;
            f1(x, y);   // call by value, 교환 X

            f1(&x, &y); // call by address, 교환 O, 주소를 던지기 때문에 null을 던질 수가 있음 -> 방어적인 프로그래밍이 필요함
            WriteLine(x + " " + y);

            f1(x, y); // call by reference, 교환 O, null을 던질 수가 없음 -> 방어적인 프로그래밍이 필요없음
            WriteLine(x + " " + y);
            */
            //////////////////////////////////////////////////////////////////////
            /*
            int n = 0x7bcd1234;
            f1(n);
            */
            //////////////////////////////////////////////////////////////////////
            /*
            // goto문 : 다중 for문에서 검색하고 빠져나올 때 사용?

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    // 검색
                    WriteLine(i * 4 + j);
                    if (i*4+j == 6)
                    {
                        goto FIND;
                    }
                }
            }
        FIND:
            WriteLine(1);
            */
            //////////////////////////////////////////////////////////////////////
            /*
            //C#에서의 데이터 교환 문법

            int x = 3, y = 4;
            WriteLine(x + " " + y); // 교환 X

            m1(x, y);
            WriteLine(x + " " + y); // 교환 X

            m2(ref x, ref y);
            WriteLine(x + " " + y); // 교환 O
            */
            //////////////////////////////////////////////////////////////////////
            /*
            // 공유 X
            Lion l = new Lion();
            int b = l.f1();
            b = 100;
            WriteLine(l.a);

            // 공유 문법
            ref int c = ref l.f1();
            c = 200;
            WriteLine(l.a);
            */
            //////////////////////////////////////////////////////////////////////
        }
    }
}