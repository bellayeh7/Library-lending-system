#pragma once

#include "DataBase.h"
#include "winsock.h" 
#include "mysql.h"

class DataBase
{
	//����һ���������ݿ�ĺ����������������ط�ֱ��ʹ��
	public:
		static MYSQL getCon();
};

