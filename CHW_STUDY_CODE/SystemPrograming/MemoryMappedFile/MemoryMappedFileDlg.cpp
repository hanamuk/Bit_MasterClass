
// MemoryMappedFileDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MemoryMappedFile.h"
#include "MemoryMappedFileDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


#pragma warning (disable:4996)

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


// CMemoryMappedFileDlg 대화 상자



CMemoryMappedFileDlg::CMemoryMappedFileDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MEMORYMAPPEDFILE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMemoryMappedFileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMemoryMappedFileDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMemoryMappedFileDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMemoryMappedFileDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMemoryMappedFileDlg 메시지 처리기

BOOL CMemoryMappedFileDlg::OnInitDialog()
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

void CMemoryMappedFileDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMemoryMappedFileDlg::OnPaint()
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
HCURSOR CMemoryMappedFileDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMemoryMappedFileDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	HANDLE hFile =  CreateFile(_T("c:\\Temp\\Naru.txt"),
					GENERIC_READ, 0, NULL,  //모드, ? , 보안
					OPEN_EXISTING, //만드는 목적(OPEN_EXISTING는 존재하면)
					FILE_ATTRIBUTE_NORMAL,
					NULL);

	//1. 파일 매핑 오브 젝트를 생성한다
	HANDLE hFMap =  CreateFileMapping(hFile, NULL,
					PAGE_READONLY, 0, 0,0);//세번쨰 인자는 CreateFile 에서 두번쨰 인자와 맞아야한다., 네번쨰 다섯번쨰인자를 0으로 주면 파일크기 그대로 가져온다는 뜻
	
	
	//2. 파일 매핑 오브젝트를 가상메모리 주소공간에 연결한다.
	TCHAR* pText = (TCHAR*)MapViewOfFile(hFMap, FILE_MAP_READ, 0, 0, 0);

	//3. 파일을 변수처럼 사용한다.
	if (IsTextUnicode(pText, 10, NULL)) //10글자만 읽어봐
	{
		//유니코드 AfxMessageBox는 유니코드 전용
		AfxMessageBox(pText);
	}
	else
	{
		//ansi코드: 변환을 해주어야함
		char* pAnsiText = (char*)pText;
		MessageBoxA(NULL, pAnsiText,"최현우",MB_OK);

	}

	//AfxMessageBox(pText);	//위의 if를 안쓸때 깨지는이유는 저 파일에 저장된게 원래 ansi인데 위에서 읽을떄 TCHAR(유니코드)로 읽기떄문에.

	//4. 뒷정리를 한다
	UnmapViewOfFile(pText);
	CloseHandle(hFMap);
	CloseHandle(hFile);

}


void CMemoryMappedFileDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	HANDLE hFile;
	hFile = CreateFile(_T("c:\\Temp\\Alpha.txt"),
		GENERIC_READ|GENERIC_WRITE,
		0, NULL,  //모드, ? , 보안
		OPEN_EXISTING, //만드는 목적(OPEN_EXISTING는 존재하면)
		FILE_ATTRIBUTE_NORMAL, NULL);

	//1. 파일 매핑오브젝트를 만든다
	HANDLE hFMap;
	hFMap = CreateFileMapping(hFile, NULL,
				PAGE_READWRITE, 0, 0, NULL);

	//2.
	char* pText = (char*)MapViewOfFile(hFMap, FILE_MAP_WRITE, 0, 0, 0);
	
	//3. 파일을 메모리 처럼 사용한다
	strcpy(pText, "hello" );

	//4. 뒷정리를 한다
	UnmapViewOfFile(pText);
	CloseHandle(hFMap);
	CloseHandle(hFile);

}
