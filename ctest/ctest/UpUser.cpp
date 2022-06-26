// UpUser.cpp: 实现文件
//

#include "pch.h"
#include "mtest.h"
#include "UpUser.h"
#include "afxdialogex.h"


// UpUser 对话框

IMPLEMENT_DYNAMIC(UpUser, CDialogEx)

UpUser::UpUser(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG5, pParent)
{

}

UpUser::~UpUser()
{
}

void UpUser::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_Text(pDX, IDC_EDIT2, m_pass);
}


BEGIN_MESSAGE_MAP(UpUser, CDialogEx)
END_MESSAGE_MAP()


// UpUser 消息处理程序
