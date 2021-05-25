
// LISTBOXDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "LISTBOX.h"
#include "LISTBOXDlg.h"
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


// CLISTBOXDlg 대화 상자



CLISTBOXDlg::CLISTBOXDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LISTBOX_DIALOG, pParent)
	, m_strName(_T(""))
	, m_strComboName(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLISTBOXDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_NAME, m_ctrlNameBox);
	DDX_Text(pDX, IDC_NAME, m_strName);
	DDX_Control(pDX, IDC_COMBO_NAME, m_ctrlNameCombo);
	DDX_CBString(pDX, IDC_COMBO_NAME, m_strComboName);
}

BEGIN_MESSAGE_MAP(CLISTBOXDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CLISTBOXDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CLISTBOXDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CLISTBOXDlg::OnBnClickedButton3)
	ON_LBN_SELCHANGE(IDC_LIST_NAME, &CLISTBOXDlg::OnLbnSelchangeListName)
	ON_BN_CLICKED(IDC_BUTTON4, &CLISTBOXDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CLISTBOXDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CLISTBOXDlg 메시지 처리기

BOOL CLISTBOXDlg::OnInitDialog()
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

void CLISTBOXDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLISTBOXDlg::OnPaint()
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
HCURSOR CLISTBOXDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLISTBOXDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//1. 에디트 창의; 글자를 읽어온다
	//UpdateData(1);
	GetDlgItem(IDC_NAME)->GetWindowText(m_strName);
	

	//2. 그 글자를 리스트 박스에 추가한다
	m_ctrlNameBox.AddString(m_strName);
	//m_ctrlNameBox.SetWindowText(m_strName); //위치를 모르기 때문에 넣어지지 않는다.

	//3. 에디트 창의 글자를 초기화한다.
	m_strName = _T("");
	//UpdateData(0);
	GetDlgItem(IDC_NAME)->SetWindowText(m_strName);

}


void CLISTBOXDlg::OnBnClickedButton2()
{
	//1. 에디트 창의; 글자를 읽어온다
	UpdateData(1);

	//2. 그 글자를 리스트 박스에 삽입한다
	m_ctrlNameBox.InsertString(0,m_strName);

	//3. 에디트 창의 글자를 초기화한다.
	m_strName = _T("");
	UpdateData(0);


}


void CLISTBOXDlg::OnBnClickedButton3()
{
	//1. 에디트 창의; 글자를 읽어온다
	UpdateData(1);

	//2. 그 글자로 리스트 박스에서 검색한다.
	int nIndex = m_ctrlNameBox.FindStringExact(-1,m_strName);
	if (nIndex == LB_ERR)// LB_ERR 리스트박스 에러.
	{
		AfxMessageBox(_T("찾는 사람이 없습니다"));
	}
	else
	{
		CString strTemp;
		m_ctrlNameBox.GetText(nIndex, strTemp);
		AfxMessageBox(strTemp);
	}

	//3. 에디트 창을 초기화한다.
	m_strName = _T("");
	UpdateData(0); //컨트롤 <-- 변수(m_strName)
}


void CLISTBOXDlg::OnLbnSelchangeListName()
{
	//1. 현재선택된 셀렉션을 알아낸다.(int index)
	int nIndex = m_ctrlNameBox.GetCurSel();

	if (nIndex == LB_ERR) return;

	//2. 구한 index의 글자를 구한다.
	CString strTemp;
	m_ctrlNameBox.GetText(nIndex, strTemp);

	//3. 그 글자를 대화상자에 쓴다.
	this->SetWindowText(strTemp);

}


void CLISTBOXDlg::OnBnClickedButton4()
{
	//1. 현재선택된 셀렉션을 알아낸다.(int index)
	int nIndex = m_ctrlNameBox.GetCurSel();

	if (nIndex == LB_ERR) return;

	//2. 구한 index의 글자를 구한다.
	CString strTemp;
	m_ctrlNameBox.GetText(nIndex, strTemp);

	//3. 그 글자를 대화상자에 쓴다.
	this->SetWindowText(strTemp);
	AfxMessageBox(_T("전화걸기")+ strTemp);
}


void CLISTBOXDlg::OnBnClickedButton5()
{
	//1. 콤보박스 에딧창에서 값을 읽어온다. 
	//GetDlgItem(IDC_COMBO_NAME)->GetWindowText(m_strComboName);
	UpdateData(1);

	//2. 콤보박스에 추가
	m_ctrlNameBox.AddString(m_strComboName);
	m_ctrlNameCombo.AddString(m_strComboName);

	//3. 콤보의 에디트창 초기화
	//3-1 m_ctrlNameCombo.SetWindowText(_T(""));
	
	//3-2 m_strComboName = _T("");
	//3-2 UpdateData(0);

	//3-3 m_ctrlNameCombo.SetEditSel(0, 5);	//0부터 5번까지 5글자의 셀렉션을 한다.(파란색으로 긋는것.)
	m_ctrlNameCombo.SetEditSel(0, -1);	//0부터 끝까지 글자의 셀렉션을 한다.(파란색으로 긋는것.)
	m_ctrlNameCombo.Clear();//위에 글자가 셀렉션되어있으니 그 셀렉션된것을 지운다.
}
