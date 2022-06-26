// CMyList.cpp: 实现文件
//

#include "pch.h"
#include "mtest.h"
#include "CMyList.h"
#include "afxdialogex.h"


// CMyList 对话框

IMPLEMENT_DYNAMIC(CMyList, CDialogEx)

CMyList::CMyList(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{
	

}

CMyList::~CMyList()
{
}

void CMyList::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}

BOOL CMyList::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_list.InsertColumn(0, _T("ID"), LVCFMT_LEFT, 50);
	m_list.InsertColumn(1, _T("Name"), LVCFMT_LEFT, 50);
	m_list.InsertColumn(2, _T("Age"), LVCFMT_LEFT, 50);
	m_list.InsertColumn(3, _T("Address"), LVCFMT_LEFT, 50);

	int nidx;
	nidx = m_list.InsertItem(0, _T("0001"));
	m_list.SetItemText(nidx, 1, _T("张三"));
	m_list.SetItemText(nidx, 2, _T("23"));
	m_list.SetItemText(nidx, 3, _T("地球"));

	nidx = m_list.InsertItem(1, _T("0002"));
	m_list.SetItemText(nidx, 1, _T("王五"));
	m_list.SetItemText(nidx, 2, _T("22"));
	m_list.SetItemText(nidx, 3, _T("美国"));
	return 0;
}


BEGIN_MESSAGE_MAP(CMyList, CDialogEx)
	ON_BN_CLICKED(IDOK, &CMyList::OnBnClickedOk)
END_MESSAGE_MAP()


// CMyList 消息处理程序


void CMyList::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	
}

