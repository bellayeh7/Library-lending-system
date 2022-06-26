// UpDateUser.cpp: 实现文件
//

#include "pch.h"
#include "c.h"
#include "UpDateUser.h"
#include "afxdialogex.h"
#include "Database.h"
#include<iostream>
using namespace std;


// UpDateUser 对话框

IMPLEMENT_DYNAMIC(UpDateUser, CDialogEx)

UpDateUser::UpDateUser(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG4, pParent)
	, u_na(_T(""))
	, u_nu(_T(""))
	, u_ad(_T(""))
{

}

UpDateUser::~UpDateUser()
{
}

void UpDateUser::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, u_na);
	DDX_Text(pDX, IDC_EDIT2, u_nu);
	DDX_Text(pDX, IDC_EDIT3, u_ad);
}


BEGIN_MESSAGE_MAP(UpDateUser, CDialogEx)
	ON_BN_CLICKED(IDOK, &UpDateUser::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT2, &UpDateUser::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT1, &UpDateUser::OnEnChangeEdit1)
END_MESSAGE_MAP()


// UpDateUser 消息处理程序


void UpDateUser::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
	UpdateData(true);
	MYSQL m_sqlCon = Database::getCon();
	char update[1000];
	sprintf_s(update, "update b_user set name='%s',number='%s',address='%s' where id='%s'", u_na, u_nu, u_ad,u_id);
	if (mysql_query(&m_sqlCon, update) == 0)
	{
		//直接改变文本框的内容
		GetDlgItem(IDC_STATIC4)->SetWindowTextA("修改成功！");
	}
	else {
		GetDlgItem(IDC_STATIC4)->SetWindowTextA("修改失败！");
	}
	mysql_close(&m_sqlCon);
}


void UpDateUser::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
void UpDateUser::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}