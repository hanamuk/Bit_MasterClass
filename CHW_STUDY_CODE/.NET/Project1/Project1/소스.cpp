#include <stdio.h>
#include <stddef.h>
#include <iostream>

int sum(int num);
void seven();
void show();
void change();
void big();
int arr[3][3] = { {20,21,22} ,{23,24,25},{26,27,28} };
int main(void)
{
    show();

    printf("\n\n");
    change();
    show();

    printf("\n\n");
    change();
    show();

    printf("\n\n");
    change();
    show();

    printf("\n\n");
    change();
    show();

    printf("\n\n");
    big();
    show();


}
int sum(int num)
{
    int ret = 0;
    for (int i = 1; i <= num; i++)
    {
        ret += i;
    }
    return ret;
}

void seven()
{
    int s = 7;
    for (int i = 1; i <= 9; i++)
    {
        printf("%d * %d = %d\n", s, i, s * i);
    }
}
void show()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d", arr[i][j]);
        }printf("\n");
    }
}

void change()
{
    int arr[3][3] = { {20,21,22} ,{23,24,25},{26,27,28} };
    int temp[3][3] = { 0, };

    // ¹è¿­ 90µµ È¸Àü
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            temp[i][j] = arr[3 - j - 1][i];



}
void big(void)
{
   
    while (true)
    {
        int count = 0;
        int arr[10] = { 0, };
        if (count == 10000) break;
        int val = rand() % 99;
        val = val / 10;
        if (val < 1)
            val = 0;
        arr[val] += 1;
        count++;
    }
    
    for (int i = 1; i < 10; i++)
    {
        printf("<%d0~%d9> : %d°³\n", i, i, arr[i]);
    }
}


#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    char arr1[6][6];
    int arr2[16];
    int random = 0;
    srand(time(NULL));

    for (int i = 0; i < 16; i++)
    {
        arr2[i] = i;
    }

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (i == 0 || i == 5 || j == 0 || j == 5)
            {
                arr1[i][j] = '*';
                printf("%c ", arr1[i][j]);
            }
            else
            {
                while (1)
                {
                    random = rand() % 16;
                    if (arr2[random] != -1)
                    {
                        arr1[i][j] = arr2[random];
                        printf("%d ", arr1[i][j]);
                        arr2[random] = -1;
                        break;
                    }
                }
            }
        }
        printf("\n");
    }
}



#include <stdio.h>
#include <stdlib.h>

struct RECT
{
    long x1, x2, y1, y2;
};

void Func(RECT input1, RECT input2, RECT result)
{
    input1.x1 = 50, input1.y1 = 100;
    input1.x2 = 100, input1.y2 = 200;
    input2.x1 = 75, input2.y1 = 125;
    input2.x2 = 125, input2.y2 = 200;
    result.x1, result.y1;
    result.x2, result.y2;

    for (int i = 0; i < 2; i++)
    {
        if (i >= 1)
        {
            if (input1.x1 <= input2.x1 || input1.x2 >= input2.x2)
                if (input1.y1 <= input2.y1 || input1.y2 >= input2.y2)
                {
                    result.x1 = input2.x1;
                    result.y1 = input2.y1;
                    result.x2 = input2.x1;
                    result.y2 = input2.y2;
                }
            if (input2.x1 < input1.x1 || input2.x2 > input1.x2)
            {
                if (input2.y1 < input1.y1 || input2.y2 > input1.y2)
                {
                    result.x1 = input2.x1;
                    result.y1 = input2.y1;
                    result.x2 = input2.x1;
                    result.y2 = input2.y2;
                }
            }
            if (input2.x1 < input1.x1 || input2.x2 > input1.x1)
            {
                if (input2.y1 > input1.y1 || input2.y2 < input1.y1)
                {
                    result.x1 = input2.x1;
                    result.y1 = input2.y1;
                    result.x2 = input2.x1;
                    result.y2 = input2.y2;
                }
            }
            else
            {
                printf("°ãÃÄÁø ÁÂÇ¥ x");
                break;
            }

            printf("°ãÃÄÁø ÁÂÇ¥ (%d, %d), (%d, %d).\n", result.x1, result.y1, result.x2, result.y2);
        }

    }

}
int main(void)
{
    RECT rect1 = { 0. }, rect2 = { 0. }, rect3 = { 0. };
    Func(rect1, rect2, rect3);

}
double exp(double x, int n) { // x´Â ¹Ø, nÀº Áö¼öÀÌ´Ù.
    int i;
    double r = 1.0;
    for (i = 0; i < n; i++)
        r = r * x;
    return (r);
}
