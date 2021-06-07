

#pragma once

//Person.h
struct Person
{
	char name[20];
	int age;
	bool gender;
};

#define PACK_PERSON 	1     //�̸�, ����, ����
#define PACK_LISTALL	2     //- 

#define ACK_PERSON_S     11   // ������ ������. echo
#define ACK_PERSON_F     12  //  ������ ������ echo 
#define ACK_LISTALL         13 //����Ǿ� �ִ� ��� �ɹ�����Ʈ

typedef struct tagPACKETPERSON
{
	int flag;			//1			// 2
	int count;			//1			// 5
	Person per[10];		//0��°�迭�� ����		//0~4 �ε����� ����.
}PACKETPERSON, PACKLISTALL;


PACKETPERSON pack_AddPerson(const char* name, int age, bool gender);
PACKLISTALL pack_ListAll();


