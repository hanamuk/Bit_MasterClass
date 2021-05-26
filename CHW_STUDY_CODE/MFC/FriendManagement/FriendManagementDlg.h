
// FriendManagementDlg.h: 헤더 파일
//

#pragma once


// CFriendManagementDlg 대화 상자
class CFriendManagementDlg : public CDialogEx
{
// 생성입니다.
public:
	CFriendManagementDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FRIENDMANAGEMENT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_strName;
	int m_nAge;
	BOOL m_bGender;

	CSpinButtonCtrl m_ctrlSpin;
	CListCtrl m_ctrlFriendList;
	
	afx_msg void OnBnClickedBtnAdd();
	afx_msg void OnEnUpdateAge();
	afx_msg void OnBnClickedBtnDEL();
	afx_msg void OnBnClickedBtnUPDATE();
	afx_msg void OnLvnEndlabeleditList(NMHDR* pNMHDR, LRESULT* pResult);
};
