//packet.h
#pragma once


#define PACK_SHORTMESSAGE		4	//이름. 시간 ,일자 
#define PACK_MEMOMESSAGE		5
#define ACK_SHORTMESSAGE		17	
#define ACK_MEMOMESSAGE			18
struct PACKETSHORTMESSAGE
{
	int flag;
	char name[20];
	char msg[512];
	int hour;
	int min;
	int second;

};
typedef struct PACKETSHORTMESSAGE PACKETMEMO;