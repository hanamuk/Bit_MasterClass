
// DriverClientDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "DriverClient.h"
#include "DriverClientDlg.h"
#include "afxdialogex.h"
#include "Driver.h"

 			
#pragma comment(lib, "Driver")	

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


// CDriverClientDlg 대화 상자



CDriverClientDlg::CDriverClientDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DRIVERCLIENT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	InitMyDev(5);
	
	
}

void CDriverClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);	
}

BEGIN_MESSAGE_MAP(CDriverClientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_START, &CDriverClientDlg::OnBnClickedButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_SUSUPEND, &CDriverClientDlg::OnBnClickedButtonSusupend)
	ON_BN_CLICKED(IDC_BUTTON_END, &CDriverClientDlg::OnBnClickedButtonEnd)
END_MESSAGE_MAP()


// CDriverClientDlg 메시지 처리기

BOOL CDriverClientDlg::OnInitDialog()
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

void CDriverClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDriverClientDlg::OnPaint()
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
HCURSOR CDriverClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

typedef struct USERDATA
{
	int x;
	int y;

}USERDATA;

USERDATA g_arrData[100]; //구조체로 받는다
int g_nCount = 0;

DWORD WINAPI MakeData(LPVOID p)
{
	USERDATA* arMake = (USERDATA*) p;
	CString strTemp;
	HANDLE hPipe;
	BOOL bSuccess;
	DWORD dwWritten;

	for (int i = 0; i < 100; i++)
	{
		arMake[i].x = arMake[i].x * 2;
		arMake[i].y = arMake[i].y * 2;
		
	}

	for (;;)
	{
		if (WaitNamedPipe(_T("\\\\.\\pipe\\Driverpipe"), NMPWAIT_WAIT_FOREVER) == TRUE)
		{

			hPipe = CreateFile(_T("\\\\.\\pipe\\Driverpipe"),
				GENERIC_WRITE, 0, NULL,
				CREATE_ALWAYS, 0, NULL);

			if (hPipe != INVALID_HANDLE_VALUE)//무한루프 탈출조건. 핸들이 제대로 돌아왔을떄.
				break;

		}
	}
	for (int i = 0; i < 100; i++) //만들기.
	{
		strTemp.Format(_T("MakeData :: x=%d, y=%d\n"), arMake[i].x, arMake[i].y);
		bSuccess = WriteFile(hPipe, strTemp, (lstrlen(strTemp) + 1) * sizeof(CString), &dwWritten, NULL);
		if ((bSuccess == FALSE) || (dwWritten == 0)) break;

	}

	
	CloseHandle(hPipe);
	return 0;
}

DWORD WINAPI MonitorDev(LPVOID p)
{
	CString strTemp;
	DWORD dwID;
	int x, y;
	for (;;)	
	{
		Sleep(10);
	
		//100개가 모이면 메이크쓰레드에 보낸다.
		if (g_nCount == 100)
		{
			USERDATA* arCopy = (USERDATA*)malloc(sizeof(g_arrData));

			memcpy(arCopy, g_arrData, sizeof(USERDATA)*100);
			CloseHandle(CreateThread(NULL, 0, MakeData, arCopy, 0, &dwID));
			g_nCount = 0;

			//free(arCopy);
		}

		if (::GetMyDevPosition(&x, &y)) //정보를 배열에 넣고
		{
			g_nCount++;
			strTemp.Format(_T("x=%d, y=%d\n"), g_arrData[g_nCount].x, g_arrData[g_nCount].y);
		}
			
		else
			strTemp.Format(_T("에러발생 : %d\n"), GetMyDevError());
		//::OutputDebugString(strTemp);
	}
	return 0;
}

HANDLE g_hMake;
void CDriverClientDlg::OnBnClickedButtonStart()
{
	DWORD dwID;
	g_hMake = CreateThread(NULL, 0, MonitorDev, NULL, 0, &dwID);
}


void CDriverClientDlg::OnBnClickedButtonSusupend()
{
	static BOOL bPause = FALSE;
	if (bPause != TRUE)
	{
		SuspendThread(g_hMake);
	}
	else
	{
		ResumeThread(g_hMake);
	}
	bPause = !bPause;
}


void CDriverClientDlg::OnBnClickedButtonEnd()
{

	ReleaseMyDev();
	TerminateThread(g_hMake, 0);
	CloseHandle(g_hMake);
}
