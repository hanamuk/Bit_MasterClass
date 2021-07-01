using System;
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

            int num = 5;
            int nMid = (int)Math.Truncate((double)num/2);
            int space = nMid;
            int nCount = 1;

            Write("*", 50);

            for (int x = 0; x < num; x++)
            {
               
                Write(" ", space);
                Write("*", nCount);
                WriteLine();
                nCount+=2;
                if (space == 0)
                {
                    space++;
                    nCount -= 2;
                }
                   
                space--;


            }
            


        }
    }
}
