#pragma once


// Main 对话框

class Main : public CDialogEx
{
	DECLARE_DYNAMIC(Main)

public:
	Main(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Main();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	CListCtrl m_list;
	virtual BOOL OnInitDialog();
	void tst();
};
