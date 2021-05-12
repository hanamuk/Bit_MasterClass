#include<stdio.h>
#include<windows.h>

#define DATA_FILE_NAME "C:\\Temp\\myAddr.dat"
#define		MAX_BOOKCOUNT	5
#define     LABEL_MAX       4
#define     NAME_MAX        32
#define     P_NUMVER_MAX    20

typedef struct _USERDATA
{
    char strName[NAME_MAX];	  // �̸�
    int nAge;			  // ����
    int nGender;		  // ����
    char strPhoneNumber[P_NUMVER_MAX];
    struct USERDATA* pLink;

} USERDATA;

int		g_nCount = 0;
USERDATA	g_AddrBook[MAX_BOOKCOUNT];

const enum Menu { EXIT = 0, ADD, SERCH, DEL, LIST };
const char* szLabel[LABEL_MAX] = { "�Է�","�˻�","����","��Ϻ���" };

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
    LoadData(DATA_FILE_NAME);//���Ͽ��� �о����
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
            printf("�����մϴ�. \n\n");
            SaveData(DATA_FILE_NAME);//���Ͽ� �����ϱ�
            return 0;
        }
        else
        {
            printf("���Է�.");
        }
        Sleep(1000);
        system("cls");
    }

    SaveData(DATA_FILE_NAME);//���Ͽ� �����ϱ�
    return 0;
}

int LoadData(char* szFileName)
{

    //g_AddrBook <-- szFileName
    // ---------------------------
    //1. ��Ʈ��(����) ���� (rb���)
    FILE* fp;
    fopen_s(&fp, szFileName, "rb");

    if (fp == NULL)
        return;

    //2. ��Ʈ��(����)�� �б�
    fread(&g_nCount, sizeof(int), 1, fp);//�������
    //for (int i = 0; i < g_nCount; i++) {
    for (int i = 0; i < g_nCount; i++) {
    //for (int i = 0; i < MAX_BOOKCOUNT; i++) {
        fread(g_AddrBook + i, sizeof(USERDATA), 1, fp);
    }

    /*
    if (fp == NULL)
    {
        printf("������");
        return;

    }
 
    while (!feof(fp))
    {
        fread(g_AddrBook + nCount, sizeof(USERDATA), 1, fp);
        nCount++;
    }
     */  

    //3. ��Ʈ�� ����
    fclose(fp);


    return 0;
}
int SaveData(char* szFileName)
{
    
    //g_AddrBook --> szFileName
    // ---------------------------
    //1. ��Ʈ��(����) ���� (wb���)
    FILE* fp;
    fopen_s(&fp, szFileName, "wb");

    //2. ��Ʈ��(����)�� ����
    fwrite(&g_nCount, sizeof(int), 1, fp);//ī��Ʈ ����

    for (int i = 0; i < g_nCount; i++) {
    //for (int i = 0; i < MAX_BOOKCOUNT; i++) {
        fwrite(g_AddrBook+i, sizeof(USERDATA),1,fp);//������ ����
    }
    
    //3. ��Ʈ�� ����
    fclose(fp);

    return 0;
}


void Menu(const char* szLabel[], int* nMenu)
{
    printf("===================================================\n");
    printf("��ȭ��ȣ��(Array)\n");
    for (int i = 0; i < LABEL_MAX; i++) {
        printf("%d. %s \n", i + 1, szLabel[i]);
    }

    printf("0. ���� \n");
    printf("===================================================\n");

    printf("============= \n");
    printf("���ϴ� ����� �����ϼ��� : ");
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
        printf("������ ���� ������ �����մϴ�");
        return;
    }

    printf("�̸��� �Է��ϼ��� : ");
    gets(strName);
    if (NameSerch(strName) == 1)
    {
        printf("�̹� �����ϴ� �̸��Դϴ�.\n");
        return;
    }

    printf("���̸� �Է��ϼ��� : ");
    scanf_s("%d", &nAge);

    printf("������ �Է��ϼ���(����:0, ���� :1) : ");
    scanf_s("%d", &nGender);

    printf("��ȭ��ȣ�� �Է��ϼ���(-����) : ");
    scanf_s("%s", strPhoneNum, sizeof(strPhoneNum));

    printf("�̸� : %s\t���� : %s,\t���� : %d��,\t��ȭ��ȣ : %s  �����Ͻðڽ��ϱ�? y(1)/n(0) : ",
        strName,
        nGender == 0 ? "����" : "����",
        nAge,
        strPhoneNum);

    scanf_s("%d", &nChoice);
    if (nChoice != 1 && nChoice != 0) {
        printf(" �߸��Է��ϼ̽��ϴ�. �ٽ� �Է��ϼ���\n ");
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
        printf("����� �����ϴ�.\n");
        return;
    }

    printf("----%d���� ����ó----\n\n", g_nCount);
    for (int i = 0; i < g_nCount; i++) {

        printf("%d. �̸� : %s \t ,���� : %s\t, ���� : %d��\t,  ��ȭ��ȣ : %s\n",
            i + 1,
            g_AddrBook[i].strName,
            g_AddrBook[i].nGender == 0 ? "����" : "����",
            g_AddrBook[i].nAge,
            g_AddrBook[i].strPhoneNumber);
    }
    getch();
}

void Serch()
{
    char strName[15] = { NULL };
    int cmpResult = -1;

    printf("�˻��� ���� �̸��� �Է��ϼ��� : ");
    gets(strName);

    for (int i = 0; i < g_nCount; i++)
    {
        cmpResult = strcmp(g_AddrBook[i].strName, strName);
        if (cmpResult == 0)
        {
            printf("%d��. �̸� : %s\t ,���� : %s\t, ���� : %d��\t,  ��ȭ��ȣ : %s\n",
                i + 1,
                g_AddrBook[i].strName,
                g_AddrBook[i].nGender == 0 ? "����" : "����",
                g_AddrBook[i].nAge,
                g_AddrBook[i].strPhoneNumber);
            getch();

        }
    }
    if (cmpResult != 0)
        printf("�˻��� ����� �����ϴ�.  ");

    Sleep(2000);
}

void Delete()
{
    char strName[15] = { NULL };
    int cmpRetult = -1;


    printf("������ ����ó�� �̸��� �Է��ϼ��� : ");
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

            printf("%s �����Ϸ�", strName);
            Sleep(1000);
            break;
        }
    }
    if (cmpRetult == 1)
        printf("������ ����� �����ϴ�.");

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
            return 1; //�ִ�
    }
    return 0;
}
