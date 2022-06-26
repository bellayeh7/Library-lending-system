// AddUser.cpp: 实现文件
//

#include "pch.h"
#include "mtest.h"
#include "AddUser.h"
#include "afxdialogex.h"
#include "DataBase.h"


// AddUser 对话框

IMPLEMENT_DYNAMIC(AddUser, CDialogEx)

AddUser::AddUser(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG4, pParent)
	, m_name(_T(""))
	, m_pass(_T(""))
{

}

AddUser::~AddUser()
{
}

void AddUser::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_Text(pDX, IDC_EDIT2, m_pass);
}


BEGIN_MESSAGE_MAP(AddUser, CDialogEx)
	ON_BN_CLICKED(IDOK, &AddUser::OnBnClickedOk)
END_MESSAGE_MAP()


// AddUser 消息处理程序


void AddUser::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	
	UpdateData(true);

	//调用类的静态函数 连上数据库
	MYSQL m_sqlCon = DataBase::getCon();

	char insert[1000];
	sprintf_s(insert, "insert into t_user values(0, \'%s\', \'%s\')",
		m_name, m_pass);

	//执行语句
	if (mysql_query(&m_sqlCon, insert) == 0) {
		//直接改变文本框的内容
		GetDlgItem(ID_SHOW)->SetWindowTextA("添加成功");
	}
	else {
		GetDlgItem(ID_SHOW)->SetWindowTextA("添加失败");
	}
	mysql_close(&m_sqlCon);//关闭Mysql连接 

	cm->tst();

	CDialogEx::OnOK();

}
