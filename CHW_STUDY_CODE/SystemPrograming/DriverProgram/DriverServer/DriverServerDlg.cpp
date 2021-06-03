﻿
// DriverServerDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "DriverServer.h"
#include "DriverServerDlg.h"
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


// CDriverServerDlg 대화 상자



CDriverServerDlg::CDriverServerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DRIVERSERVER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDriverServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ctrlInfo);
}

BEGIN_MESSAGE_MAP(CDriverServerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_START, &CDriverServerDlg::OnBnClickedButtonStart)
END_MESSAGE_MAP()


// CDriverServerDlg 메시지 처리기

BOOL CDriverServerDlg::OnInitDialog()
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
CListBox* g_List;
void CDriverServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDriverServerDlg::OnPaint()
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
HCURSOR CDriverServerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

DWORD WINAPI ClientThread(LPVOID p)
{
	HANDLE hPipe = (HANDLE)p;
	TCHAR buf[256];
	DWORD dwRead;
	//CString strTemp;

	for (;;)
	{
		BOOL f = ReadFile(hPipe, buf, 256, &dwRead, NULL);
			if (f == FALSE || dwRead == 0) break;

		
		g_List->AddString(buf);
	}
	
	CloseHandle(hPipe);

	
	return 0;
}

DWORD WINAPI ListenThread(LPVOID p)
{
	for (;;)	//(여러명의 고객 접속을위한)고객을 여러번 생성하기위해 돌아가는 무한루프. 즉 고객 쓰레드를 여려개 만들기위해 필요.
	{
		//1. 파이프 생성
		HANDLE hPipe;
		hPipe = CreateNamedPipe(_T("\\\\.\\pipe\\Driverpipe"),
			PIPE_ACCESS_DUPLEX,
			PIPE_TYPE_BYTE,
			3,			//인스턴스 최대 수
			4096, 0, //out 버퍼, in 버퍼 사이즈.
			1,			//timeout , 0은 os가 알아서 해라(50ms).
			NULL);

		//2. 접속대기
		BOOL bConnect;
		bConnect = ConnectNamedPipe(hPipe, NULL);
		if ((bConnect == FALSE) && (GetLastError() == ERROR_PIPE_CONNECTED))
			bConnect = TRUE;

		if (bConnect)
		{
			DWORD dwID;
			CloseHandle(CreateThread(NULL, 0, ClientThread, (LPVOID)hPipe, 0, &dwID));
		}
		else
		{
			CloseHandle(hPipe);
		}
	}
	return 0;
}


void CDriverServerDlg::OnBnClickedButtonStart()
{
	g_List = &m_ctrlInfo;
	DWORD dwID;
	CreateThread(NULL, 0, ListenThread, this, NULL, &dwID);	
}
