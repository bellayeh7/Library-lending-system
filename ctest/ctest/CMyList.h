#pragma once
#include "User.h"
#include "CMain.h"

// CMyList 对话框

class CMyList : public CDialogEx
{
	DECLARE_DYNAMIC(CMyList)

public:
	CMyList(User* us, CListCtrl* m_list, CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CMyList();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
//	BOOL CMyList::OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
//	CListCtrl m_list;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	CString m_na;
	CString m_pa;
	CListCtrl* m_list;
	CMain* cm;
	User* us;
	afx_msg void OnBnClickedButton1();
};
