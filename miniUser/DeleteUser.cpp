// DeleteUser.cpp: 实现文件
//

#include "pch.h"
#include "c.h"
#include "DeleteUser.h"
#include "afxdialogex.h"
#include "Database.h"
#include<iostream>
using namespace std;


// DeleteUser 对话框

IMPLEMENT_DYNAMIC(DeleteUser, CDialogEx)

DeleteUser::DeleteUser(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG5, pParent)
	, d_na(_T(""))
	, d_nu(_T(""))
	, d_ad(_T(""))
{

}

DeleteUser::~DeleteUser()
{
}

void DeleteUser::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, d_na);
	DDX_Text(pDX, IDC_EDIT2, d_nu);
	DDX_Text(pDX, IDC_EDIT3, d_ad);
}


BEGIN_MESSAGE_MAP(DeleteUser, CDialogEx)
	ON_BN_CLICKED(IDOK, &DeleteUser::OnBnClickedOk)
	ON_STN_CLICKED(IDC_STATIC6, &DeleteUser::OnStnClickedStatic6)
END_MESSAGE_MAP()


// DeleteUser 消息处理程序


void DeleteUser::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
	UpdateData(true);
	MYSQL m_sqlCon = Database::getCon();
	char delete1[1000];
	sprintf_s(delete1, "delete from b_user where id='%s'",d_id);
	MessageBoxA(delete1);
	if (mysql_query(&m_sqlCon, delete1) == 0)
	{
		//直接改变文本框的内容
		GetDlgItem(IDC_STATIC6)->SetWindowTextA("删除成功！");
	}
	else {
		GetDlgItem(IDC_STATIC6)->SetWindowTextA("删除失败！");
	}
	mysql_close(&m_sqlCon);
}


void DeleteUser::OnStnClickedStatic6()
{
	// TODO: 在此添加控件通知处理程序代码
}
