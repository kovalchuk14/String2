#pragma once
#include<iostream>

///////////////////////////////////////////////////////////////////////////////
/////////////////////////CLASS DECLARATION/////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

class String;
String operator+(const String& left, const String& rignt);
bool operator==(const String& left, const String& right);
bool operator<(const String& left, const String& right);
bool operator>(const String& left, const String& right);

bool operator!=(const String& left, const String& right);

class String {
	int size;
	char* str;
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();
	void set_str(const char* str);

	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other);
	String& operator= (String && other);
	~String();

	String& operator=(const String& other);
	String& operator+=(const String& other);

	const char& operator[](int i)const;
	char& operator[](int i);

	//methods
	void print();
};
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

