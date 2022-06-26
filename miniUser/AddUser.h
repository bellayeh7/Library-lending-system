#pragma once
#include "Main.h"


// AddUser 对话框

class AddUser : public CDialogEx
{
	DECLARE_DYNAMIC(AddUser)

public:
	AddUser(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~AddUser();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_name;
	CString m_pass;
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
	CString m_address;
	afx_msg void OnStnClickedShow();
	Main* m;
};
