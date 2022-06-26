#include "pch.h"
#include "Database.h"

MYSQL Database::getCon()
{
	MYSQL m_sqlCon;
	mysql_init(&m_sqlCon);
	if (!mysql_real_connect(&m_sqlCon, "localhost", "root",
		"117540", "t_user", 3306, NULL, 0)) {
		AfxMessageBox(_T("数据库连接失败!"));
		return m_sqlCon;
	}
	mysql_query(&m_sqlCon, "set names 'gb2312'");
	return m_sqlCon;
}
std::string Database::string_To_UTF8(const std::string & strSrc)
{
	return std::string();
}
std::string string_To_UTF8(const std::string & str)
{
	int nwLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);

	wchar_t * pwBuf = new wchar_t[nwLen + 1];//一定要加1，不然会出现尾巴
	ZeroMemory(pwBuf, nwLen * 2 + 2);

	::MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), pwBuf, nwLen);

	int nLen = ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, -1, NULL, NULL, NULL, NULL);

	char * pBuf = new char[nLen + 1];
	ZeroMemory(pBuf, nLen + 1);

	::WideCharToMultiByte(CP_UTF8, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);

	std::string retStr(pBuf);

	delete[]pwBuf;
	delete[]pBuf;

	pwBuf = NULL;
	pBuf = NULL;

	return retStr;
}
