// CMyList.cpp: 实现文件
//

#include "pch.h"
#include "mtest.h"
#include "CMyList.h"
#include "afxdialogex.h"
#include "DbUtil.h"


// CMyList 对话框

IMPLEMENT_DYNAMIC(CMyList, CDialogEx)

CMyList::CMyList(User * us, CListCtrl* list, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_na(_T(""))
	, m_pa(_T(""))
	, us(us)
	, m_list(list)
{
	//m_list = list;
	//this->cm = cm;
	AfxMessageBox(this->us->getName());
}


CMyList::~CMyList()
{
}

void CMyList::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_na);
	DDX_Text(pDX, IDC_EDIT2, m_pa);
}

BOOL CMyList::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	return TRUE;
}


BEGIN_MESSAGE_MAP(CMyList, CDialogEx)
	ON_BN_CLICKED(IDOK, &CMyList::OnBnClickedOk)
	//ON_BN_CLICKED(IDC_BUTTON1, &CMyList::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMyList::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMyList 消息处理程序


void CMyList::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	MYSQL ms = DbUtil::getCon();
	char insert[1000];
	sprintf_s(insert, "insert into t_user values(0, \'%s\', \'%s\')",
		m_na, m_pa);

	//执行语句
	if (mysql_query(&ms, insert) == 0) {
		int nidx = m_list->InsertItem(0, "999");
		//给行列的位置设置内容  1：行号    2：列号   3：内容
		m_list->SetItemText(nidx, 1, m_na);
		m_list->SetItemText(nidx, 2, m_pa);
		AfxMessageBox(_T("插入成功!"));
	}
	else {
		AfxMessageBox(_T("插入失败!"));
	}
	mysql_close(&ms);//关闭Mysql连接 
	
}



/*void CMyList::OnBnClickedButton1()
{
	AfxMessageBox("666");
	// TODO: 在此添加控件通知处理程序代码
	//cm->tst();
	//AfxMessageBox(us->getName());
}*/



void CMyList::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	this->cm->tst();
}
