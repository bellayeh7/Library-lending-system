#pragma once

class User:CObject
{
	
	public:
		User();
		
	private:
		CString name;
		CString pass;

	public:
		CString getName();
		void setName(CString name);

};

