//packet.h
#pragma once


#define PACK_NEWMEMBER	1     //id ,pw, name
#define PACK_LOGIN				2
#define PACK_LOGOUT		3
#define PACK_SHORTMESSAGE		4	//�̸�. �ð� ,���� 
#define PACK_MEMOMESSAGE		5

#define ACK_NEWMEMBER_S     11   // ������ ������. echo
#define ACK_NEWMEMBER_F     12  //  ������ ������ echo 
#define ACK_LOGIN_S			13		//id ,pw, name
#define ACK_LOGIN_F		14		
#define ACK_LOGOUT_S			15	
#define ACK_LOGOUT_F			16	
#define ACK_SHORTMESSAGE		17	
#define ACK_MEMOMESSAGE		18

struct PACKETNEWMEMBER
{
	int flag;
	char id[10];
	char pw[10];
	char name[10];

	static PACKETNEWMEMBER CreatePacket(const char* _name, const char* _id, const char* _pw);
	static PACKETNEWMEMBER CreatePacket( const char* _id, const char* _pw);

};

typedef struct PACKETNEWMEMBER PACKLOGIN;  //PACKETNEWMEMBER�� �̸� 2�� ��밡��.


struct PACKLOGOUT
{
	int flag;
	char id[10];
	static PACKLOGOUT CreatePacket(const char* _id);
};

struct PACKETSHORTMESSAGE
{
	int flag;
	char name[20];
	char msg[512];
	int hour;
	int min;
	int second;

	static PACKETSHORTMESSAGE CreatePacket(const char* _name, const char* msg);
	static PACKETSHORTMESSAGE CreatePacket(const char* _name, const char* msg, bool dummy); //dummy�� �����ϱ�����.
};

typedef struct PACKETSHORTMESSAGE PACKETMEMO;