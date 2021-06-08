//Control.cpp

#include <stdio.h>
#include "packet.h"
#include "Control.h"

Control* Control::instance = NULL;

void Control::Run()
{
    try
    {
        net.CreateSocket(9000);
    }
    catch (const char* msg)
    {
        printf("에러 : %s\n", msg);
    }
}

void Control::RecvData(int sock, const char* msg, int size)
{
    printf(">> [수신데이터] %dbyte\n", size);
    int* p = (int*)msg;
    if (*p == PACK_NEWMEMBER)
    {
        printf("회원가입\n");
        PACKETNEWMEMBER* member = (PACKETNEWMEMBER*)msg;
        if (NewMember(member) == true)
        {
            member->flag = ACK_NEWMEMBER_S;
        }
        else
        {
            member->flag = ACK_NEWMEMBER_F;
        }

       
    }
    else if (*p == PACK_LOGIN)
    {
        printf("로그인\n");
        PACKLOGIN* login = (PACKLOGIN*)msg;
        if (LoginMember(login) == true)
        {
            login->flag = ACK_LOGIN_S;
        }
        else
        {
            login->flag = ACK_LOGIN_F;
        }

    }
    else if (*p == PACK_LOGOUT)
    {
        printf("로그아웃\n");
        PACKLOGOUT* logout = (PACKLOGOUT*)msg;
        if (LogoutMember(logout) == true)
        {
            logout->flag = ACK_LOGOUT_S;
           
        }
        else
        {
           
            logout->flag = ACK_LOGOUT_F;
        }
    }
    net.SendData(sock, msg, size);   //<=======전송!!!!!!!!!!
   
}

bool Control::LogoutMember(PACKLOGOUT* plogin)
{
    for (int i = 0; i < (int)personlist.size(); i++)
    {
        Member mem = personlist[i];
        if (strcmp(mem.getID(), plogin->id) == 0 && mem.getIsLogin() == TRUE)
        {
            //plogin의 나머지 정보 채우기

            personlist[i].setIsLogin(FALSE);
            PrintMemberData(); //결과출력
            return true;
        }
    }
    return false;
}


bool Control::NewMember(PACKETNEWMEMBER* pMem)
{
    Member member(pMem->name, pMem->id, pMem->pw);
    personlist.push_back(member);
    PrintMemberData();
    return true;
}

bool Control::LoginMember(PACKLOGIN* plogin)
{
    for (int i = 0; i < (int)personlist.size(); i++)
    {
        Member mem = personlist[i];
        if (strcmp(mem.getID(), plogin->id) == 0 &&
            strcmp(mem.getPW(), plogin->pw) == 0)
        {
            //plogin의 나머지 정보 채우기
            strcpy_s(plogin->name, sizeof(plogin->name),mem.getName());

            //vector의 로그인 상태값 변경하기
            personlist[i].setIsLogin(TRUE);
            PrintMemberData(); //결과출력
            return true;
        }
    }
    return false;
}

void Control::PrintMemberData()
{
    system("cls");

    printf("회원수 : %d\n", personlist.size());
    for (int i = 0; i < (int)personlist.size(); i++)
    {
        Member person = personlist[i];
        printf("[%d] %s\t%d\t%s\t%c\n",
            i, person.getName(), person.getID(), person.getPW(),
            (person.getIsLogin() ? 'O' : 'X'));
    }
}