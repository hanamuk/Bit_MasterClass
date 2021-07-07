using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
namespace _0702_Cshape02
{
    class Program
    {
        /* 함수, 가변인자
        //리턴이없다, 전달인수가 없다
        static void f1() { }
        //리턴이 없고 전달인수가 없다
        static void f2(int a ,string s) {}
        //리턴이있고 전달인수가 없다
        static int f3() { return 100; }
        //리턴이있꼬 전달인수가 있다.
        static int f4(int a) { return 100; }


        //params는 가변인자.. 받아도 되고 안받아도 되는 매개변수. C에서는 void f5(string s, ...) 이런식으로 ...으로 적혀있음.
        static void f5(string s,  params int[] p)
        {
            WriteLine(s);
            int sum = 0;
            foreach (var item in p)
            {
                sum += item;
            }
            WriteLine(sum);
        }
        */


        static void Main(string[] args)
        {

            //f5("호랑이");
            //f5("호랑이",20,24,3433,244);

            /*swap , reverse ----------------------------------------------------
            string s = "무궁화 꽃이 피었습니다";
            char[] ar = s.ToCharArray();
            foreach (var item in ar)
            {
                WriteLine(item);
            }
            Array.Reverse(ar);
            WriteLine(ar);

            //리버스 구현?
            for (int i = 0; i < ar.Length/2; i++)
            {
                int nCount = ar.Length-1;
                var temp = ar[i];
                ar[i] = ar[nCount -i];
                ar[nCount - i] = temp;
            }
            WriteLine(ar);
            */

            /*
            //GUID 발급 : 보안문제 .. 관한 고유아이디 발급------------------------------------------
            Guid id1 = Guid.NewGuid();
            WriteLine(id1);
            string id2 = Guid.NewGuid().ToString(); //ToString("D") 은 디폴트 D가 숨어있다
            WriteLine(id2);
            string id3 = Guid.NewGuid().ToString("N"); //ToString("N") , N을 넣으면 '-' 하이푼이 제거된다.
            WriteLine(id3);

            string id4 = Guid.NewGuid().ToString("B"); //ToString("B")는 {}스코프를 붙혀준다
            WriteLine(id4);
            string id5 = Guid.NewGuid().ToString("P"); //ToString("P")는 ()괄호를 붙혀준다
            WriteLine(id5);
            */

            /*
            int num = 0xabcd;
            WriteLine(num);
            WriteLine(Convert.ToString(num, 2));// ToString(num, 2) 은 num을 2진법으로 바꾸어라.
            WriteLine(Convert.ToString(num, 8));// ToString(num, 8) 은 num을 8진법으로 바꾸어라.
            WriteLine(Convert.ToString(num, 10));// ToString(num, 10) 은 num을 10진법으로 바꾸어라.
            WriteLine(Convert.ToString(num, 16));// ToString(num, 16) 은 num을 16진법으로 바꾸어라.

            string s = Convert.ToString(num, 2);
            WriteLine(s.PadLeft(32,'0'));           //총 32자리를 나오게하는데 빈공간은 0으로 표시
            */

            //ox 랜덤출력. 9개.  배열사용하지않고, 모양이 연속된 것의 최대 갯수를 표현하라 ...
            Random rand = new Random();

            /* 내코드
            while (true)
            {
                Write("99는 종료, 계속은 숫자 : ");
                int input = int.Parse(ReadLine());

                if (input == 99)
                    break;

                int nMaxO = 0;
                int nOtemp = 0;
                int nMaxX = 0;
                int nXtemp = 0;
                int nPreChar = -1;

                for (int i = 0; i < 9; i++)
                {
                    int nRand = rand.Next(0, 2);     //0  = O, 1 = X 나온다.
                    Write(nRand == 0 ? "O" : "X");

                   

                    if (nRand == nPreChar)
                    {
                        if (nRand == 0)
                            nOtemp++;
                        else if (nRand == 1)
                            nXtemp++;
                    }
                    else
                    {
                        if (nMaxO < nOtemp)
                        {
                            nMaxO = nOtemp;
                            nOtemp = 0;
                        }

                        if (nMaxX < nXtemp)
                        {
                            nMaxX = nXtemp;
                            nXtemp = 0;
                        }
                        
                    }
                    nPreChar = nRand;


                }
                WriteLine();

                if (nMaxO < nOtemp)
                {
                    nMaxO = nOtemp;
                    nOtemp = 0;
                }

                if (nMaxX < nXtemp)
                {
                    nMaxX = nXtemp;
                    nXtemp = 0;
                }
                WriteLine($"O : {nMaxO+1} , X: {nMaxX+1}");



            }
            */

            //교수님코드
            int evenCt = 0;
            int oddCt = 0;

            int maxEven = 0;
            int maxOdd = 0;


            for (int i = 0; i <10 ; i++)
            {
                int num = rand.Next(2);
                Write(num + " ");
                if (num == 0)
                {
                    oddCt = 0;
                    evenCt++;
                    if (evenCt > maxEven)
                        maxEven = evenCt;
                }
                else
                {
                    evenCt = 0;
                    oddCt++;
                    if (oddCt > maxOdd)
                        maxOdd = oddCt;
                }

            }
            WriteLine(" even :"+ maxEven + " Odd : "+maxOdd);


    

        }
    }
}
