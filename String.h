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
	//class ����ָ���Ա  ��Ҫ copy ���� ��copy��ֵ  ������������ͷ
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
		m_data = new char[l];//+1 ����ΪĩβҪ��\0��
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
	//���str��������Լ�����delete�ᵼ��str.m_data û��ֵ
	if (this == &str)
	{
		return *this;
	}

	//��ֵcopy 1.˵���Ѿ���String  ��Ҫ��delete 2.Ȼ��copy

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
