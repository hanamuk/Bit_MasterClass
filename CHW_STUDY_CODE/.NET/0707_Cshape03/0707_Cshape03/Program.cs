using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace _0707_Cshape03
{
    class Program
    {
       
        static void Main(string[] args)
        {
            //string[] arH = new string[6];
            //string[] arW = new string[5];
            int nCount = 0;
            Random rand = new Random();
            for (int i = 0; i < 6; i++)
            {
                if (i == 0 || i == 5)
                {
                    for (int s = 0; s < 6; s++)
                    {
                        Write("#");
                    }
                    WriteLine();
                }
                else 
                {
                    Write("#");
                    for (int k = 0; k < 4; k++)
                    {
                        if (rand.Next(0, 2) == 0 && nCount < 4)
                        {
                            Write("O");
                            nCount++;
                            continue;
                        }
                          
                       
                        Write(".");

                    }
                    Write("#");
                    WriteLine();
                }
                




            }


           

        }
    }
}
