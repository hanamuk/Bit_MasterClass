using System;
using System.Collections.Generic;
using System.Linq;
// 2번문제 int num = 0x7f3c7b4d;
// 2진수로 리턴하는 함수를 만드세요.
// 사용법 : string s = m1(num);
// s를 출력한 결과 
// 0111 1111 0011 1100 0111 1011 0100 1101
//만약 num이 0x3; 이라면 
//결과는 0000 0000 0000 0000 0000 0000 0011 항상 32자리를 유지. 4자리 마다 공백처리.




using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace _0707_Cshape02
{
    class Object
    {
        private int num= 0x3;
        
        
        public int HexToBinary()
        {
            
            string result = Convert.ToString(num, 2).PadLeft(32, '0');
            int count = (result.Length / 4)-1;
            int mul = 4;

            for (int i = 0; i <= count; i++) //0~ 6
            {
                if (i == 0)
                    result = result.Insert(i * mul, " ");
                else
                    result = result.Insert(i * mul + i, "\t");
               
            }

            WriteLine(result);
            return 0;
        }

    }

    class Program
    {
        static void Main(string[] args)
        {
            Object obj = new Object();

            obj.HexToBinary();

           
        }
    }
}
