//�����Ʃ����� ����ü�� ���鋚 4����Ʈ�� �޸𸮸� �����. ����ü �ɹ��� ������ ��Ŀ� ���� ����ü ũ�Ⱑ �޶�����.
// char�� ���� ������ 1ĭ�� ä������ 3����Ʈ�� ���µ� �״��� int���� �ִ´ٸ� ����ü �� �� 8����Ʈ�� �ȴ�
//�̷��� ������ �ذ��ϱ� ���ؼ� ��Ʈ��ũ����� �Ҷ��� �޸𸮸� 1����Ʈ�� �ױ����ؼ� #pragma pack(1)������.
#pragma pack(1) //���ϸ��� ����

#include"packet.h"
#include<stdio.h>
#include<string.h>
NEWMEMBER pack_NewMember(const char* name, const char* id, const char* pw, int age)
{
	NEWMEMBER packet = { 0 };
	packet.flag = PACK_NEWMEMBER;
	strcpy_s(packet.name, sizeof(packet.name), name);
	strcpy_s(packet.id, sizeof(packet.id), id);
	strcpy_s(packet.pw, sizeof(packet.pw), pw);
	packet.age = age;
	return packet;
}

LOGIN pack_Login(const char* id, const char* pw)
{
	LOGIN packet = { 0 };
	packet.flag = PACK_LOGIN;
	strcpy_s(packet.id, sizeof(packet.id), id);
	strcpy_s(packet.pw, sizeof(packet.pw), pw);
	return packet;
}

LOGOUT  pack_Logout(const char* id)
{
	LOGOUT packet = { 0 };
	packet.flag = PACK_LOGOUT;
	strcpy_s(packet.id, sizeof(packet.id), id);
	return packet;
}

