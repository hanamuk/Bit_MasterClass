using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.Threading.Tasks;
using static System.Console;
using System.Collections;

namespace Diamond
{
    class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {
                Write("input : ");
                int input = int.Parse(ReadLine());
                WriteLine();
                if (input % 2 == 0)
                {
                    WriteLine("홀수만 입력하세요");
                    continue;
                }

                

                for (int i = 1; i < input;)
                {
                    WriteLine(new string(' ', (input-i)/2) + new string('*', i) + new string(' ', (input - i) / 2));
                    i += 2;
                }

                WriteLine(new string('*', input));

                for (int i = 1; i < input/2 + 1;i++)
                {
                    WriteLine(new string(' ', i) + new string('*', input-(2*i)) + new string(' ', i));
                }
                
            }

        }
    }
}
