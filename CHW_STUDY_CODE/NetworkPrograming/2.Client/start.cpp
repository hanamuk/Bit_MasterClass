#include<stdio.h>
#include "CMyClient.h"	
int main(void)
{
	CMyClient client;
	client.CreateSocket("192.168.0.93", 9000);

    while (true)
    {
        // ����ڿ��� ���ڿ��� �Է�
        char buf[256] = "\0";
        printf(">> ");
        gets_s(buf, sizeof(buf));
        if (strlen(buf) == 0)
            break;
        client.SendData(buf, strlen(buf));
    }
	
	return 0;
}