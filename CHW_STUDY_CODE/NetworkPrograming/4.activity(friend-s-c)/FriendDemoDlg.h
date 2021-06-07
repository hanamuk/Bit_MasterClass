
// FriendDemoDlg.h: 헤더 파일
//

#pragma once
#include"CPerson.h"
#include "Control.h"
#include"packet.h"

class Control;

// CFriendDemoDlg 대화 상자
class CFriendDemoDlg : public CDialogEx
{
// 생성입니다.
public:
	CFriendDemoDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FRIENDDEMO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.

private :
	Control* pcon;

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
	CListCtrl m_ctrlLIst;
	CString m_strName;
	int m_nAge;
	BOOL m_bGender;
	int m_nCount;
	afx_msg void OnBnClickedBtnAdd();
	CSpinButtonCtrl m_ctrlSpin;
	CPerson m_pPerson[5];
	afx_msg void OnBnClickedBtnDel();
	afx_msg void OnBnClickedBtnUpdate();
	afx_msg void OnEnUpdateAge();
	afx_msg void OnLvnEndlabeleditList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedLoad();
	afx_msg void OnBnClickedSave();
	void AddList(const char* name, int age, bool gender);
	void ListAll(PACKLISTALL* list);
};
