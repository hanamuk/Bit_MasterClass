using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace _0707_Cshape05
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] ar = { 50, 64, 39, 66, 93, 78, 0, 100 };
            int[] arr = new int[ar.Length];
            string[,] array = new string[10, ar.Length];
            int num = 0;

            for (int i = 0; i < ar.Length; i++)
            {
                arr[i] = ar[i] / 10;
            }
            for (int i = 0; i < ar.Length; i++)
            {
                Write(arr[i] + " ");
            }
            WriteLine();
            WriteLine();
            for (int i = 10; i > 0; i--)
            {
                for (int j = 0; j < arr.Length; j++)
                {
                    num = arr[j];
                    if (num >= i)
                    {
                        Write("0 ");
                    }
                    else
                    {
                        Write(". ");
                    }
                }
                WriteLine();
            }
        }

    }
}
