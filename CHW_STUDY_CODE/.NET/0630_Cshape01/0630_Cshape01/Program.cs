using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;    //Console을 생략하고 사용가능.

namespace _0630_Cshape01
{
    class Tiger { }
    class Program
    {
        /*   
           //int a= 1000; 대입연산자가 생략되었다.
           static void m1(int a, Tiger t)
           { 


           }

           static void m2(int a)
           {


           }*/

        //프로그램 시작시 main 은 운영체제가 호출하는데 static 이 안붙으면 메모리에 올라간 메인이 없기 떄문에, os가 부를때 main을 호출하기위해 붙혀준것이다..
        static void Main(string[] args) 
        {
            /*Tiger t1 = new Tiger();

            Tiger t2 = null;    //객체가아니다
            t2 = new Tiger(); //나중에 사용가능
            t2 = null;*/


            //에러
            // int a = null;

            //int b = 10;
            //b = null;

            //경고
            //int c = 10;
            //if (c == null)
            // {
            //  WriteLine();
            //}

            /*nullable형식
            //일반타입의 null을 넣는 문법
            int? a= null;       //a 는 이제 객체가 아니다. nullable형식.
            int? b= 10;     //b를 만들떄 널을 가질수 있도록 설정
            b= null;        
            int? c = 20;

            if(c==null)
            {
                WriteLine(100);
            }
             */

            /*
            int? a= null;      
            int? b= 10;     
            int c = 20;
            WriteLine(a.HasValue);
            //문법 자체를쓸수없다
             WriteLine(c.HasValue);
            */



            /*    
                단축키..
              WriteLine("콘솔 생략");//lw이 단축키..

              for (int i = 0; i < length; i++)// for누르고 tab tab 두번누르면.. 자동으로 형식이 생성된다.
              {

              }

              foreach (var item in collection)    //foreach도 똑같음..
              {

              }*/

            /* write line 표기법
            WriteLine("0번쨰 인자 {0}, 1번쨰 인자 {1} , 3번쨰 넣기{0}",10, 20); //기본형태
            WriteLine("0번쨰 인자 {0:d4}, 1번쨰 인자 {1:d3}",10, 20);   //자리수를 맞춰주는 기능.. d4는 네자리로 출력해라 / 남는공간은 0으로 라는뜻
            WriteLine("0번쨰 인자 {0:x}, 1번쨰 인자 {1:x}",10, 20);     //x는 16진수로 표기해라.
            Clear();    //앞에꺼 지우기.
             */


            /*     //type  C#에서는 타입들이 클래스이다. 즉 실제로는 객체 그래서 함수를 사용가능. 
                   byte a1; // 0~ 255 , 음수불가
                   sbyte a2;   // -128~ 127
                   short a3; //2바이트
                   ushort a4; //양수만쓰는 ushort
                   uint a5; //양수int
                   long a6;
                   ulong a7;
                   char a9 = '한'; //C#에서는 char가 2바이트..

                  float a10 = 3.14f; 반드시 f를 마지막에 붙힌다
                  double a11 = 3.14
                  deciaml a12 = 3.14m;   16바이트로 더욱 세밀한 조정이 가능한 타입.. 마지막에 m을 붙혀줘야한다.
                  
                   WriteLine(byte.MaxValue);
                   WriteLine(byte.MinValue);

            */


            /* 출력 2
            int a = 10, b = 20;
            WriteLine("{0},{1}", a, b);
            WriteLine($"{a},{b}"); // $를 사용하면 외부 변수를 숫자가 아니라 이렇게 바로 접근해서 사용가능하다

            var c= 10;  //모든타입
            object d;   //모든타입
            dynamic e;  //모든타입
            */


            /*  // 1010 , 
              WriteLine(10);
              WriteLine(0x10); //16진수
              WriteLine(0b10); //2진수
              WriteLine(0b_0101_0111); */

            /*  long a = 10;
              //대입 연산자는 반드시 쌍반간에 타입이 동일해야한다./
              // 받는 타입으로 맞추어 준다

              //타입캐스팅
              int b = (int)a;


              Tiger t = new Tiger();
              m1(1000,t);
              m1(1000,new Tiger());

              //뮨법이 성립한다면
              //int a =  for () { };
              //m2(for () { });
             */

            //WriteLine(7 / 3);
            // WriteLine(7 % 3);   //% : 모듈러스 라고한다

            /*
            WriteLine(false ^ false);   //^ 는 XOR 이다. ,서로다르면 트루, 같으면 펄스
            WriteLine(false ^ true);
            WriteLine(true ^ false);
            WriteLine(true ^ true);
            */

            /* 3항연산자.
            int a = 10, b = 20, c;
            if (a > b)
            {
                c = a;
            }
            else
            {
                c = b;
            }

            c = a > b ? a : b;
            
            WriteLine(a>b?"호랑이":"코끼리"); 
            */

            /*
            int num = 10;
            int abs = num >=0 ? num : -num;
             */

            /*
            int? a= null;      
            int? b= 10;     
            int c = 20;

            //값이 가져올 값이있을떄는 가져오고 없으면 0을 설정
            WriteLine(a.GetValueOrDefault());
            WriteLine(b.GetValueOrDefault());
            WriteLine(b.GetValueOrDefault(-100)); //-100으로 디폴트 설정

            WriteLine(a == null ? -1 : a); //아래와 같은 의미

            //null통합연산
            WriteLine(a ?? -1); // a가 널이면 -1 이고, 아니면 값을 출력? 
            */
            /*
            char a ='A';
            char b = (char)65; ;
            int c = 65;
            int d = (int)'A';

            char? e;
            e = 'A';
            WriteLine(e ?? -2); */


        /* string 갱신
            string s1 = null;

            string s2 = "호랑이";
            WriteLine(s2);

            //----------------- 스트링 클래스로 만든 객체는 안에 들어있는 내용을 수정할 수없다. 그래서 위의 s2와 아래 s2는 다른 메모리이다
            //                  즉 위에 서 만든 이름과 같으면 위에꺼의 메모리를 지우고 아래 꺼로 메모리를 새로만든다. string은 값을 갱신 할 수 없다.
            s2 = "코끼리";
            WriteLine(s2);
            s2 += "독수리";
            WriteLine(s2);  //애도 마찬가지로 기존 s2메모리는 삭제되고 새로운 s2메모리ㅏ가 만들어진다.


            //string 갱신을 위한 클래스는 StringBuilder 를 사용해야한다
            StringBuilder s;

            // -----------를 대체하자!
            string s3 = new string('-', 30); //초기값으로 - 30개를 넣어주라
            WriteLine(s3);
            WriteLine(new string('-', 30));
        */
        }

        /* int m1(int a, int b)
         {
             return a > b ? 100 : 200;    
         }*/
    }
}
