#pragma once
#include "Database.h"
#include "winsock.h"
#include "mysql.h"
#include<iostream>
class Database
{
	//����һ���������ݿ�ĺ����������������ط�ֱ��ʹ��
public:
	static MYSQL getCon();
	static std::string string_To_UTF8(const std::string & strSrc);
};