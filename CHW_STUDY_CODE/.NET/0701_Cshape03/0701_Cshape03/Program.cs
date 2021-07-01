using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace _0701_Cshape03
{
    class Star
    {
        public Star(int id, int cnt)
        {
            this.id = id;
            this.cnt = cnt;
        }
        public int id;
        public int Id { get; set; }

        public int cnt;
        public int Cnt { get; set; }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Random ran = new Random();
            ArrayList arr = new ArrayList();
            int ct = 0;

            while (true)
            {
                // 조건에 따라서 랜들하게 데이터 삭제
                for (int i = 0; i < arr.Count;)
                {
                    if (ran.Next(2) == 0)
                    {
                        arr.RemoveAt(i);
                    }
                    else
                    {
                        ((Star)arr[i]).cnt++;
                        i++;
                    }
                }


                // 데이터 추가
                while (arr.Count < 10)
                {
                    arr.Add(new Star(ct++, 0));
                }


                foreach (Star item in arr)
                    Write("{0:d2} ", item.id);
                WriteLine();

                foreach (Star item in arr)
                    Write("{0:d2} ", item.cnt);
                WriteLine();

                // Key 입력조건
                Write("숫자를 입력하세요");
                int input = int.Parse(ReadLine());
                if (input == 99)
                {
                    WriteLine("프로그램을 종료합니다.");
                    break;
                }
            }
        }
    }

}
