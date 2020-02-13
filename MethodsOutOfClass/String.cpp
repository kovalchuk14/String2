#include "String.h"
///////////////////////////////////////////////////////////////////////////////
/////////////////////////CLASS DEFINITION//////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
int String::get_size()const
{
	return this->size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}
void String::set_str(const char* str)
{
	delete[] this->str;
	this->size = strlen(str) + 1;
	this->str = new char[size] {};
	strcpy(this->str, str);
}
String::String(int size) :size(size), str(new char[size] {})
{
	//this->size = size;
	//this->str = new char[size] {};
	std::cout << "DefaultConstructor:\t" << this << std::endl;
}
String::String(const char* str) :String(strlen(str) + 1)
{
	//this->size = strlen(str) + 1;
	//this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = str[i];
	std::cout << "Constructor:\t" << this << std::endl;
}
String::String(const String& other) :String(other.str)
{
	/*this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i]; */
	//strcpy(this->str, other.str);
	std::cout << "CopyConstructor:\t" << this << std::endl;
}
String::String(String&& other) :size(other.size), str(other.str)
{
	/*this->size = other.size;
	this->str = other.str;*/
	other.str = nullptr;
	std::cout << " Move Construnctor:\t" << this << std::endl;
}
String& String::operator= (String && other)
{
	delete str;
	this->str = other.str;
	other.str = nullptr;
	std::cout << "Move assignment\t" << this << std::endl;
	return *this;
}
String::~String()
{
	delete[] this->str;
	std::cout << "Destructor:\t" << this << std::endl;
}
String& String::operator=(const String& other)
{
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	strcpy(this->str, other.str);
	std::cout << "CopyAssignment:" << this << std::endl;
	return *this;
}


String& String::operator+=(const String& other)
{
	return *this = *this + other;
}

const char& String::operator[](int i)const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}
//methods
void String::print()
{
	std::cout << size << "\t" << str << std::endl;
}
/////////////////////////////////OUT OF CLASS//////////////////////////////////

String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
	{
		cat[i] = left[i];

	}
	for (int i = 0; i < right.get_size(); i++)
	{
		cat[i + left.get_size() - 1] = right[i];
	}

	return cat;
}
bool operator==(const String& left, const String& right)
{
	if (strlen(left.get_str()) != strlen(right.get_str()))return false;
	for (int i = 0; left[i] != 0 && right[i] != 0; i++)
	{
		if (left[i] != right[i])return false;
	}
	return true;
}
bool operator<(const String& left, const String& right)
{
	/*if (strcmp(left.get_str(), right.get_str()) < 0)return true;
	else return false;*/
	return strcmp(left.get_str(), right.get_str()) < 0 ? true : false;

}
bool operator>(const String& left, const String& right)
{
	return strcmp(left.get_str(), right.get_str()) > 0 ? true : false;
}

bool operator!=(const String& left, const String& right)
{
	return !(left == right);
}
/////////////////////////////////OUT OF CLASS//////////////////////////////////

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	/*if (!obj.get_numerator())
	{
	std::cout << obj.get_integer() << std::endl;
	}
	else if (!obj.get_integer())
	{
	std::cout << obj.get_numerator() << "/" << obj.get_denominator() << std::endl;
	}
	else
	{
	std::cout << obj.get_integer() << " [" << obj.get_numerator() << "/" << obj.get_denominator() << "]" << std::endl;
	}*/
	return os << obj.get_str();
}
std::istream& operator>>(std::istream& is, String& obj)
{
	char* sz_str = new char[USHRT_MAX] {};
	is >> sz_str;
	sz_str = (char*)realloc(sz_str, strlen(sz_str) + 1);
	obj.set_str(sz_str);
	delete[]sz_str;
	return is;
}
///////////////////////////////////////////////////////////////////////////////
/////////////////////////CLASS DEFINITION-END//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
