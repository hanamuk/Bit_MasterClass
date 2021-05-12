#include<stdio.h>
#include<windows.h>

#define DATA_FILE_NAME "C:\\Temp\\myAddr.dat"
#define		MAX_BOOKCOUNT	5
#define     LABEL_MAX       4
#define     NAME_MAX        32
#define     P_NUMVER_MAX    20

typedef struct _USERDATA
{
    char strName[NAME_MAX];	  // 이름
    int nAge;			  // 나이
    int nGender;		  // 성별
    char strPhoneNumber[P_NUMVER_MAX];
    struct USERDATA* pLink;

} USERDATA;

int		g_nCount = 0;
USERDATA	g_AddrBook[MAX_BOOKCOUNT];

const enum Menu { EXIT = 0, ADD, SERCH, DEL, LIST };
const char* szLabel[LABEL_MAX] = { "입력","검색","삭제","목록보기" };

void Menu(const char* szLabel[], int* nMenu);
void Add();
void Delete();
void PrintAll();
void Serch();
int NameSerch(char* name);
int LoadData(char*);
int SaveData(char*);


int main(void)
{
    LoadData(DATA_FILE_NAME);//파일에서 읽어오기
    int nMenu = -1;

    for (;;)
    {
        Menu(szLabel, &nMenu);

        if (nMenu == ADD)
            Add();
        else if (nMenu == SERCH)
            Serch();
        else if (nMenu == DEL)
            Delete();
        else if (nMenu == LIST)
            PrintAll();
        else if (nMenu == EXIT)
        {
            printf("종료합니다. \n\n");
            SaveData(DATA_FILE_NAME);//파일에 저장하기
            return 0;
        }
        else
        {
            printf("재입력.");
        }
        Sleep(1000);
        system("cls");
    }

    SaveData(DATA_FILE_NAME);//파일에 저장하기
    return 0;
}

int LoadData(char* szFileName)
{

    //g_AddrBook <-- szFileName
    // ---------------------------
    //1. 스트림(파일) 개방 (rb모드)
    FILE* fp;
    fopen_s(&fp, szFileName, "rb");

    if (fp == NULL)
        return;

    //2. 스트림(파일)에 읽기
    fread(&g_nCount, sizeof(int), 1, fp);//헤더정보
    //for (int i = 0; i < g_nCount; i++) {
    for (int i = 0; i < g_nCount; i++) {
    //for (int i = 0; i < MAX_BOOKCOUNT; i++) {
        fread(g_AddrBook + i, sizeof(USERDATA), 1, fp);
    }

    /*
    if (fp == NULL)
    {
        printf("빈파일");
        return;

    }
 
    while (!feof(fp))
    {
        fread(g_AddrBook + nCount, sizeof(USERDATA), 1, fp);
        nCount++;
    }
     */  

    //3. 스트림 폭파
    fclose(fp);


    return 0;
}
int SaveData(char* szFileName)
{
    
    //g_AddrBook --> szFileName
    // ---------------------------
    //1. 스트림(파일) 개방 (wb모드)
    FILE* fp;
    fopen_s(&fp, szFileName, "wb");

    //2. 스트림(파일)에 저장
    fwrite(&g_nCount, sizeof(int), 1, fp);//카운트 저장

    for (int i = 0; i < g_nCount; i++) {
    //for (int i = 0; i < MAX_BOOKCOUNT; i++) {
        fwrite(g_AddrBook+i, sizeof(USERDATA),1,fp);//데이터 저장
    }
    
    //3. 스트림 폭파
    fclose(fp);

    return 0;
}


void Menu(const char* szLabel[], int* nMenu)
{
    printf("===================================================\n");
    printf("전화번호부(Array)\n");
    for (int i = 0; i < LABEL_MAX; i++) {
        printf("%d. %s \n", i + 1, szLabel[i]);
    }

    printf("0. 종료 \n");
    printf("===================================================\n");

    printf("============= \n");
    printf("원하는 기능을 선택하세요 : ");
    scanf_s("%d", nMenu);
    getchar();
}


void Add()
{
    char strName[15] = { NULL };
    char strPhoneNum[15] = { NULL };
    int nAge = 1;
    int nGender = 0;

    int nChoice = -1;

    if (g_nCount > MAX_BOOKCOUNT)
    {
        printf("데이터 저장 공간이 부족합니다");
        return;
    }

    printf("이름을 입력하세요 : ");
    gets(strName);
    if (NameSerch(strName) == 1)
    {
        printf("이미 존재하는 이름입니다.\n");
        return;
    }

    printf("나이를 입력하세요 : ");
    scanf_s("%d", &nAge);

    printf("성별을 입력하세요(남성:0, 여성 :1) : ");
    scanf_s("%d", &nGender);

    printf("전화번호를 입력하세요(-포함) : ");
    scanf_s("%s", strPhoneNum, sizeof(strPhoneNum));

    printf("이름 : %s\t성별 : %s,\t나이 : %d세,\t전화번호 : %s  저장하시겠습니까? y(1)/n(0) : ",
        strName,
        nGender == 0 ? "남성" : "여성",
        nAge,
        strPhoneNum);

    scanf_s("%d", &nChoice);
    if (nChoice != 1 && nChoice != 0) {
        printf(" 잘못입력하셨습니다. 다시 입력하세요\n ");
        return;
    }

    if (nChoice == 1) {
        strcpy_s(g_AddrBook[g_nCount].strName, sizeof(g_AddrBook[g_nCount].strName), strName);
        strcpy_s(g_AddrBook[g_nCount].strPhoneNumber, sizeof(g_AddrBook[g_nCount].strPhoneNumber), strPhoneNum);
        g_AddrBook[g_nCount].nAge = nAge;
        g_AddrBook[g_nCount].nGender = nGender;
        g_AddrBook[g_nCount].pLink = g_AddrBook + (g_nCount + 1);

        g_nCount++;
    }
    else {
        getchar();
        return;
    }
}

void PrintAll()
{
    if (g_nCount == 0) {
        printf("목록이 없습니다.\n");
        return;
    }

    printf("----%d개의 연락처----\n\n", g_nCount);
    for (int i = 0; i < g_nCount; i++) {

        printf("%d. 이름 : %s \t ,성별 : %s\t, 나이 : %d세\t,  전화번호 : %s\n",
            i + 1,
            g_AddrBook[i].strName,
            g_AddrBook[i].nGender == 0 ? "남성" : "여성",
            g_AddrBook[i].nAge,
            g_AddrBook[i].strPhoneNumber);
    }
    getch();
}

void Serch()
{
    char strName[15] = { NULL };
    int cmpResult = -1;

    printf("검색할 분의 이름을 입력하세요 : ");
    gets(strName);

    for (int i = 0; i < g_nCount; i++)
    {
        cmpResult = strcmp(g_AddrBook[i].strName, strName);
        if (cmpResult == 0)
        {
            printf("%d번. 이름 : %s\t ,성별 : %s\t, 나이 : %d세\t,  전화번호 : %s\n",
                i + 1,
                g_AddrBook[i].strName,
                g_AddrBook[i].nGender == 0 ? "남성" : "여성",
                g_AddrBook[i].nAge,
                g_AddrBook[i].strPhoneNumber);
            getch();

        }
    }
    if (cmpResult != 0)
        printf("검색한 사람이 없습니다.  ");

    Sleep(2000);
}

void Delete()
{
    char strName[15] = { NULL };
    int cmpRetult = -1;


    printf("삭제할 연락처의 이름을 입력하세요 : ");
    gets(strName);

    for (int i = 0; i < g_nCount; i++)
    {
        cmpRetult = strcmp(g_AddrBook[i].strName, strName);
        if (cmpRetult == 0)
        {
            *(g_AddrBook + i)->strName = NULL;
            *(g_AddrBook + i)->strPhoneNumber = NULL;
            g_AddrBook[i].nGender = NULL;
            g_AddrBook[i].nAge = NULL;
            g_AddrBook[i].pLink = NULL;

            g_nCount--;

            for (int j = i; j <= g_nCount; j++)
                g_AddrBook[j] = g_AddrBook[j + 1];

            printf("%s 삭제완료", strName);
            Sleep(1000);
            break;
        }
    }
    if (cmpRetult == 1)
        printf("삭제할 사람이 없습니다.");

    Sleep(1000);
    getchar();
}

int NameSerch(char* name)
{
    int cmpResult = -1;

    for (int i = 0; i < g_nCount; i++)
    {
        cmpResult = strcmp(g_AddrBook[i].strName, name);
        if (cmpResult == 0)
            return 1; //있다
    }
    return 0;
}
