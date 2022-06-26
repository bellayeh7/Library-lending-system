#include "pch.h"
#include "DataBase.h"

MYSQL DataBase::getCon()
{
	//创建数据库对象
	MYSQL m_sqlCon;
	//初始化数据库
	mysql_init(&m_sqlCon);
	//连接数据库
	if (!mysql_real_connect(&m_sqlCon, "localhost", "root",
		"yagami", "db_hnist", 3306, NULL, 0)) {
		AfxMessageBox(_T("数据库连接失败!"));
		return m_sqlCon;
	}
	//设置编码 防止中文乱码
	mysql_query(&m_sqlCon, "set names 'gb2312'");
	return m_sqlCon;
}
