// AddUser.cpp: 实现文件
//

#include "pch.h"
#include "c.h"
#include "AddUser.h"
#include "afxdialogex.h"
#include "Database.h"
#include<iostream>
using namespace std;


// AddUser 对话框

IMPLEMENT_DYNAMIC(AddUser, CDialogEx)

AddUser::AddUser(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, m_name(_T(""))
	, m_pass(_T(""))
	, m_address(_T(""))
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
	DDX_Text(pDX, IDC_EDIT3, m_address);
}


BEGIN_MESSAGE_MAP(AddUser, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT2, &AddUser::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT1, &AddUser::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &AddUser::OnBnClickedButton1)
	ON_STN_CLICKED(ID_SHOW, &AddUser::OnStnClickedShow)
END_MESSAGE_MAP()


// AddUser 消息处理程序


void AddUser::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void AddUser::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void AddUser::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//m->tst();
	CDialogEx::OnOK();
	UpdateData(true);
	MYSQL m_sqlCon = Database::getCon();
	char insert[1000];
	sprintf_s(insert, "insert into b_user values(0,\'%s\',\'%s\',\'%s\')", m_name, m_pass,m_address);
	if (mysql_query(&m_sqlCon, insert) == 0)
	{
		//直接改变文本框的内容
		GetDlgItem(ID_SHOW)->SetWindowTextA("添加成功！");
	}
	else {
		GetDlgItem(ID_SHOW)->SetWindowTextA("添加失败！");
	}
	mysql_close(&m_sqlCon);
	m->tst();
		
}


void AddUser::OnStnClickedShow()
{
	// TODO: 在此添加控件通知处理程序代码
}
