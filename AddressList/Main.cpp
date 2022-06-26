// Main.cpp: 实现文件
//

#include "pch.h"
#include "c.h"
#include "Main.h"
#include "afxdialogex.h"
#include<iostream>
#include "winsock.h"
#include "mysql.h"
#include "AddUser.h"
#include "UpDateUser.h"
#include "DeleteUser.h"
#include "Database.h"
using namespace std;
// Main 对话框

IMPLEMENT_DYNAMIC(Main, CDialogEx)

Main::Main(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

Main::~Main()
{
}

void Main::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(Main, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &Main::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &Main::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Main::OnBnClickedButton2)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &Main::OnLvnItemchangedList1)
END_MESSAGE_MAP()


// Main 消息处理程序


void Main::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码 
	POSITION pos = m_list.GetFirstSelectedItemPosition();
	int sh = m_list.GetNextSelectedItem(pos);
	if (sh == -1) {
		MessageBoxA("请选择要删除的内容");
		return;
	}
	//获取列表中选中行，第0列数据
	CString d0 = m_list.GetItemText(sh, 0);
	CString d1 = m_list.GetItemText(sh, 1);
	CString d2 = m_list.GetItemText(sh, 2);
	CString d3 = m_list.GetItemText(sh, 3);
	//把整型转成字符串
	//CString cs;
	//cs.Format("good %d", nSel);
	//MessageBoxA(cs);
	DeleteUser du;
	du.d_id = d0;
	du.d_na = d1;
	du.d_nu = d2;
	du.d_ad = d3;
	du.DoModal();
	m_list.DeleteAllItems();
	Main::OnInitDialog();

}


void Main::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	AddUser au;
	//把当前主窗口的对象指针，赋给添加界面的一个主窗口属性
	au.m = this;
	au.DoModal();
	m_list.DeleteAllItems();
	Main::OnInitDialog();

}


void Main::OnBnClickedButton2()
{
	//获取选中内容的下标
	POSITION pos = m_list.GetFirstSelectedItemPosition();
	int nSel = m_list.GetNextSelectedItem(pos);
	if (nSel == -1) {
		MessageBoxA("请选择要修改的内容");
		return;
	}
	//获取列表中选中行，第0列数据
	CString s0 = m_list.GetItemText(nSel, 0);
	CString s1 = m_list.GetItemText(nSel, 1);
	CString s2 = m_list.GetItemText(nSel, 2);
	CString s3 = m_list.GetItemText(nSel, 3);
	//把整型转成字符串
	//CString cs;
	//cs.Format("good %d", nSel);
	//MessageBoxA(cs);
	UpDateUser ud;
	ud.u_id = s0;
	ud.u_na = s1;
	ud.u_nu = s2;
	ud.u_ad = s3;
	ud.DoModal();// TODO: 在此添加控件通知处理程序代码
	m_list.DeleteAllItems();
	Main::OnInitDialog();

}


void Main::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


BOOL Main::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_list.InsertColumn(0, _T("ID"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(1, _T("姓名"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(2, _T("电话号码"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(3, _T("家庭住址"), LVCFMT_LEFT, 100);
	tst();
	/*int nidx;
	MYSQL m_sqlCon;
		MYSQL_RES * res;
	MYSQL_ROW row;
	mysql_init(&m_sqlCon);
	if (!mysql_real_connect(&m_sqlCon, "localhost", "root",
		"117540", "t_user", 3306, NULL, 0)) {
		AfxMessageBox(_T("数据库连接失败!"));
		return false;
	}
	mysql_query(&m_sqlCon, "set names 'utf8'");
	CString sql;
	sql.Format(_T("select * from b_user"));
	if (mysql_query(&m_sqlCon, sql) == 0)
	{
		//获取查询的结果集
		res = mysql_store_result(&m_sqlCon);
		int i = 0;
		while (row = mysql_fetch_row(res))
		{
			//row[0];
			//row[1];
			//取每一行的每一列数据
			CString id(row[0]);
			CString na(row[1]);
			CString nu(row[2]);
			CString ad(row[3]);
			nidx = m_list.InsertItem(i, id);
			//给行列的位置设置内容  1：行号    2：列号   3：内容
			m_list.SetItemText(nidx, 1, na);
			m_list.SetItemText(nidx, 2, nu);
			m_list.SetItemText(nidx, 3, ad);
			i++;
		}
	}*/

	/*for (int i = 0; i < 20; i++)
	{
		//插入一行记录，并返回行号
		CString c1, c2, c3;
		c1.Format(_T("00"),i);
		c2.Format(_T("zhangsan"),i);
		c3.Format(_T("23"));	
		//给行列的位置设置内容 1：行号 2：列号 3：内容
		m_list.SetItemText(nidx, 1, _T("张三%d", i));
		m_list.SetItemText(nidx, 2, _T("23%d", i));
	}*/
	

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void Main::tst()
{
	//m_list.DeleteAllItems();
	//Main::OnInitDialog();
	MYSQL m_sqlCon = Database::getCon();
	MYSQL_RES *res;
	CString sql;
	MYSQL_ROW row;
	int nidx;
	sql.Format(_T("select * from b_user"));
	if (mysql_query(&m_sqlCon, sql) == 0)
	{
		//获取查询的结果集
		res = mysql_store_result(&m_sqlCon);
		int i = 0;
		while (row = mysql_fetch_row(res))
		{
			//row[0];
			//row[1];
			//取每一行的每一列数据
			CString id(row[0]);
			CString na(row[1]);
			CString nu(row[2]);
			CString ad(row[3]);
			nidx = m_list.InsertItem(i, id);
			//给行列的位置设置内容  1：行号    2：列号   3：内容
			m_list.SetItemText(nidx, 1, na);
			m_list.SetItemText(nidx, 2, nu);
			m_list.SetItemText(nidx, 3, ad);
			i++;
		}
	}
}
