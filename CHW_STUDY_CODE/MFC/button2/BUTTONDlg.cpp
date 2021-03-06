
// BUTTONDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "BUTTON.h"
#include "BUTTONDlg.h"
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


// CBUTTONDlg 대화 상자



CBUTTONDlg::CBUTTONDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BUTTON_DIALOG, pParent)
	, m_bAll(TRUE)
	, m_bUpDate(FALSE)
	, m_bSystem(TRUE)
	, m_nOS(2)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBUTTONDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_ALL, m_bAll);
	DDX_Check(pDX, IDC_CHECK_UPDATE, m_bUpDate);
	DDX_Check(pDX, IDC_CHECK_SYSTEM, m_bSystem);
	DDX_Radio(pDX, IDC_RADIO1, m_nOS);
}

BEGIN_MESSAGE_MAP(CBUTTONDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDD_START_V3, &CBUTTONDlg::OnBnClickedStartV3)
	ON_BN_CLICKED(IDC_CHECK_ALL, &CBUTTONDlg::OnBnClickedCheckAll)
END_MESSAGE_MAP()


// CBUTTONDlg 메시지 처리기

BOOL CBUTTONDlg::OnInitDialog()
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

void CBUTTONDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CBUTTONDlg::OnPaint()
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
HCURSOR CBUTTONDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CBUTTONDlg::OnBnClickedStartV3()
{
	//1. 채크 박스의 값들을 읽어온다.
	UpdateData(1);		//컨트롤 ->변수 , 한번하면 연결된 모든변수의 값을 가져오는듯.

	//2. 그 값들에 따라서 검사를 진행한다

	if(m_bAll)		AfxMessageBox(_T("전체 영역 검사"));
	if (m_bUpDate)	AfxMessageBox(_T("업데이트 영역 검사"));
	if (m_bSystem)	AfxMessageBox(_T("시스템 영역 검사"));

	//3. OS별로 검사를 진행한다.
	switch (m_nOS)
	{
	case 0: 
		AfxMessageBox(_T("안드로이드")); break;
	case 1:
		AfxMessageBox(_T("윈도우"));		break;
	case 2:
		AfxMessageBox(_T("리눅스"));		break;


	}
}


void CBUTTONDlg::OnBnClickedCheckAll()
{
	//1. 1번 체크박스의 값을 읽어온다.
	UpdateData(1); //컨트롤 ->변수

	//2. 그 값에 따라 나머지 체크박스를 처리한다.
	if (m_bAll)	//전체검사를 의향이 있다.
	{
		//나머지 체크박스를 디스에이블 한다.
		CWnd* pWnd = this->GetDlgItem(IDC_CHECK_UPDATE);
		pWnd->EnableWindow(0);
		GetDlgItem(IDC_CHECK_SYSTEM)->EnableWindow(0);

		GetDlgItem(IDC_CHECK_UPDATE)->ShowWindow(0);
		GetDlgItem(IDC_CHECK_SYSTEM)->ShowWindow(0);

		GetDlgItem(IDD_START_V3)->SetWindowText(_T("전체검사 시작"));
		this->SetWindowText(_T("전체검사 시작"));
	}
	else //전체검사를 할 의향이 없다
	{
		//나머지 체크박스를 인에이블 한다.
		GetDlgItem(IDC_CHECK_UPDATE)->EnableWindow(1);
		GetDlgItem(IDC_CHECK_SYSTEM)->EnableWindow(1);

		GetDlgItem(IDC_CHECK_UPDATE)->ShowWindow(1);
		GetDlgItem(IDC_CHECK_SYSTEM)->ShowWindow(1);

		GetDlgItem(IDD_START_V3)->SetWindowText(_T("전체검사를 하지 않습니다"));
		this->SetWindowText(_T("전체검사를 하지 않습니다"));


	}
}
