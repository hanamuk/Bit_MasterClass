using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;


//1번.  2021년 
//1월 1일 금요일이다 라는 정보는 알고 있다. 윤년은 고려 x
//달력을 출력하세요 2021년 달력 전부.
//1월달 
//일 월 화 수 목 금 토

//2월달 
//일 월 화 수 목 금 토


enum Day { 일, 월, 화, 수, 목, 금, 토}


namespace _0707_Cshape01
{
    class Program
    {
        
        static void Main(string[] args)
        {
            int nStarDay = 5;
            int nCount = 0;
            List<string> list = new List<string>();
            list = Enum.GetNames(typeof(Day)).ToList();
            int nMaxDay = 30;
         
            WriteLine("2021년 달력");
            
            for (int i = 1; i <= 12; i++) //월 표시/
            {
                WriteLine($"{i}월");
                for (int j = 0; j < 7; j++)
                {
                    if (nStarDay % 7 == 0)
                        nStarDay = 0;
                    Write(list[j].PadLeft(2, ' '));//요일 표시.
                    nStarDay++;
                }

                if (i == 4 || i == 6 || i == 9 || i == 11 || i == 12)
                    nMaxDay = 29;
                if (i == 2)
                    nMaxDay = 27;


                for (int k = 0; k <= nMaxDay; k++)
                {
                    if (k == 0 )
                    {
                        WriteLine();
                        for (int s = 0; s < nStarDay; s++)
                        {
                            if (nStarDay == 7)
                                break;
                            Write(" ".PadLeft(3, ' '));
                            nCount++;
                        }
                            
                    }
                    if (nCount == 7)
                    {
                        WriteLine();
                        nCount = 0;
                    }
                      
                    
                    Write((k+1).ToString().PadLeft(3, ' '));//요일 숫자 표시.
                    nCount++;

                    if (k == nMaxDay)
                        nStarDay = nCount;
                }
                nCount = 0;
                nMaxDay = 30;
                WriteLine();
                WriteLine();

            }

        }
    }
}

// 2번문제 int num = 0x7f3c7b4d;
// 2진수로 리턴하는 함수를 만드세요.
// 사용법 : string s = m1(num);
// s를 출력한 결과 
// 0111 1111 0011 1100 0111 1011 0100 1101
//만약 num이 0x3; 이라면 
//결과는 0000 0000 0000 0000 0000 0000 0011 항상 32자리를 유지. 4자리 마다 공백처리.


//3번 문제 가로 6칸, 세로 5칸의 행렬을 사용한다.
//출력 결과 
/*
 
    # # # # # #
    # . o . o #
    # o o . o #
    # . . o . #
    # # # # # #       이렇게 출력되는데 o가 반드시 랜덤한 위치에 6개 들어가야한다 [배열 사용]
 
 */

//4번 배열을 사용하지 않는다.
/*
    int num = 5; 일떄., num는 무조건 홀수 ,모래시계 모양 그리기.
    O O O O O
    . O O O .
    . . O . .  
    . O O O .
    O O O O O
 */

// 5번 문제.

/*
int [] ar = {50,64,39,66,93,78,0,100};
이차원 배열을 사용한다
히스토그램 작성




 */