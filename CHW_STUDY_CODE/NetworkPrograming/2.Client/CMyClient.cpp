#include "CMyClient.h"
#include<stdio.h>
#include <winsock2.h>				//�����
#include <ws2tcpip.h>	
#pragma comment(lib, "ws2_32.lib")  //dll import ����

CMyClient::CMyClient() : sock(0)
{
	//1. ���̺귯�� �ʱ�ȭ(Winsock 2.2����)
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("������ ���� �ʱ�ȭ ����\n");
		exit(-1); //���� �ڵ� ��
	}
}

CMyClient::~CMyClient()
{
	//2. ���̺귯�� ����
	WSACleanup();
}
void CMyClient::CreateSocket(const char* ip, int port)
{
	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (sock == INVALID_SOCKET)
		throw "���� ��������";

	SOCKADDR_IN addr;						
	memset(&addr, 0, sizeof(addr));			//API������ ZeroMemory(&addr, 0, sizeof(addr));	addr�� addrũ���� ��ŭ ��� 0���� �����.
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	unsigned int numberaddr;
	inet_pton(AF_INET, ip, &numberaddr);
	addr.sin_addr.s_addr = numberaddr;

	int retval = connect(sock, (SOCKADDR*)&addr, sizeof(addr));
	if (retval == SOCKET_ERROR)
		throw "�����������";

	//���� Tread ���� �ϴ� ��ġ
	CloseHandle(CreateThread(0, 0, RecvThread, (LPVOID)sock, 0, 0));

	printf("\t���Ἲ��");


}

DWORD WINAPI CMyClient::RecvThread(LPVOID value)
{
	SOCKET sock = (SOCKET)value;
	while (true)
	{

		char buf[256];
		int retval = recv(sock, buf, sizeof(buf), 0);
		if (retval == -1 || retval == 0)
		{
			printf("���Ͽ��� or ������ ������\n");
			closesocket(sock);
			return 0;
		}

		buf[retval] = '\0';
		printf(">> [���ŵ�����] : %s\n", buf);

	}
	return 0;
}

void CMyClient::SendData(const char* msg, int lenth)
{
	
	int retval = send(sock, msg, lenth, 0);
	printf("    [�۽�]%dbyte\n", retval);


}



