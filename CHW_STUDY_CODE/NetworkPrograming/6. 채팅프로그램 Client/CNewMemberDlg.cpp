// CNewMemberDlg.cpp: 구현 파일
//

#include "pch.h"
#include "0608채팅프로그램Client.h"
#include "CNewMemberDlg.h"
#include "afxdialogex.h"


// CNewMemberDlg 대화 상자

IMPLEMENT_DYNAMIC(CNewMemberDlg, CDialogEx)

CNewMemberDlg::CNewMemberDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ADD, pParent)
	, m_strID(_T(""))
	, m_strPassword(_T(""))
	, m_strName(_T(""))
{

}

CNewMemberDlg::~CNewMemberDlg()
{
}

void CNewMemberDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strID);
	DDX_Text(pDX, IDC_EDIT2, m_strPassword);
	DDX_Text(pDX, IDC_EDIT3, m_strName);
}


BEGIN_MESSAGE_MAP(CNewMemberDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_CHECK, &CNewMemberDlg::OnBnClickedButtonCheck)
	ON_BN_CLICKED(IDC_BUTTON_ADD2, &CNewMemberDlg::OnBnClickedButtonAdd2)
END_MESSAGE_MAP()


// CNewMemberDlg 메시지 처리기

//중복체크
void CNewMemberDlg::OnBnClickedButtonCheck()
{
	UpdateData(1);
	m_strID; 

	//서버로 전송하는 코드

}


void CNewMemberDlg::OnBnClickedButtonAdd2()
{
	//UpdateData(1);
	//if (dlg.DoModal() == IDOK)
	CNewMemberDlg::OnOK();	//해당 Dlg 종료하는 코드.?, 확인버튼을 누르면 꺼지는것 위의 2 코드의 기능을 얘가 가지고있음.
	//CMy0608채팅프로그램ClientDlg::OnBnClickedButtonAdd() 로 넘어감.
}


void CNewMemberDlg::GetData(CString& id, CString& pw, CString& name)	//레퍼런스 매개변수
{
	// TODO: 여기에 구현 코드 추가.
	id = m_strID;
	pw = m_strPassword;
	name = m_strName;
}


