using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
namespace _0707_Cshape04
{
    class Program
    {

        static void Main(string[] args)
        {
            int input;


            while (true)
            {
                Write("숫자를 입력하세요:");
                int a = int.Parse(ReadLine());
                if (a % 2 == 0)
                {
                    WriteLine("홀수만 입력");
                    continue;

                }
                for (int i = 0; i < a; i += 2)
                {
                    for (int j = 0; j < i; j += 2)
                    {
                        Write(".");
                    }
                    for (int k = 0; k < a - i; k++)
                    {
                        Write("O");
                    }
                    for (int j = 0; j < i; j += 2)
                    {
                        Write(".");
                    }
                    WriteLine();
                }
                for (int i = a - 2; i > 0; i -= 2)
                {
                    for (int j = 1; j < i; j += 2) 
                    {
                        Write(".");
                    }
                    for (int k = 0; k <= a - i; k++)
                        Write("O");
                    for (int j = 1; j < i; j += 2)
                    {
                        Write(".");
                    }
                    WriteLine();
                }
            }


        }



    }
    
}
