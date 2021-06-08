//packet.h
#pragma once

#define PACK_NEWMEMBER	1     //id ,pw, name
#define PACK_LOGIN				2
#define PACK_LOGOUT 3


#define ACK_NEWMEMBER_S     11   // 나머지 정보는. echo
#define ACK_NEWMEMBER_F     12  //  나머지 정보는 echo 
#define ACK_LOGIN_S			13		//id ,pw, name
#define ACK_LOGIN_F		14		//id ,pw, name

#define ACK_LOGOUT_S			15	
#define ACK_LOGOUT_F			16	

struct PACKETNEWMEMBER
{
	int flag;
	char id[10];
	char pw[10];
	char name[20];
};

typedef PACKETNEWMEMBER PACKLOGIN;

struct PACKLOGOUT
{
	int flag;
	char id[10];

};
