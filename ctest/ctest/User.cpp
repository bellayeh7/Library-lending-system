#include "pch.h"
#include "User.h"

User::User()
{

}

CString User::getName()
{
	return name;
}

void User::setName(CString name)
{
	this->name = name;
}
