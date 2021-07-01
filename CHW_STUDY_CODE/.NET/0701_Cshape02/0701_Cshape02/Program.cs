using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;


namespace _0701_Cshape02
{
   

    class Program
    {
        static void Main(string[] args)
        {
            //int input;
            //input = ReadLine();

            //int input;
            //input = int.Parse(ReadLine());
            //WriteLine(input+ 100);


            //int.Parse 와 Convert 차이점!-------------------------------
            //WriteLine(1);
            //int b = Convert.ToInt32(null);
            //WriteLine(b);
            //WriteLine(2);
            //int a = int.Parse(null);   //Convert와 차이점은 값이 null일떄 parse는 exception이 발생하고 컨버터는 발생안한다!
            //WriteLine(3);

            //out설명 필요.
            //int c;
            //Int32.TryParse("123", out c);
            //WriteLine(c);
            // Int32.TryParse(null, out c);
            // WriteLine(c);

            //ArrayList al = new ArrayList();
            //al.Add(1);
            //al.Add(1);
            //al.Add(2);
            //al.Add(2);
            //al.Add(3);
            //al.Add(3);
            //al.Add(4);
            //al.Add(4);

            //for (int i = 0; i < al.Count;)
            //{
            //    if ((int)al[i] % 2 == 0)
            //    {
            //        al.RemoveAt(i);
            //    }
            //    else
            //    {
            //        //i++; //아래꺼와 속도차이가 10배 난다. iterator논리가 들어갈때.. 리스트를 사용할떄 ++i가 훨씬 빠르다.ㅇㄹ
            //        ++i;
            //    }

            //}
            //foreach (var item in al)
            //{
            //    Write(item + " ");
            //}
            //WriteLine();


            //내코드---------------------------------------------------------
            //ArrayList arList = new ArrayList();
            //ArrayList arShowList = new ArrayList();
            //Random rand = new Random();
            //int nCount = 0;

            //while (true)
            //{

            //    int nEnd;
            //    Write("숫자를 입력하세요 99가 입력되면 종료입니다. : ");
            //    nEnd = int.Parse(ReadLine());

            //    if (nEnd == 99)
            //        return;



            //    int nRand = rand.Next() % 10;

            //    if (arList.Count == 0)
            //    {
            //        for (int i =0; i < 10; i++)
            //        {
            //            Write("{0,3} ", nCount);
            //            arShowList.Add(nCount);
            //            arList.Add(0);
            //            nCount ++;
            //        }
            //        WriteLine();

            //        foreach (var item in arList)
            //        {
            //            Write("{0,3} ",item);
            //        }
            //        WriteLine();

            //    }
            //    else
            //    {
            //        for (int i = 0; i < nRand; i++)
            //        {
            //            int nDelRand = rand.Next() % arList.Count;
            //            arList.RemoveAt(nDelRand);
            //            arShowList.RemoveAt(nDelRand);
            //        }

            //        for (int i =0 ; i < nRand; i++)
            //        {
            //            arList.Add(0);
            //            arShowList.Add(nCount);
            //            nCount++;
            //        }

            //        for (int i = 0; i < 10; i++)
            //        {
            //            Write("{0,3} ", arShowList[i]);

            //        }
            //        WriteLine();
            //        for (int i = 0; i < 10; i++)
            //        {
            //            Write("{0,3} ", arList[i]);

            //        }
            //        WriteLine();

            //    }




            //}


            //강사님 코드---------------------------------------------
            //Random random = new Random();
            //// ex 1)
            //for (int i = 0; i < 10; i++)
            //{
            //    int num = (new Random()).Next();
            //    //WriteLine(random.Next());
            //}
            //WriteLine();
            //// ex 2)
            //for (int i = 0; i < 10; i++)
            //{
            //    WriteLine(random.Next(2));
            //}
            //WriteLine();
            //// ex 3)
            //for (int i = 0; i < 10; i++)
            //{
            //    WriteLine(random.Next(3, 5));
            //}
            //WriteLine();

            //// ex 4) Red : 0~255
            //for (int i = 0; i < 10; i++)
            //{
            //    WriteLine(random.NextDouble());
            //}
            //byte[] ar = new byte[10];
            //random.NextBytes(ar);
            //foreach (var item in ar)
            //{
            //    Write(item + " ");
            //}
            //WriteLine();



            ////하는방법 2------------------------------------------
            //ArrayList al = new ArrayList();
            //Random random = new Random();
            //int nCount = 0;
            //int nId = 0;
            //while (true)
            //{
            //    WriteLine();
            //    int nEnd;
            //    Write("숫자를 입력하세요 99가 입력되면 종료입니다. : ");
            //    nEnd = int.Parse(ReadLine());



            //내꺼 코드 2----------------------------------------------------
            //    if (nEnd == 99)
            //        break;

            //    if (nCount == 0)
            //    {
            //        for (int i = 0; i < 10; i++)
            //            al.Add(new Star(i, 0));
            //        foreach (Star item in al)
            //        {
            //            Write("{0,3}", item.getId().ToString());
            //        }
            //        WriteLine();


            //        foreach (Star item in al)
            //        {
            //            Write("{0,3}", item.getCount().ToString());
            //        }
            //        WriteLine();

            //        nCount++;
            //        nId = 10;

            //    }
            //    else
            //    {
            //        int nRand = random.Next(10);

            //        for (int i = 0; i < nRand; i++)
            //        {
            //            int nDrand = random.Next(al.Count);
            //            al.RemoveAt(nDrand);

            //        }
            //        for (int i = 0; i < nRand; i++)
            //        { 
            //            al.Add(new Star(nId, 0));
            //            nId++;

            //        }

            //        foreach (Star item in al)
            //        {
            //            Write("{0,3}", item.getId().ToString());
            //        }
            //        WriteLine();


            //        foreach (Star item in al)
            //        {
            //            Write("{0,3}", item.getCount().ToString());
            //        }
            //        WriteLine();
            //    }

            //}

            //강사님 코드 2------------------------------------------------------
           
        }

    }
}


//