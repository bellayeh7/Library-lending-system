#include "pch.h"
#include "DataBase.h"

MYSQL DataBase::getCon()
{
	//�������ݿ����
	MYSQL m_sqlCon;
	//��ʼ�����ݿ�
	mysql_init(&m_sqlCon);
	//�������ݿ�
	if (!mysql_real_connect(&m_sqlCon, "localhost", "root",
		"yagami", "db_hnist", 3306, NULL, 0)) {
		AfxMessageBox(_T("���ݿ�����ʧ��!"));
		return m_sqlCon;
	}
	//���ñ��� ��ֹ��������
	mysql_query(&m_sqlCon, "set names 'gb2312'");
	return m_sqlCon;
}
