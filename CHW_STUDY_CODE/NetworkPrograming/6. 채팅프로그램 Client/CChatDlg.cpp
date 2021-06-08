// CChatDlg.cpp: 구현 파일
//

#include "pch.h"
#include "0608채팅프로그램Client.h"
#include "CChatDlg.h"
#include "afxdialogex.h"
#include"ChatControl.h"

CChatDlg* g_pDlg = NULL;
// CChatDlg 대화 상자

IMPLEMENT_DYNAMIC(CChatDlg, CDialogEx)

CChatDlg::CChatDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_CHATTING, pParent)
	, m_strshortmessage(_T(""))
	, m_strMemo(_T(""))
{
	ChatControl::getInsatnce()->ParentForm(this);
	g_pDlg = this;
}

CChatDlg::~CChatDlg()
{
}

void CChatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strshortmessage);
	DDX_Control(pDX, IDC_EDIT_CHAT, m_ctrlList);
	DDX_Text(pDX, IDC_EDIT_NOTE, m_strMemo);
}


BEGIN_MESSAGE_MAP(CChatDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SEND, &CChatDlg::OnBnClickedButtonSend)
	ON_MESSAGE(EVENT_SENDMESSAGE, &CChatDlg::OnMyMessage)//크로스쓰레드를 막기위해 사용
	ON_MESSAGE(EVENT_MEMOMESSAGE, &CChatDlg::OnMyMemoMessage)
	ON_BN_CLICKED(IDC_BUTTON_SEND2, &CChatDlg::OnBnClickedButtonSend2)
END_MESSAGE_MAP()


// CChatDlg 메시지 처리기




void CChatDlg::SendData(CString name)
{
	//여기서 set을 하면 폼이 생성되기 전이라 터져서 일단 값만 바꾸고 폼이 뜰때 위에 표시해준다
	m_name = name;
}


BOOL CChatDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CString str;
	str.Format("%s님이 로그인 하셨습니다", m_name);
	SetWindowText(str);

	return TRUE;  
}




// 채팅에대한 전송버튼
void CChatDlg::OnBnClickedButtonSend()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(1);
	if (m_strshortmessage == "")
	{
		return;
	}

	ChatControl::getInsatnce()->ShortMessage(m_name, m_strshortmessage);
	m_strshortmessage = "";
	UpdateData(0);
}

void CChatDlg::MemoMessage(PACKETMEMO* msg) //문제
{

	g_pDlg->PostMessage(EVENT_MEMOMESSAGE, (WPARAM)msg, 0);

}
LRESULT CChatDlg::OnMyMemoMessage(WPARAM wParam, LPARAM lParam)
{
	PACKETMEMO* p = (PACKETMEMO*)wParam;

	m_strMemo = p->msg;
	UpdateData(0);
	return 0;

}


PACKETSHORTMESSAGE* g_msg;
void CChatDlg::ShortMessage(PACKETSHORTMESSAGE* msg)
{
	// TODO: 여기에 구현 코드 추가.
	g_msg = msg;
	g_pDlg->PostMessage(EVENT_SENDMESSAGE, (WPARAM)msg, 0); //LRESULT CChatDlg::OnMyMessage(WPARAM wParam, LPARAM lParam)함수호출

	
	//DisplayText("[%s]%s(%d:%d:%d)",	크로스 스레드
		//msg->name, msg->msg, msg->hour, msg->min, msg->second);	크로스 쓰레드
}




// 에디트 컨트롤에 문자열 출력
void CChatDlg::DisplayText(char* fmt, ...)	//...은 가변형 파라메타
{
	va_list arg;			va_start(arg, fmt);

	char cbuf[512 + 256];	vsprintf_s(cbuf, fmt, arg);
	
	//크로스 쓰레드 문제발생
	//컨트롤을 생성한 쓰레드(primary thread)
	//컨트롤을 사용하는 쓰레드가 다를 경우 발생하는 문제.
	// send message는 자기 쓰레드에서 돌아가고, postmessage는 메인쓰레드로 돌아간다. 그래서 mfc에서 크로쓰쓰레드를 막기위해 post를 쓴다.
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_CHAT);
	int nLength = pEdit->GetWindowTextLength();
	pEdit->SetSel(nLength, nLength);
	pEdit->ReplaceSel(cbuf);


	//int nLength = m_ctrlList.GetWindowTextLength();
	//m_ctrlList.SetSel(nLength, nLength);
	//m_ctrlList.ReplaceSel(cbuf);

	//int nLength = GetWindowTextLength(hEdit2);	//주석처리된것은 win32 함수.
	//SendMessage(hEdit2, EM_SETSEL, nLength, nLength);
	//SendMessage(hEdit2, EM_REPLACESEL, FALSE, (LPARAM)cbuf);
	va_end(arg);
}

LRESULT CChatDlg::OnMyMessage(WPARAM wParam, LPARAM lParam)
{
	PACKETSHORTMESSAGE* p = (PACKETSHORTMESSAGE*)wParam;
	DisplayText("[%s]%s(%d:%d:%d)\n",	
		p->name, p->msg, p->hour, p->min, p->second);
	return 0;
}

//쪽지보내기
void CChatDlg::OnBnClickedButtonSend2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(1);
	if (m_strMemo == "")
	{
		return;
	}

	ChatControl::getInsatnce()->MemoMessage(m_name, m_strMemo);
	m_strMemo = "";
	UpdateData(0);
}

