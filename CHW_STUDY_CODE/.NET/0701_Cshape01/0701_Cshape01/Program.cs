using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace _0701_Cshape01
{
    class Tiger {
        string name;
        public string Name { get; set; }

        int age;
        public int Age { get; set; }
      

        public Tiger(string name, int age)
        {
            this.name = name;
            this.age = age;
        }
        public void showData()
        {
            WriteLine(name + " " + age);
        }
       
    }
    class Program
    {
        static void Main(string[] args)
        {
            // 배열 최대 값 서치-----------------------------------------------
            //int[] ar1 = new int[] { 1, 3, 5, 7, 9, 13, 3, 6, 4, 2 };
            //int max = int.MinValue;
            //WriteLine(max);

            //foreach (var item in ar1)
            //{
            //    max = item > max ? item : max;
            //}
            //WriteLine("max = {0}", max);

            //for문 -----------------------------------------------------
            ////for문에 형식 1 
            //for (int i = 0; i < 10; i++)
            //{

            //}

            ////for문에 형식 2
            //for (int i = 1; i <= 10; i++)
            //{

            //}

            ////for문에 형식 3(n* 2 + 1  만큼 반복, 음수양수 0 포함해서 돌릴떄 사용, 좌표 영역에서 사용)
            //for (int i = -5; i <= 5; i++)
            //{

            //}

            //exception 처리------------------------------------
            //int v = 4;
            //int d = 0;
            //int c;
            //try
            //{
            //    c = v / d;
            //}
            //catch (Exception e)
            //{
            //   WriteLine(e.Message);
            //    c = 10;
            //}


            //WriteLine("{0}", c);
            //WriteLine($"{c}");


            //컬렉션 예제 1---------------------------------------------------
            //ArrayList al = new ArrayList();
            //CRUD 중에서 Create(add, insert, create를 이름으로 나타낼 수 있다.)--------------------------
            //al.Add("호랑이");
            //WriteLine(al.Count);
            //al.Add("코끼리");
            //al.Add("독수리");
            //WriteLine(al.Count);
            //for (int i = 0; i < 10; i++)
            //{
            //    al.Add(i * 10 + i+"");

            //}
            //WriteLine(al.Count);
            //al.Add(10);
            //al.Insert(1, 99);   //앞에 수는 저장할 인덱스.
            //foreach (var item in al)
            //{
            //    Write(item + " ");
            //}
            //WriteLine();

            //CRUD 중에서 Read---------------------------------------------------
            //foreach (var item in al)
            //    Write(item+ " ");
            //WriteLine();

            //컬렉션 실무 일반 1---------------------------------------------------
            // ArrayList al = new ArrayList();
            //방법 1
            //Tiger t = new Tiger("호랑이", 10);
            // al.Add(t);
            ////방법 2
            //al.Add(new Tiger("독수리", 20));
            //al.Add(new Tiger("코끼리", 30));
            //WriteLine(al.Count);
            //foreach (Tiger item in al)
            //{
            //    item.showData();
            //}WriteLine();

            //ArrayList al = new ArrayList();
            // al.Add(10);
            //al.Add(30);
            //al.Add(20);
            //WriteLine(al.Add(30));  //넣었을떄 인덱스번호 리턴.
            //int pos = al.Add(40);
            //WriteLine(pos);

            //CRUD delete------------------------------
            //al.Remove(30); //처음찾은 30 하나만 제거하고 끝난다
            //foreach (var item in al)
            //{
            //    Write(item + " ");
            //}WriteLine();

            //al.RemoveAt(10);    //유효범위를 벗어나면 exception이 발생된다.
            //foreach (var item in al)
            //{
            //    Write(item + " ");
            //}
            //WriteLine();

            //CRUD , Update -----------------------------------------------------
            //al[0] = 88;
            //foreach (var item in al)
            //{
            //    Write(item + " ");
            //}
            //WriteLine();
            ////al.Clear();
            //WriteLine(al.Count);

            //WriteLine(al.Contains(88));     //문자열 검색있는지 여부.. 
            //WriteLine(al.Contains(77)); 

            //WriteLine(al.IndexOf(88)); //찾으면 0
            //WriteLine(al.IndexOf(77));  //못찾으면 -1 리턴

            // int num = 10;
            // ArrayList arrNum = new ArrayList(10) { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
            // ArrayList arrAge = new ArrayList(10) { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

            // for (int i = 0; i < arrNum.Count; i++)
            // {
            //     Write("{0, 4}", arrNum[i]);
            // }
            // WriteLine();
            // for (int i = 0; i < arrAge.Count; i++)
            // {
            //     Write("{0,4}", arrAge[i]);
            // }
            // WriteLine();


            // while (true)
            //{
            //    int inputNum;
            //    Write("숫자를 입력하세요 : ");
            //    inputNum = int.Parse(ReadLine());
            //    if (inputNum == 99) { break; }

            //    ArrayList numTemp = new ArrayList();
            //    ArrayList ageTemp = new ArrayList();
            //    Random random = new Random();

            //    for (int i = 0; i < arrNum.Count; i++)
            //    {   
            //        int rand = random.Next(1, 3);
            //        if(rand == 1)
            //        {
            //            numTemp.Add(arrNum[i]);
            //            ageTemp.Add((int)arrAge[i] + 1);
            //        }
            //    }

            //    for (int i = 0; i < numTemp.Count; i++)
            //    {
            //        arrNum[i] = numTemp[i];
            //        arrAge[i] = ageTemp[i];
            //    }

            //    for(int i = numTemp.Count; i<arrNum.Count; i++)
            //    {
            //        arrNum[i] = num;
            //        arrAge[i] = 0;
            //        num++;
            //    }

            //    for (int i = 0; i < arrNum.Count; i++)
            //    {
            //        Write("{0, 4}", arrNum[i]);
            //    }
            //    WriteLine();
            //    for (int i = 0; i < arrAge.Count; i++)
            //    {
            //        Write("{0, 4}", arrAge[i]);
            //    }
            //    WriteLine();

            //}

       
        }

    }
}
