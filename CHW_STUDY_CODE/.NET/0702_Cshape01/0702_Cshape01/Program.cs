using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
namespace _0702_Cshape01
{
    class Program
    {
        /* 싸인 코싸인
        static double DegreeToRadian(double degree)
        {
            return Math.PI * degree / 180.0;

        }
        */
        static void Main(string[] args)
        {
            /*
             수학공식
            //30도(degree)가 아니고 30radian 이다.. 3.14*30.0/180.0으로 넣어야 30도에 대한 값이 나온다..
            WriteLine(Math.Sin(DegreeToRadian(30.0)));

            double sum = 0.0f;
            for (int i = 0; i < 100; i++)
            {

                sum += 0.1f;
            }

            //double형 ? 은 이렇게 등가비교를 하면 안된다.
            if (sum == 10.0)
            {
                WriteLine("호랑이");
            }
            WriteLine(sum);

            // x' = cos0 * x - sin0 * y
            // y' = sin0 * x + cos0 * y
            */

            /*
            //--------------------------------------- dictionay
            //쌍을 이룬다
            //{1,2} 1:key, 2:value , 키값은 중복불가 , hash가 붙으면 딕셔너리/.
            Hashtable user = new Hashtable();
            user.Add("1", "호랑이");
            user.Add("2", "독수리");
            user.Add("3", "강남콩");
            WriteLine(user.Count);

            // 제거는 반드시 키를 이용하여 제거
            user.Remove("2");
            WriteLine(user.Count);
            //user.Clear();
            //WriteLine(user.Count);

            //검색
            WriteLine(user.Contains("1"));
            WriteLine(user.Contains("2"));

            //Read
            WriteLine(user["1"]);
            WriteLine(user["4"]);

            user.Add("4", "떡상가즈아");
            ICollection keys = user.Keys;
            ICollection values = user.Values;

            foreach (var key in keys)
            {
                Write(key+" ");
            }WriteLine();

            foreach (var value in values)
            {
                Write(value + " " );
            }
            WriteLine();

            // exception 발생
            //user.Add(null, "강남콩");

            //갱신
            user["1"] = "코끼리1";
            user["2"] = "코끼리2";


            foreach (var value in values)
            {
                Write(value + " ");
            }
            WriteLine();

            //
            WriteLine(user["2"].ToString());
            string s = user["2"].ToString();
            WriteLine(s);

            //for문에서 딕셔너리의 내용을 보고싶으면 DictionaryEntry로 받아야한다/.
            foreach (DictionaryEntry item in user)
            {
                WriteLine($"{item.Key}:\t{ item.Value}");
            }
            Clear();

            foreach (var item in user.Values)
            {
                WriteLine();
            }

            WriteLine(user.ContainsValue("코끼리2"));
            WriteLine(user.ContainsValue("코끼리3"));

            // exception 발생 , 키값은 고유해야한다.
            //user.Add("1", "호랑이4");

            */

            /*
            //SortedList---------------------------------------------------------
            //사용법은 딕셔너리와 유사하다., 딕셔너리인데 넣을떄 순서를 검색해서 정렬된다.
            SortedList s1 = new SortedList();
            s1.Add("apple", "호랑이1");
            s1.Add("orange", "호랑이2");
            s1.Add("banana", "호랑이3");

            foreach (DictionaryEntry item in s1)
            {
                WriteLine($"{item.Key}:\t{ item.Value}");
            }

            s1.Add("kiwi", "키위");
            //s1.Add("kiwi", "키위");
            s1["kiwi"] = "키위2";//갱신

            //인덱스를 사용해서..set
            s1.SetByIndex(1,"독수리");

            s1.RemoveAt(0);
            
            foreach (DictionaryEntry item in s1)
            {
                WriteLine($"{item.Key}:\t{ item.Value}");
            }

            WriteLine();
            WriteLine(s1.GetByIndex(0));

            IList kets = s1.GetKeyList();
            IList values = s1.GetValueList();
            foreach (var item in values)
            {
                WriteLine(item);

            }
            */

            /*
            //queue 큐 ----------------------------------------

            Queue q = new Queue();
            q.Enqueue("Msg1");
            q.Enqueue("Msg2");
            q.Enqueue("Msg3");
            WriteLine(q.Count);

            //실제로 데이터를 가져온다.
            while (q.Count != 0)
            {
                string s = q.Dequeue().ToString();
                WriteLine(q.Count +" " +  s);
            }
            WriteLine();


            q.Enqueue("Msg1");
            q.Enqueue("Msg2");
            q.Enqueue("Msg3");

            //데이터를 뽑기전에 확인 하는 코드
            string s2 = q.Peek().ToString();
            WriteLine(q.Count + " "+ s2);
            //큐를 비운다.
            //q.Clear();
            WriteLine(q.Count);

            //있는지 없는지 확인
            WriteLine(q.Contains("Msg3"));
            WriteLine(q.Contains("Msg4"));

            WriteLine("------------------------------");
            object[] ar = q.ToArray();
            WriteLine(q.Count);

            foreach (string item in ar)
            {
                Write(item+ " ");
            }WriteLine();

            q.Clear();

            ArrayList al = new ArrayList();
            al.Add("Msg 10");
            al.Add("Msg 20");
            al.Add("Msg 30");
            Queue q1 = new Queue(al);
            WriteLine(q1.Count);
            */


            /* stack------------------------------------------
             ArrayList al = new ArrayList();
             al.Add(10);
             al.Add(20);
             al.Add(30);

             Stack st = new Stack(al);
             WriteLine(st.Count);
             st.Push(40);
             st.Push(50);
             WriteLine(st.Count);

             while (st.Count != 0)
             {
                 int data = (int)st.Pop();
                 WriteLine(data);

             }
             WriteLine(st.Count);

             st.Push(10);
             st.Push(20);
             st.Push(30);
             int num = (int)st.Peek();
             WriteLine(num);
             WriteLine(st.Count);

             Clear();
             object[] ar2 = st.ToArray();
             foreach (int item in ar2)
             {
                 Write(item + " ");
             }WriteLine();

             WriteLine(st.Count);

             */

            /*
            //BitArray-------------------------------------------
            BitArray ba = new BitArray(new bool[] { true, false, true, false });

            foreach (bool item in ba)
            {
                WriteLine(item);
            }
            //안에 내용을 전부 뒤집어준다.
            ba.Not();
            WriteLine();
            foreach (bool item in ba)
            {
                WriteLine(item);
            }

            Clear();
            BitArray a = new BitArray(new bool[] { false, false, true, true });
            BitArray b = new BitArray(new bool[] { false, true, false, true });

            //a와 b를 연산해서 a 에 집어 넣는다..
            a.And(b);   //OR, AND ,XOR 전부 제공..

            foreach (bool item in a)
            {
                WriteLine(item);
            }
            */

           
        }
    }
}
