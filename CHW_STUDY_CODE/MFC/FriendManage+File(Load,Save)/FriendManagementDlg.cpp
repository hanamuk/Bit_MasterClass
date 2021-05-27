﻿
// FriendManagementDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "FriendManagement.h"
#include "FriendManagementDlg.h"
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


// CFriendManagementDlg 대화 상자



CFriendManagementDlg::CFriendManagementDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FRIENDMANAGEMENT_DIALOG, pParent)
	, m_strName(_T(""))
	, m_nAge(0)
	, m_bGender(FALSE)
	, m_Path(_T(""))
{
	m_nCount = 0;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFriendManagementDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NAME, m_strName);
	DDX_Text(pDX, IDC_AGE, m_nAge);
	DDX_Radio(pDX, IDC_MALE, m_bGender);
	DDX_Control(pDX, IDC_SPIN1, m_ctrlSpin);
	DDX_Control(pDX, IDC_LIST, m_ctrlFriendList);
}

BEGIN_MESSAGE_MAP(CFriendManagementDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_ADD, &CFriendManagementDlg::OnBnClickedBtnAdd)
	ON_EN_UPDATE(IDC_AGE, &CFriendManagementDlg::OnEnUpdateAge)
	ON_BN_CLICKED(IDC_BTN_DEL, &CFriendManagementDlg::OnBnClickedBtnDEL)
	ON_BN_CLICKED(IDC_BTN_UPDATE, &CFriendManagementDlg::OnBnClickedBtnUPDATE)
	ON_NOTIFY(LVN_ENDLABELEDIT, IDC_LIST, &CFriendManagementDlg::OnLvnEndlabeleditList)
	ON_BN_CLICKED(IDC_SAVE, &CFriendManagementDlg::OnBnClickedSave)
	ON_BN_CLICKED(IDC_LOAD, &CFriendManagementDlg::OnBnClickedLoad)
END_MESSAGE_MAP()


// CFriendManagementDlg 메시지 처리기

BOOL CFriendManagementDlg::OnInitDialog()
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
	DWORD dwStyle = m_ctrlFriendList.GetExtendedStyle();
	m_ctrlFriendList.SetExtendedStyle(dwStyle | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES );

	static CImageList imgListSmall;
	imgListSmall.Create(16, 16, ILC_COLOR32, 2, 0);	
	imgListSmall.Add(AfxGetApp()->LoadIcon(IDI_MALE));
	imgListSmall.Add(AfxGetApp()->LoadIcon(IDI_FEMALE));
	m_ctrlFriendList.SetImageList(&imgListSmall, LVSIL_SMALL);

	m_ctrlFriendList.InsertColumn(0, _T("이름"), 0, 100);
	m_ctrlFriendList.InsertColumn(1, _T("나이"), 0, 200);
	m_ctrlFriendList.InsertColumn(2, _T("성별"), 0, 100);

	m_ctrlSpin.SetRange(0, 100);
	m_ctrlSpin.SetPos(0);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CFriendManagementDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFriendManagementDlg::OnPaint()
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
HCURSOR CFriendManagementDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFriendManagementDlg::OnBnClickedBtnAdd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(1);

	if (m_nCount < 5)
	{
		m_pPerson[m_nCount].m_bGender = m_bGender;
		m_pPerson[m_nCount].m_nAge = m_nAge;
		m_pPerson[m_nCount].m_strName = m_strName;
		m_nCount++;
	}
	else
	{
		AfxMessageBox(_T("메모리가 꽉찼음"));
		return;
	}
	

	CString strAge;
	strAge.Format(_T("%d"), m_nAge);

	m_ctrlFriendList.InsertItem(0, m_strName, m_bGender);
	//m_ctrlFriendList.SetItemText(0, 0, m_strName);
	m_ctrlFriendList.SetItemText(0, 1, strAge);
	m_ctrlFriendList.SetItemText(0, 2, m_bGender == 0 ?_T("남성"):_T("여성"));

}


void CFriendManagementDlg::OnEnUpdateAge()
{
	if (m_ctrlSpin.GetSafeHwnd())//태어났으면 GetSafeHwnd 가 ture
		m_nAge = m_ctrlSpin.GetPos();
}

void CFriendManagementDlg::OnBnClickedBtnDEL()//삭제
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nCount = m_ctrlFriendList.GetItemCount();

	for (int i = nCount - 1; i >= 0; i--)
	{
		if (m_ctrlFriendList.GetCheck(i))
		{
			m_ctrlFriendList.DeleteItem(i);
			m_pPerson[m_nCount].m_bGender = 0;
			m_pPerson[m_nCount].m_nAge = 0;
			m_pPerson[m_nCount].m_strName =_T("");
			m_nCount--;
		}
			
	}
}


void CFriendManagementDlg::OnBnClickedBtnUPDATE()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(1);
	int nCount = m_ctrlFriendList.GetItemCount();

	for (int i = nCount - 1; i >= 0; i--)
	{
		if (m_ctrlFriendList.GetCheck(i))
			m_ctrlFriendList.SetItemText(i, 0, m_strName);
	}
}


void CFriendManagementDlg::OnLvnEndlabeleditList(NMHDR* pNMHDR, LRESULT* pResult)
{
	NMLVDISPINFO* pDispInfo = reinterpret_cast<NMLVDISPINFO*>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CEdit* pEdit = m_ctrlFriendList.GetEditControl();
	CString strTemp;
	pEdit->GetWindowText(strTemp);
	//AfxMessageBox(strTemp);
	m_ctrlFriendList.SetItemText(pDispInfo->item.iItem, 0, strTemp);

	*pResult = 0;
}


void CFriendManagementDlg::OnBnClickedSave()
{
	//대화상자 
	CFileDialog a(FALSE);
	int nResult = a.DoModal();
	
	if (nResult != IDOK) return;

	m_Path= a.GetPathName(); //경로얻어오기

	// ////////////////////////////
	CFile file((m_Path),
		CFile::modeCreate | CFile::modeReadWrite);	//사용할 파일을 선언.

	CArchive ar(&file, CArchive::store);//아키브를 만들고 위의파일과 연결하고, store는 저장용, load는 가져오기

	ar << m_nCount;
	for (int i = 0; i < m_nCount; i++)
	{
		m_pPerson[i].Serialize(ar);
	}
	//////////////////////////////////////
	//메모리와 화면 초기화.
	/*
	for (int i = 0; i <m_nCount; i++)
	{
		m_ctrlFriendList.DeleteItem(0);
		m_pPerson[i].m_bGender = 0;
		m_pPerson[i].m_nAge = 0;
		m_pPerson[i].m_strName = _T("");
	}
	*/

	m_nCount = 0;//메모리초기화
	m_ctrlFriendList.DeleteAllItems();//화면초기화
}


void CFriendManagementDlg::OnBnClickedLoad()
{

	//대화상자 
	CFileDialog a(TRUE);
	int nResult = a.DoModal();

	if (nResult != IDOK) return;
	m_Path = a.GetPathName(); //경로얻어오기
	/////////////////////////////////////////

	m_nCount = 0;//메모리초기화
	m_ctrlFriendList.DeleteAllItems();//화면초기화

	/////////////////////////////////////////
	CFile file((m_Path),
		 CFile::modeRead);	//사용할 파일을 선언.

	CArchive ar(&file, CArchive::load);//아키브를 만들고 위의파일과 연결하고, store는 저장용, load는 가져오기

	ar >> m_nCount;
	for (int i = 0; i < m_nCount; i++)
	{
		m_pPerson[i].Serialize(ar);
	}
	/////////////////////
	//화면에 표시
	CString strAge;
	for (int i = 0; i < m_nCount; i++)
	{
		strAge.Format(_T("%d"), m_pPerson[i].m_nAge);

		m_ctrlFriendList.InsertItem(0, m_pPerson[i].m_strName, m_pPerson[i].m_bGender);
		m_ctrlFriendList.SetItemText(0, 1, strAge);
		m_ctrlFriendList.SetItemText(0, 2, m_pPerson[i].m_bGender == 0 ? _T("남성") : _T("여성"));
	}

}
