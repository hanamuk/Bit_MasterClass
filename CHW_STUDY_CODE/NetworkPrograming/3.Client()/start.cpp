#include<stdio.h>
#include"App.h"
#include "CMyClient.h"	
int main(void)
{
    App app;
    app.Init();
    app.Run();
    app.Exit();


    /*
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
	
    */


	return 0;
}