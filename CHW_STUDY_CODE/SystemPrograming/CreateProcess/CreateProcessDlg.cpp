
// CreateProcessDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "CreateProcess.h"
#include "CreateProcessDlg.h"
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


// CCreateProcessDlg 대화 상자



CCreateProcessDlg::CCreateProcessDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CREATEPROCESS_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCreateProcessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCreateProcessDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CCreateProcessDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CCreateProcessDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CCreateProcessDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CCreateProcessDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CCreateProcessDlg 메시지 처리기

BOOL CCreateProcessDlg::OnInitDialog()
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

void CCreateProcessDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCreateProcessDlg::OnPaint()
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
HCURSOR CCreateProcessDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCreateProcessDlg::OnBnClickedButton2()
{
	//프로세스 생성1 , 유니코드 지원 x, 얘는 win32이라 전역함수다. ::이라고 된건 win32전역함수
	::WinExec("Notepad.exe", SW_SHOWNORMAL);	//동기로 실행
	///////////////////////////////////////////////
	CWnd* pWnd = FindWindow(_T("Notepad"), NULL);
	if (pWnd == NULL)
		AfxMessageBox(_T("검색불가"));
	else
		AfxMessageBox(_T("메모장을 찾았습니다."));

}


void CCreateProcessDlg::OnBnClickedButton1()
{
	STARTUPINFO si = {sizeof(STARTUPINFO),};	//처음에 자기 사이즈를 받아서 자기가 버젼이 뭔지알기위해
												//create할떄 이거의 주소를 주면 열리는 프로그램의 정보를 넣어준다.
	PROCESS_INFORMATION pi;					//프로세스의 핸들 같은거 반환.

	TCHAR strPath[20] = _T("Notepad.exe");

	//비동기 실행
	::CreateProcess(NULL, strPath,	//첫번쨰 인자도 주소를 주면찾아주는데 풀path를 입력해줘야하고, 두번쨰는 띄우고 싶은 프로그램이름을 올리면 찾아줌
				NULL, NULL, //보안속성 2개
				FALSE, 0, NULL, NULL,//상속, 우선순위, 인바이러번트, 작업우선순위
				&si, &pi);
	/////////////////////////////////////////////// 비동기이기떄문에 통신을 위해 기다리는 아래 함수 사용
	WaitForInputIdle(pi.hProcess, INFINITE);//hProcess이 완성될떄까지 기다린다.  INFINITE: 무제한으로 기다린다.
	/////////////////////////////////////////////
	CWnd* pWnd = FindWindow(_T("Notepad"), NULL);
	if (pWnd == NULL)
		AfxMessageBox(_T("검색불가"));
	else
	{
		//AfxMessageBox(_T("메모장을 찾았습니다."));
		Sleep(2000);
		pWnd->SendMessage(WM_CLOSE);
	}
		
}


void CCreateProcessDlg::OnBnClickedButton3()
{
	//자살하는 함수
	//ExitProcess(0);

	//타살로 자살하는함수 //GetCurrentProcess는 자기자신 핸들 받아오는함수.
	TerminateProcess(GetCurrentProcess(), 0);

	AfxMessageBox(_T("이 프로그램은 종료됩니다"));//수행되지 않음.


}


void CCreateProcessDlg::OnBnClickedButton4()
{
	STARTUPINFO si = { sizeof(STARTUPINFO), };	
	PROCESS_INFORMATION pi;					

	TCHAR strPath[20] = _T("Notepad.exe");

	//비동기 실행
	::CreateProcess(NULL, strPath,	
		NULL, NULL, //보안속성 2개
		FALSE, 0, NULL, NULL,//상속, 우선순위, 인바이러번트, 작업우선순위
		&si, &pi);
	
	WaitForInputIdle(pi.hProcess, INFINITE);
	Sleep(1000);
	
	TerminateProcess(pi.hProcess, 0);
	AfxMessageBox(_T("메모장 종료됩니다"));
}
