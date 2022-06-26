#pragma once

#include "DataBase.h"
#include "winsock.h" 
#include "mysql.h"

class DataBase
{
	//定义一个连接数据库的函数，方便在其它地方直接使用
	public:
		static MYSQL getCon();
};

