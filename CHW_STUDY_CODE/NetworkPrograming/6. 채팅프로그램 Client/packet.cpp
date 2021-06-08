//packet.cpp //모든소스파일은 pch.h파일을 제일먼저 include

#include "pch.h"				//pre compile header 자신만의 클래스를 넣을떄 반드시 얘가 있어야하고 맨위에 있어야한다
#include "packet.h"

PACKETNEWMEMBER PACKETNEWMEMBER::CreatePacket(const char* _name, const char* _id, const char* _pw)
{
	PACKETNEWMEMBER packet;

	packet.flag = PACK_NEWMEMBER;
	strcpy_s(packet.id, sizeof(packet, id), _id);
	strcpy_s(packet.pw, sizeof(packet, id), _pw);
	strcpy_s(packet.name, sizeof(packet, id), _name);
	return packet;
}

PACKETNEWMEMBER PACKETNEWMEMBER::CreatePacket(const char* _id, const char* _pw)
{
	PACKETNEWMEMBER packet;

	packet.flag = PACK_LOGIN;
	strcpy_s(packet.id, sizeof(packet, id), _id);
	strcpy_s(packet.pw, sizeof(packet, id), _pw);
	return packet;
}

PACKLOGOUT PACKLOGOUT:: CreatePacket(const char* _id)
{
	PACKLOGOUT packet;
	packet.flag = PACK_LOGOUT;
	strcpy_s(packet.id, sizeof(packet, id), _id);
	return packet;

}

PACKETSHORTMESSAGE PACKETSHORTMESSAGE::CreatePacket(const char* _name, const char* _msg)
{

	PACKETSHORTMESSAGE packet;
	packet.flag = PACK_SHORTMESSAGE;
	strcpy_s(packet.name, sizeof(packet.name), _name);
	strcpy_s(packet.msg, sizeof(packet.msg), _msg);
	CTime curTime = CTime::GetCurrentTime();
	packet.hour = curTime.GetHour();
	packet.min = curTime.GetMinute();
	packet.second = curTime.GetSecond();

	return packet;

}

PACKETSHORTMESSAGE PACKETSHORTMESSAGE::CreatePacket(const char* _name, const char* _msg, bool dummy)
{
	PACKETSHORTMESSAGE packet;
	packet.flag = PACK_MEMOMESSAGE;
	strcpy_s(packet.name, sizeof(packet.name), _name);
	strcpy_s(packet.msg, sizeof(packet.msg), _msg);
	CTime curTime = CTime::GetCurrentTime();
	packet.hour = curTime.GetHour();
	packet.min = curTime.GetMinute();
	packet.second = curTime.GetSecond();

	return packet;


}