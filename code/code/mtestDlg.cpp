
// mtestDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "mtest.h"
#include "mtestDlg.h"
#include "afxdialogex.h"
#include <iostream>
#include "CLogin.h"
//因为数据库是通过网络连接的，必须包含网络相关头文件  
#include "winsock.h"
//这个没什么好说的，mysql头文件自然要包含    
#include "mysql.h"


using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CmtestDlg 对话框



CmtestDlg::CmtestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MTEST_DIALOG, pParent)
	, n_name(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmtestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT3, n_name);
}

BEGIN_MESSAGE_MAP(CmtestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CmtestDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CmtestDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CmtestDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CmtestDlg 消息处理程序

BOOL CmtestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CmtestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CmtestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CmtestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





void CmtestDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
	//Reg("ff");
	//AfxMessageBox(_T("查询结束!"));
	
}


void CmtestDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
	//MessageBox(L"6666");
	CString sna;
	CString spa;
	//获取某个控件的text内容
	GetDlgItemText(IDC_EDIT3,sna);
	//直接根据ID获取控件对象
	GetDlgItem(IDC_EDIT4)->GetWindowTextA(spa);

	//连接数据库，插入注册信息
	//创建数据库对象
	MYSQL m_sqlCon;
	//初始化数据库
	mysql_init(&m_sqlCon);
	//连接数据库
	if (!mysql_real_connect(&m_sqlCon, "localhost", "root",
		"yagami", "db_hnist", 3306, NULL, 0)) {
		AfxMessageBox(_T("数据库连接失败!"));
		return;
	}
	else {
		AfxMessageBox(_T("数据库连接成功!"));
	}
	//设置编码 防止中文乱码
	mysql_query(&m_sqlCon, "set names 'gb2312'");

	//创建查询语句
	char insert[1000];
	sprintf_s(insert, "insert into t_user values(0, \'%s\', \'%s\')",
		sna, spa);

	//执行语句
	if (mysql_query(&m_sqlCon, insert) == 0) {
		AfxMessageBox(_T("插入成功!"));
	}
	else {
		AfxMessageBox(_T("插入失败!"));
	}
	mysql_close(&m_sqlCon);//关闭Mysql连接 
}

MYSQL_RES *m_res;
MYSQL_ROW row;
void CmtestDlg::Reg(CString na) {
	MYSQL m_sqlCon;
	mysql_init(&m_sqlCon);

	if (!mysql_real_connect(&m_sqlCon, "localhost",
		"root","yagami", "db_hnist", 3306, NULL, 0))
	{
		AfxMessageBox(_T("数据库连接失败!"));
		return;
	}
	else//连接成功则继续访问数据库，之后的相关操作代码基本是放在这里面的  
	{
		mysql_query(&m_sqlCon, "set names 'gb2312'");
		const char *sql = "select * from t_user";
		//执行查询
		mysql_query(&m_sqlCon, sql);
		m_res = mysql_store_result(&m_sqlCon);
		//如果为空则返回

		if (NULL == m_res)
		{
			AfxMessageBox("NULL");
			return;
		}

		//重复读取行，把数据放入列表中，直到row为NULL
		while (row = mysql_fetch_row(m_res))
		{
			for (int rols = 0; rols < 2; rols++)
			{
				CString md(row[rols]);
			}
		}
	}


}

void CmtestDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
	CLogin dlg;
	dlg.DoModal();
}
