#pragma once


// DeleteUser 对话框

class DeleteUser : public CDialogEx
{
	DECLARE_DYNAMIC(DeleteUser)

public:
	DeleteUser(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DeleteUser();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString d_na;
	CString d_nu;
	CString d_ad;
	CString d_id;
	afx_msg void OnStnClickedStatic6();
};
