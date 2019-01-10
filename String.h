#pragma once

#include <string>
#include <iostream>
using namespace std;

class String
{
public:
	String(const char* cstr = 0);
	String(const String& str);
	~String();
	String& operator=(const String& str);
	//class 中有指针成员  需要 copy 构造 和copy赋值  析构函数三巨头
	char* get_c_str() const { return m_data; }
private:
	char *m_data;
};

ostream& operator<<(ostream& os, const String& str);

ostream& operator<<(ostream& os, const String& str)
{
	return os << str.get_c_str() << endl;
}

inline String::String(const char* cstr)
{
	if (cstr)
	{
		int l = strlen(cstr) + 1;
		m_data = new char[l];//+1 是因为末尾要‘\0’
		strcpy_s(m_data,l, cstr);
	}
	else {
		m_data = new char[1];
		*m_data = '\0';
	}
}
inline String::String(const String& str)
{
	int l = strlen(str.m_data) + 1;
	m_data = new char[l];
	strcpy_s(m_data, l,str.m_data);
}

inline String& String::operator=(const String& str) 
{
	//如果str传入的是自己本身，delete会导致str.m_data 没有值
	if (this == &str)
	{
		return *this;
	}

	//赋值copy 1.说明已经有String  需要先delete 2.然后copy

	delete[] m_data;
	int l = strlen(str.m_data) + 1;
	m_data = new char[l];
	strcpy_s(m_data,l, str.m_data);

	return *this;
}

inline String::~String()
{
	delete[] m_data;
}
