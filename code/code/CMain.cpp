// CMain.cpp: 实现文件
//

#include "pch.h"
#include "mtest.h"
#include "CMain.h"
#include "afxdialogex.h"
#include <iostream>
#include <string>
#include "winsock.h" 
#include "mysql.h"

// CMain 对话框

IMPLEMENT_DYNAMIC(CMain, CDialogEx)

CMain::CMain(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

CMain::~CMain()
{
}

void CMain::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(CMain, CDialogEx)
	ON_BN_CLICKED(IDOK, &CMain::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON3, &CMain::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CMain::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMain 消息处理程序


void CMain::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CMain::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMain::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
}


BOOL CMain::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//列表的表头
	m_list.InsertColumn(0, _T("ID"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(1, _T("姓名"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(2, _T("密码"), LVCFMT_LEFT, 100);

	//列表的数据
	int nidx;

	//从数据库查询数据
	//创建数据库对象
	MYSQL m_sqlCon;
	//查询的结果集
	MYSQL_RES *res;
	//结果集的一行数据对象
	MYSQL_ROW row;

	//初始化数据库
	mysql_init(&m_sqlCon);
	//连接数据库
	if (!mysql_real_connect(&m_sqlCon, "localhost", "root",
		"yagami", "db_hnist", 3306, NULL, 0)) {
		AfxMessageBox(_T("数据库连接失败!"));
		return false;
	}
	//设置编码 防止中文乱码
	mysql_query(&m_sqlCon, "set names 'gb2312'");

	CString sql;
	sql.Format(_T("select * from t_user"));

	if (mysql_query(&m_sqlCon, sql) == 0) {

		//获取查询的结果集
		res = mysql_store_result(&m_sqlCon);
		//把结果集真实数据显示到列表
		//重复读取行，把数据放入列表中，直到row为NULL
		int i = 0;
		while (row = mysql_fetch_row(res))
		{
			//row[0];
			//row[1];
			//取每一行的每一列数据
			CString id(row[0]);
			CString na(row[1]);
			CString pa(row[2]);
			nidx = m_list.InsertItem(i, id);
			//给行列的位置设置内容  1：行号    2：列号   3：内容
			m_list.SetItemText(nidx, 1, na);
			m_list.SetItemText(nidx, 2, pa);
			i++;
		}
	}


	/*for (int i = 0; i < 20; i++)
	{
		//插入一行记录，并返回行号
		CString c1,c2,c3;
		c1.Format(_T("00%d"), i);
		c2.Format(_T("张三%d"), i);
		c3.Format(_T("66%d"), i);
		nidx = m_list.InsertItem(i, c1);
		//给行列的位置设置内容  1：行号    2：列号   3：内容
		m_list.SetItemText(nidx, 1, c2);
		m_list.SetItemText(nidx, 2, c3);
	}*/

	


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
