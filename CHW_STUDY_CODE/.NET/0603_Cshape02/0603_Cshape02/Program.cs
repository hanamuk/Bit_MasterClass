using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace _0603_Cshape02
{
    class Program
    {
        static void Main(string[] args)
        {
            //연산자 재정의
            string a = "호랑이";
            string b = "코끼리";
            string c = a + b;
            WriteLine(c);

            string d = "독수리";
            string e= "타잔";
            e += d;

            //
            bool b1 = "호랑이"== "호랑이";
            WriteLine(b1);

            //
            string s1 = "tiger";
            string s2 = null;
            //같은결과
            WriteLine(s1 == null ? "널":s1);
            WriteLine(s1?? "널");

            WriteLine(s2 == null ? "널" : s2);
            WriteLine(s2 ?? "널");

            //문자열 >> 숫자변환 char to int
            string s3 = "1000";
            int n3 = Convert.ToInt32(s3);
            WriteLine(n3 + 1);

            int n4 = int.Parse(s3);

            WriteLine(n4 + 1);


            //숫자 >> 문자열
            int n5 = 1234;
            WriteLine(n5.ToString()+ "호랑이");
            WriteLine(123.ToString()); //숫자를 문자열로 꼭넣어야할떄 이런식으로도 사용가능하다.
            WriteLine(n5.ToString("n0")); //n0는 3자리 수마다 , 를넣어주는 옵션이다.
            WriteLine(n5.ToString("x")); //x를 넣으면 16진수로 치환시켜진다.

            int n6 = 15;
            WriteLine(n6.ToString("000000")); // 0의 숫자만큼의 자리수로 출력되는데 빈공간은 0으로 출력한다.

            string s4 = string.Format("호랑이{0}{1}",1000,2000);
            WriteLine(s4);

            string s5 = "   한   글   ";
            Write(s5.TrimStart()); //공백제거, 글짜 앞쪽의 공백 제거
            WriteLine("----");
            Write(s5.TrimEnd()); //글짜 뒤쪽의 공백제거
            WriteLine("----");
            Write(s5.Trim());// 앞뒤 공백 모두 제거... 중간에 공백제거는 기능이없음.

            Clear();
            string s6 = s5.Trim();
            WriteLine(s5);
            WriteLine(s6);


            string s7 = "1";
            string s8 = "10";
            string s9 = "100";
            WriteLine(s7.PadLeft(8));   //총 8 자리로 출력하는데 왼쪽방향에 빈공간을 만들어라.
            WriteLine(s8.PadLeft(8));
            WriteLine(s9.PadLeft(8));

            Write(s7.PadRight(8));   
            Write(s8.PadRight(8));
            Write(s9.PadRight(8));

            WriteLine(s7.PadLeft(8, '#'));   //총 8 자리로 출력하는데 왼쪽방향에 빈공간을 만들어라. 근데 빈공간에 #으로 채워라
            WriteLine(s8.PadLeft(8, '!'));  
            WriteLine(s9.PadLeft(8,'@'));

            string s10 = "TigerWin";
            WriteLine(s10.ToLower());
            WriteLine(s10.ToUpper());



        }
    }
}
