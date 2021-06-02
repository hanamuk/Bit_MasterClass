
// AsyncIODlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "AsyncIO.h"
#include "AsyncIODlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CAsyncIODlg 대화 상자



CAsyncIODlg::CAsyncIODlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ASYNCIO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAsyncIODlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAsyncIODlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CAsyncIODlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CAsyncIODlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CAsyncIODlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CAsyncIODlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CAsyncIODlg 메시지 처리기

BOOL CAsyncIODlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CAsyncIODlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CAsyncIODlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CAsyncIODlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

char strData[] =
"나룻배와 행인\r\n"
"			한용운\r\n"
"나는 나룻배\r\n"
"당신은 행인\r\n"
"당신은 흙발로 나를 짓밟습니다.\r\n"
"나는 당신을 안고 물을 건너갑니다.\r\n"
"나는 당신을 안으면 깊으나 얕으나 급한 여울이나 건너갑니다.\r\n"
"만일 당신이 아니 오시면 나는 바람을 쐬고 눈비를 맞으며\r\n"
"밤에서 낮까지 당신을 기다리고 있습니다.\r\n"
"당신은 물만 건너면 나를 보지도 않고 가십니다 그려.\r\n"
"그러나 당신이 언제든지 오실 줄만은 알아요.\r\n"
"나는 당신을 기다리면서 날마다 날마다 낡아 갑니다.\r\n"
"나는 나룻배\r\n"
"당신은 행인\r\n";
/*
비동기 방식은 CreateFile() 일떄와 CreateFileEx() 둘다 사용할 수있는데, 여기서 앞에 함수를 쓰면 이벤트 방식으로 결과를 받아
처리를 할 수 있고 뒤쪽의 함수를 사용하면 인자로 보낸 함수를 실행이 끝날때 콜백을 통해 호출하게 된다.
즉, 비동기는 둘다 가능하다

- 대부분의 커널객체는 동기화 객체다.
*/

//비동기에서 Event로 결과를 돌려받는 방식  Overlapped 방식.
void CAsyncIODlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	HANDLE hFile;
	hFile = CreateFile(_T("c:\\Temp\\event_io.txt"),
			GENERIC_WRITE,
			0, NULL, CREATE_ALWAYS,
			FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, 0); //FILE_FLAG_OVERLAPPED 를 줘야만 비동기를 사용한다.
	

	DWORD dwWritten = 0;

	//비동기 할때는 같은 핸들에 여러 IO가 될때 Offset을 잘 설정해야한다. Offset이 넣을 좌표? 이기떄문에 ..
	OVERLAPPED ov1 = { 0, };
	ov1.Offset = (strlen(strData) * sizeof(char)) * 0;
	ov1.hEvent = CreateEvent(NULL,TRUE,FALSE,NULL);

	OVERLAPPED ov2 = { 0, };
	ov2.Offset = (strlen(strData) * sizeof(char)) * 1;
	ov2.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);

	OVERLAPPED ov3 = { 0, };
	ov3.Offset = (strlen(strData) * sizeof(char)) * 2;
	ov3.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);


	//BOOL bRet = WriteFile(hFile, strData, sizeof(strData), &dwWritten, &ov);

	WriteFile(hFile, strData, sizeof(strData), &dwWritten, &ov1);//Write를 3번했는데 하나만 써진이유는ov의  Offset이 0으로 고정되어 있기때문에 똑같은곳에 계속써서이다.
	WriteFile(hFile, strData, sizeof(strData), &dwWritten, &ov2);
	WriteFile(hFile, strData, sizeof(strData), &dwWritten, &ov3);
	
	//if (bRet == FALSE && (GetLastError() == ERROR_IO_PENDING))//성공한 경우. 비동기 이기떄문에 이렇게 찾을수도 있다 굳이 뭔가 즉시체크할떄
		//AfxMessageBox(_T("IO가 정상적으로 요청되었습니다"));

	// 원래는 다른 작업을 해야한다 (강의 에서는 IO결과를 기다린다.. OS의 IO가 여기로 결과를 보내줌.)..
	//WaitForSingleObject(ov.hEvent, INFINITE);
	//WaitForSingleObject(hFile, INFINITE);
	HANDLE h[3] = { ov1.hEvent, ov2.hEvent, ov3.hEvent };
	WaitForMultipleObjects(3,h,TRUE, INFINITE);

	if(GetOverlappedResult(hFile, &ov1, &dwWritten, FALSE))	//이떄 진짜 ov, dwWritten 값이 들어온다
	{
		CString strTemp;
		strTemp.Format(_T("1번 비동기 결과 : %d"), dwWritten);
		AfxMessageBox(strTemp);
	}

	if (GetOverlappedResult(hFile, &ov2, &dwWritten, FALSE))//이떄 진짜 ov, dwWritten 값이 들어온다
	{
		CString strTemp;
		strTemp.Format(_T("2번 비동기 결과 : %d"), dwWritten);
		AfxMessageBox(strTemp);
	}

	if (GetOverlappedResult(hFile, &ov3, &dwWritten, FALSE))//이떄 진짜 ov, dwWritten 값이 들어온다
	{
		CString strTemp;
		strTemp.Format(_T("3번 비동기 결과 : %d"), dwWritten);
		AfxMessageBox(strTemp);
	}
	CloseHandle(hFile);
}


void WINAPI MyFunc(DWORD dwErr, DWORD dwByte, LPOVERLAPPED pOV) //DWORD dwErr, DWORD dwByte, LPOVERLAPPED pOV 는 자동으로 OS넣어주는것.
{
	CString strTemp;
	strTemp.Format(_T("[%s] 비동기IO결과 : %d"), pOV->hEvent, dwByte);
	AfxMessageBox(strTemp);
	
}


//비동기에서 Callback방식
void CAsyncIODlg::OnBnClickedButton2()
{
	HANDLE hFile;
	hFile = CreateFile(_T("c:\\Temp\\callback_io.txt"),
		GENERIC_WRITE,
		0, NULL, CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, 0);

	OVERLAPPED ov1 = { 0, };
	ov1.Offset = (strlen(strData) * sizeof(char)) * 0;
	ov1.hEvent = (HANDLE)_T("겨울왕국");

	OVERLAPPED ov2 = { 0, };
	ov2.Offset = (strlen(strData) * sizeof(char)) * 1;
	ov2.hEvent = (HANDLE)_T("여름왕국");

	OVERLAPPED ov3 = { 0, };
	ov3.Offset = (strlen(strData) * sizeof(char)) * 2;
	ov3.hEvent = (HANDLE)_T("콜라왕국");

	WriteFileEx(hFile, strData, sizeof(strData), &ov1, MyFunc); //MyFunc : 완료루틴? 인데 알림가능상태로 바꿔야 불러짐.(경고성대기상태, alert-able State)
	WriteFileEx(hFile, strData, sizeof(strData), &ov2, MyFunc);
	WriteFileEx(hFile, strData, sizeof(strData), &ov3, MyFunc);
	
	
	SleepEx(1, TRUE);//  TRUE가 알림가능한 상태로 변경한다는 뜻

	CloseHandle(hFile);

}

#define MEGA 1048576 //1m
#pragma warning (disable:4996)
char* buf;
DWORD len;
//HANDLE g_hEvent;

DWORD WINAPI MakeBigData(LPVOID lp)
{


	if (buf == NULL)
	{
		AfxMessageBox(_T("메모리 할당실패"));
		return -1;
	}

	char* p = NULL;
	

	char sTemp[256];
	int tlen;

	p = buf;
	for (int i = 1; ; i++)
	{
		sprintf(sTemp, ("%dLine : this file is a test\r\n"), i);
		tlen = strlen(sTemp);
		if (p - buf + tlen >= 100 * MEGA)break;
		strcpy(p, sTemp);
		p += tlen;	//buf는 고정되어있고 p가 전진하면서 지금까지 쓴 글의 크기를 알수있다.

	}
	len = p - buf;

	//SetEvent(g_hEvent);
	return 0;

}
DWORD WINAPI WriteBigData(LPVOID p)

{	//WaitForSingleObject(g_hEvent, INFINITE);
	HANDLE hBigFile;
	hBigFile = CreateFile(_T("C:\\Temp\\BigFile.txt"), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, 0);

	OVERLAPPED ov = { 0 };
	ov.hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);//기다리는게 하나일떄.	

	BOOL bReturn = WriteFile(hBigFile, buf, len, NULL, &ov);
	if (bReturn == FALSE && GetLastError() == ERROR_IO_PENDING)
	{
		AfxMessageBox(_T("IO가 정상 요청 되었습니다"));
	}
	//IO 완료 통지(event)를 기다려
	WaitForSingleObject(ov.hEvent, INFINITE);
	DWORD dwWritten;
	if (GetOverlappedResult(hBigFile, &ov, &dwWritten, FALSE))	//이떄 진짜 ov, dwWritten 값이 들어온다
	{
		CString strTemp;
		strTemp.Format(_T("빅파일 비동기 결과 : %d"), dwWritten);
		AfxMessageBox(strTemp);
	}
	CloseHandle(hBigFile);
	
	
	return 0;
}


void CAsyncIODlg::OnBnClickedButton3()
{
	
	DWORD id;
	HANDLE hMake;
	//g_hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);


	buf = (char*)calloc(100, MEGA); //MEGA를 50 개 만들어줘.

	hMake = CreateThread(0, 0, MakeBigData, 0, 0, &id);
	WaitForSingleObject(hMake, INFINITE);

	CloseHandle(CreateThread(0, 0, WriteBigData, 0, 0, &id));
	CloseHandle(hMake);
	free(buf);
}


//복사하기.
void CAsyncIODlg::OnBnClickedButton4()
{
	//1. src파일의 MMF(변수)를 생성한다. 
	HANDLE hSrc;
	hSrc = CreateFile(_T("c:\\Temp\\BigFile.txt"),
		   GENERIC_READ, 0, NULL, OPEN_EXISTING,
		   FILE_ATTRIBUTE_NORMAL, 0);

	//1-0 파일사이즈를 구한다.
	LARGE_INTEGER llFileSize;
	GetFileSizeEx(hSrc, &llFileSize);
	
	//1-1 MMF 1단계
	HANDLE hFMap = CreateFileMapping(hSrc, NULL,
		PAGE_READONLY, 0, 0, 0);

	//1-2 MMF 2단계 
	TCHAR* pText = (TCHAR*)MapViewOfFile(hFMap, FILE_MAP_READ, 0, 0, 0);

	//2. 타겟파일로 WriteEx()한다. 그포인터를 write파일 2번째 인자에 넣는다..
	HANDLE hDest;
	hDest = CreateFile(_T("c:\\Temp\\copycopy.txt"),
			GENERIC_WRITE, 0, NULL, CREATE_ALWAYS,
			FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, 0);

	OVERLAPPED ov1 = { 0, };
	ov1.hEvent = (HANDLE)_T("파일복사");

	WriteFileEx(hDest, pText, llFileSize.QuadPart, &ov1, MyFunc);//핸들, 시작주소, 크기, ? ,콜백함수
	SleepEx(1, TRUE);

	//3 뒷정리한다.
	UnmapViewOfFile(pText);
	CloseHandle(hFMap);
	CloseHandle(hSrc);
	CloseHandle(hDest);
	
}
