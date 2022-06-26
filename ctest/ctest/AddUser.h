#pragma once

#include "CMain.h"

// AddUser 对话框

class AddUser : public CDialogEx
{
	DECLARE_DYNAMIC(AddUser)

public:
	AddUser(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~AddUser();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_name;
	CString m_pass;
	afx_msg void OnBnClickedOk();
	CMain* cm;
};
