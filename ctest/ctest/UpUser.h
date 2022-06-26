#pragma once


// UpUser 对话框

class UpUser : public CDialogEx
{
	DECLARE_DYNAMIC(UpUser)

public:
	UpUser(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~UpUser();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_name;
	CString m_pass;
	CString m_id;
};
