using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
namespace _0603_Cshape03
{
    class Tiger
    {

        //public 을주면 read , white 가 모두 열려버린다. 
        //public int num; 
        int num;
        int length;
        // Num을 property라고한다... num의 프로퍼티?
       
       
        //정석
        public int Length
        {
            get { return length; }
            set { length = value; }
        
        }
        public int Num { get; set; }//이처럼 get,set을 C#에서는 제공한다.. 프로퍼티 2


        /* 프로퍼티 3
            public int getNum() { return num; }
            public void setNum(int Num) { this.num = Num; }
        */

        class Program
        {
            static void Main(string[] args)
            {

                ////배열사용 
                //int[] ar1 = new int[3]; //정석
                //int[] ar2 = new int[] { 10, 20, 30 };
                //int[] ar3 = { 10, 20, 30 };
                //WriteLine(ar1);

                ////배열 데이터 테스트할떄 요렇게 하자.
                //for (int i = 0; i < ar2.Length; i++)
                //{
                //    Write(i + " ");
                //}
                //WriteLine();

                ////item , value, data 중 하나를 쓴다.
                //foreach (int item in ar2)
                //{
                //    Write(item + " ");
                //}
                //WriteLine();

                ////공유.. 참조 , 메모리는 한개뿐인데 그것을 가르키는 포인터변수가 한개가 더생긴것. 
                //int[] ar4 = ar2; //얕은복사
                //ar4[0] = 999;
                //WriteLine(ar2[0]);

                //int[] ar5 = (int [])ar2.Clone(); //깊은복사!
                //ar5[1] = 777;
                //WriteLine(ar2[1]);

                ////2차원 배열
                //int[,] ar6 = new int[2,3]; // ==ar[2][3]  한개가 늘어날때마다 차원이 늘어남..
                //ar6[0, 0] = 1;
                //ar6[0, 1] = 2;
                //ar6[0, 2] = 3;
                //ar6[1, 0] = 4;
                //ar6[1, 1] = 5;
                ////ar6[1,2] = 5;

                //foreach (int item in ar6)
                //{
                //    Write(item + " ");
                //}
                //WriteLine();

                //Clear();
                //WriteLine(ar6.Length);
                //WriteLine(ar6.GetLength(0));//2
                //WriteLine(ar6.GetLength(1));//3

                //for (int i = 0; i < ar6.GetLength(0); i++)
                //{
                //    for (int j = 0; j < ar6.GetLength(1); j++)
                //    {
                //        Write(ar6[i, j]+ " ");

                //    }
                //    WriteLine();

                //}

                //string numStr = "";
                //for (int i = 1; i <=5; i++)
                //{
                //    numStr += i.ToString();
                //}
                //WriteLine(numStr);

                /* 시간 클래스
                DateTime newDate = DateTime.Now;
                WriteLine(newDate.Year);
                WriteLine(newDate.Month);
                WriteLine(newDate.Day);
                WriteLine(newDate.Hour);
                WriteLine(newDate.Minute);
                WriteLine(newDate.Second);
                WriteLine(newDate.DayOfWeek); //요일
                WriteLine((int)newDate.DayOfWeek); 
                */


                /* 글자찾기
                 string s = "무궁화 꽃이 피었씁니다.";
                  WriteLine(s.Length);

                  WriteLine(s.IndexOf("꽃이")); //앞에서 부터 검색 해서 몇번쨰에 있는지 리턴
                  WriteLine(s.LastIndexOf("꽃이"));//뒤에서 부터 검색해서 몇번쨰에 있는지 리턴

                  if (s.IndexOf("나무") == -1) //검색실패시-1
                  {
                      WriteLine("못찾음");3
                  }

                  WriteLine(s.Contains("꽃이")); //몇번쨰에 있는지는 리턴안하고, 있는지 없는지 bool만 리턴.

                  WriteLine(s.StartsWith("무궁")); //첫글짜가 무궁으로 시작하는지에 대해 확인/
                  WriteLine(s.EndsWith("니다")); // 끝이  니다 로 끝나는지 ..확인
                  */

                /*Tiger t = new Tiger();
                t.Num = 1000;
                WriteLine(t.Num);   //사용시 맴버변수의 이름의 첫짜가 대문자면 프로퍼디 이다..
                string s = "무궁화";
                WriteLine(s.Length);    
                */

                //밑에 코드는 객체지향 프로그램에서 절대 성립시키지 않는다
                //즉 맴버변수를 public 화 시키지 않는다
                //t.num = 100;
                // t.setNum(100);
                // WriteLine(t.getNum());



                /* -------------------------------------string 에관한 내용

                string s1 = "tiger";
                string s2 = "lion";
                string s3 = s1 + s2;

                //연결함수
                string s4 = "tiger";
                string s5 = "lion";
                string s6 = string.Concat(s4, s5);
                WriteLine(s6);


                string s7 = "무궁화꽃이 피었습니다.";
                WriteLine(s7.Insert(5, "호랑이")); //5번쨰에다가 넣는다.
                WriteLine(s7); //호랑이는 원본데이터를 건들지 않음

                string s8 = s7.Insert(5, "호랑이");

                //문자열 제거(remove, delete, erase)
                WriteLine(s7.Remove(5));    //인덱스 3번이후부터 끝까지 제거
                WriteLine(s7.Remove(1,3));  //스타트 인덱스 부터, 몇개를 제거하는지 

                //검색및 수정
                WriteLine(s7.Replace("꽃","염원"));

                string s10 = "호랑이";
                string s11 = "독수리";
                WriteLine(s10.CompareTo("호랑이")); //같으면 리턴0 다르면 0이 아닌값..
                WriteLine(s11.CompareTo("호랑이")); //같으면 리턴0 다르면 0이 아닌값..
                WriteLine(s10.CompareTo("호랑")); //앞에글자는 같긴한데 전체적으로는 다른 값일때는 1리턴..

                string s12 = null;
                string s13 = "독수리";
                try
                {
                    WriteLine(s12.CompareTo("호랑이")); //s12에 값이 null이면 비교를 할 수가없다..
                }
                catch (Exception e)
                {
                    WriteLine(e+ "exception 발생");
                }            
                WriteLine(string.Compare(s12, s13));//Compare를 사용하면 널 변수도 비교가능..? 널인지 아닌지모를때는 얘를 쓴다..


                WriteLine(string.Compare("Tiger", "tiger", true));// 3째 인자에 true를 넣으면 대소문자를 구분안한다 같으면 0 리턴 bool형 리턴이 아니기떄문에.
                WriteLine(string.Compare("Tiger", "tiger", false));// 3째 인자에 false를 넣으면 대소문자를 구분한다
                WriteLine(string.Compare("Tiger", "tiger"));//디폴트가 false

                WriteLine("Tiger".Equals("Tiger"));

                string s14 = "무공화 꽃이 피었습니다 꽃이";
                //Length 함수가아니다...  
                //그럼 맴버 변수이냐? 아니다..
                // Length는 속성(프로퍼티property) 라고 한다..
                WriteLine(s14.Length);

                */

            }
        }
    }

}