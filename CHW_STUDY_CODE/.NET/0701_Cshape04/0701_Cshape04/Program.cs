using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

//네임스페이스 사용 ------------------------------------
//using fs =FirstNamespace;
//using ss =SecondNamespace;


//namespace FirstNamespace
//{

//    class test
//    {
//        public void f1()
//        {
//            WriteLine(1);
//        }

//    }

//}

//namespace SecondNamespace
//{
//    class test
//    {
//        public void f1()
//        {
//            WriteLine(2);
//        }

//    }
//}


namespace _0701_Cshape04
{
    class Program
    {
        static void Main(string[] args)
        {
            //1 네임스페이스 사용 ----------------------------------------
            //fs.test t1 = new fs.test();
            //t1.f1();

            //ss.test t2 = new ss.test();
            //t2.f1();

            //내 코드 다이아 그리기------------------------------------------
            //int num = 5;
            //int nMid = (int)Math.Truncate((double)num/2);
            //int space = nMid;
            //int nCount = 1;

            //Write("*", 50);

            //for (int x = 0; x < num; x++)
            //{

            //    Write(" ", space);
            //    Write("*", nCount);
            //    WriteLine();
            //    nCount+=2;
            //    if (space == 0)
            //    {
            //        space++;
            //        nCount -= 2;
            //    }

            //    space--;


            //}

            //현준이형 다이아 그리기 --------------------------------------
            //while (true)
            //{
            //    Write("입력(99종료) : ");
            //    int input = int.Parse(ReadLine());

            //    if (input  == 99)
            //        break;


            //    for (int i = 1; i < input;)
            //    {
            //        WriteLine(new string(' ', (input - i) / 2) + new string('*', i) + new string(' ', (input - i) / 2));
            //        i += 2;
            //    }

            //    WriteLine(new string('*', input));

            //    for (int i = 1; i < input / 2 + 1; i++)
            //    {
            //        WriteLine(new string(' ', i) + new string('*', input - (2 * i)) + new string(' ', i));
            //    }

            //}

            while (true)
            {

                Write("입력(99종료) : ");
                int input = int.Parse(ReadLine());

                if (input == 99)
                    break;

                int num = 9;
                int q = num / 2;
                for (int i = -q; i <= q; i++)
                {
                    for (int j = -q; j <= q; j++)
                    {
                        int ii = Math.Abs(i);
                        int jj = Math.Abs(j);

                        Write("{0} ", (ii + jj <= q) ? "*" : " ");

                    }
                    WriteLine();
                }



            }


        }
           
    }
}
