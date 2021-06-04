#include <stdio.h>
#include "CMyNet.h"

void testcode1();
void testcode2();

int main()
{
	try
	{
		CMyNet net;
		net.CreateSocket(9000);
		

	}
	catch(const char* msg)
	{
		printf("에러 %s\n", msg);
	}


	return 0;
}

#include <winsock2.h>				//선언부
#include <ws2tcpip.h>				//inet_ntoa 대신 inet_ntop 사용 권장 (v4 -> v6)
#pragma comment(lib, "ws2_32.lib")  //dll import 정보

void testcode1()
{
	//1. 라이브러리 초기화(Winsock 2.2버전)
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("윈도우 소켓 초기화 실패\n");
		exit(-1); //종료 코드 값
	}

	//문자열 주소 -> 4Byte 정수
	const char* ipaddr = "230.200.12.5";
	//int numberaddr = inet_addr(ipaddr);
	unsigned int numberaddr;
	inet_pton(AF_INET, ipaddr, &numberaddr);
	printf("%s -> 0x%08x\n", ipaddr, numberaddr);

	//4Byte 정수 -> 문자열 주소
	//inet_ntoa 대신 inet_ntop 사용 권장 (v4 -> v6)
	IN_ADDR in_addr;
	in_addr.s_addr = numberaddr;
	//printf("0x%08xd -> %s\n", numberaddr, inet_ntoa(in_addr));
	char ipaddr1[30];
	inet_ntop(AF_INET, &(in_addr.s_addr), ipaddr1, INET_ADDRSTRLEN);
	printf("0x%08xd -> %s\n", numberaddr, ipaddr1);

	//2. 라이브러리 해제
	WSACleanup();
}

//바이트 정렬
void testcode2()
{
	//1. 라이브러리 초기화(Winsock 2.2버전)
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("윈도우 소켓 초기화 실패\n");
		exit(-1); //종료 코드 값
	}

	unsigned short us = 0x1234; //2byte
	unsigned long ul = 0x12345678; //4byte
	unsigned short n_us = htons(us);
	unsigned long n_ul = htonl(ul);

	//Host(?) -> Net(Big endian)
	printf("0x%08x -> 0x%08x\n", us, n_us);
	printf("0x%08x -> 0x%08x\n", ul, n_ul);

	//Net(Big endian) -> Host(?)
	printf("0x%08x -> 0x%08x\n", us, ntohs(n_us));
	printf("0x%08x -> 0x%08x\n", ul, ntohl(n_ul));

	//2. 라이브러리 해제
	WSACleanup();
}