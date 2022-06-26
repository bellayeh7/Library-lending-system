#pragma once


// UpDateUser 对话框

class UpDateUser : public CDialogEx
{
	DECLARE_DYNAMIC(UpDateUser)

public:
	UpDateUser(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~UpDateUser();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString u_na;
	afx_msg void OnEnChangeEdit2();
	CString u_nu;
	CString u_ad;
	afx_msg void OnEnChangeEdit1();
	CString u_id;
};
