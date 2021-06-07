

#pragma once

//Person.h
struct Person
{
	char name[20];
	int age;
	bool gender;
};

#define PACK_PERSON 	1     //이름, 나이, 성별
#define PACK_LISTALL	2     //- 

#define ACK_PERSON_S     11   // 나머지 정보는. echo
#define ACK_PERSON_F     12  //  나머지 정보는 echo 
#define ACK_LISTALL         13 //저장되어 있는 모든 맴버리스트

typedef struct tagPACKETPERSON
{
	int flag;			//1			// 2
	int count;			//1			// 5
	Person per[10];		//0번째배열에 저장		//0~4 인덱스에 저장.
}PACKETPERSON, PACKLISTALL;


PACKETPERSON pack_AddPerson(const char* name, int age, bool gender);
PACKLISTALL pack_ListAll();


