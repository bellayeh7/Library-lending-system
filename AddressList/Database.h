#pragma once
#include "Database.h"
#include "winsock.h"
#include "mysql.h"
#include<iostream>
class Database
{
	//定义一个链接数据库的函数，方便在其他地方直接使用
public:
	static MYSQL getCon();
	static std::string string_To_UTF8(const std::string & strSrc);
};