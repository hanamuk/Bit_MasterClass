using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
namespace designpattern
{
    class test
    {

        private int num;

        //프로퍼티
        public int Num { get; set; }
    }
    class Program
    {
        static void Main(string[] args)
        {
            //엘비스 문법. 숫자 자료형에 null을 넣을수있고
            int? nTemp = 10;
            string a = null;
            //널 체크를 이런 식으로도 할 수 있다.
            WriteLine(nTemp ??3);
            nTemp = null;
            WriteLine(nTemp ?? 3);
            WriteLine(a ??"ㅇㅈ"); //자료형에 따라 널일경우 넣는게 달라지는듯.


            //문자열 바꾸기
            int nCon = 0;
            int nCon2 = 0;
            string strNum = "1222";
            nCon = Convert.ToInt32(strNum);
            nCon2 = int.Parse(strNum);

            WriteLine(nCon +nCon2);
            WriteLine(nCon.ToString("x")); //16진수 치환.

            string s5 = "   한   글   ";
            WriteLine(s5.Trim());   //앞뒤 공백제거
            string s9 = "100";
            WriteLine(s9.PadLeft(8,'#')); //총 8자리, 오른쪽부터 채우고 남는곳은 #으로 

            int[,] ar = new int[2, 3]; //2차원배열 선언 .

            DateTime newDate = DateTime.Now;    //시간 자료형 사용.
            WriteLine(newDate.Year);

            string s = "꽃이 감감찬";
            WriteLine(s.IndexOf("꽃이")); // 꽃이 라는 글자가 몇번째에 있는 지 반환
            WriteLine(s.Contains("꽃이")); //인덱스는 반환안하고 여부만 확인.
            string.Concat(s, s5);//문자열 합치기

            //특정인덱스에 문자 넣고 지우기.
            string s8 = s.Insert(5, "호랑이");
            WriteLine(s.Remove(5));

            //검색및 수정
            WriteLine(s.Replace("꽃", "염원"));

            WriteLine("0번쨰 인자 {0:d4}, 1번쨰 인자 {1:d3}", 10, 20); 
            //자리수를 맞춰주는 기능.. d4는 네자리로 출력해라 / 남는공간은 0으로 라는뜻


        }
    }
}
