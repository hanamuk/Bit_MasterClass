#include "pch.h"
#pragma pack(1) //力老刚历 持磊

#include"packet.h"
#include<stdio.h>
#include<string.h>

PACKETPERSON pack_AddPerson(const char* name, int age, bool gender)
{
	PACKETPERSON packet = { 0 };
	packet.flag = PACK_PERSON;
	strcpy_s(packet.per[0].name, sizeof(packet.per[0].name), name);
	packet.per[0].age = age;
	packet.per[0].gender = gender;

	return packet;
}

PACKLISTALL pack_ListAll()
{
	PACKLISTALL packet = { 0 };
	packet.flag = PACK_LISTALL;
	return packet;
}