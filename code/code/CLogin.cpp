// CLogin.cpp: 实现文件
//

#include "pch.h"
#include "mtest.h"
#include "CLogin.h"
#include "afxdialogex.h"
#include "mtestDlg.h"
#include "winsock.h" 
#include "mysql.h"
#include "CMain.h"

// CLogin 对话框

IMPLEMENT_DYNAMIC(CLogin, CDialogEx)

CLogin::CLogin(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, n_na(_T(""))
	, n_pa(_T(""))
{

}

CLogin::~CLogin()
{
}

void CLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, n_na);
	DDX_Text(pDX, IDC_EDIT2, n_pa);
}


BEGIN_MESSAGE_MAP(CLogin, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &CLogin::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CLogin::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CLogin::OnBnClickedButton1)
END_MESSAGE_MAP()


// CLogin 消息处理程序


void CLogin::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();

	
}


void CLogin::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
	//更新关联变量
	//UpdateData(true);
	//MessageBox(n_na);
	//n_na = "FFFFF";
	//更新关联控件
	//UpdateData(false);

	UpdateData(true);

	//创建数据库对象
	MYSQL m_sqlCon;
	//查询的结果集
	MYSQL_RES *res;
	//初始化数据库
	mysql_init(&m_sqlCon);
	//连接数据库
	if (!mysql_real_connect(&m_sqlCon, "localhost", "root",
		"yagami", "db_hnist", 3306, NULL, 0)) {
		AfxMessageBox(_T("数据库连接失败!"));
		return;
	}
	//设置编码 防止中文乱码
	mysql_query(&m_sqlCon, "set names 'gb2312'");

	CString sql;
	sql.Format(_T("select * from t_user where name = '%s' and pass = '%s'"),n_na,n_pa);
	
	if (mysql_query(&m_sqlCon, sql) == 0) {
		
		//获取查询的结果集
		res = mysql_store_result(&m_sqlCon);
		//获取结果集的行
		if (mysql_num_rows(res) == 0) {
			AfxMessageBox(_T("登录失败，用户或者密码错误!"));
		}
		else {
			CDialogEx::OnOK();
			//AfxMessageBox(_T("登录成功!"));
			//打开主界面
			CMain cm;
			cm.DoModal();
			
		}
	}
	else {
		AfxMessageBox(_T("执行失败!"));
	}

}


void CLogin::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();

	//打开新窗口，注册
	CmtestDlg cd;
	cd.DoModal();
}
