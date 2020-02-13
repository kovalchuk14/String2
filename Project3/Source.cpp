#include<iostream>

class String;
String operator+(const String& str1, const String& str2);
class String
{
	int size;
	char* str;	//Number of bites
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	void set_str(const char* str)
	{
		delete[] this->str;
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		strcpy_s(this->str, size, str);
	}
	//		Constructors:
	explicit String(int size = 80) :size(size), str(new char[size] {})
	{
		// this-> size = size;
		//this->str = new char[size] {};
		std::cout << "DefaultConstructor:\t" << this << std::endl;
		/*std::cout << "Size:\t" << size << std::endl;*/
	}
	const char& operator[](int i) const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}
	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}
	String(const char* str) :String(strlen(str) + 1)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size];
		for (int i = 0; i < size; i++)	this->str[i] = str[i];
		std::cout << "Constructor:\t" << this << std::endl;
	}
	String(const String& other) :String(other.str)
	{
		//this->str = new char[size];
		//for (int i = 0; i < size; i++)	this->str[i] = other.str[i];
		//std::cout << "CopyConstructor:\t" << this << std::endl;
	}
	~String()
	{
		delete[] this->str;
		std::cout << "Destructor:\t" << this << std::endl;
	}

	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size];
		for (int i = 0; i < size; i++)	this->str[i] = other.str[i];
		std::cout << "CopyAssignment:\t" << this << std::endl;
		return *this;
	}

	//		Methods:
	void print()
	{
		std::cout << size << "\t" << str << std::endl;
	}
};
bool operator==(const String& left, const String& right)
{
	if (strlen(left.get_str()) != strlen(right.get_str()))return false;
	for (int i = 0; left[i] != 0; i++)
	{
		if (left[i] != right[i])return false;
	}
	return true;
}
bool operator!=(const String& left, const String& right)
{
	if (strlen(left.get_str()) != strlen(right.get_str()))return true;
	for (int i = 0; left[i] != 0; i++)
	{
		if (left[i] != right[i])return true;
	}
	return false;
}
bool operator<(const String& left, const String& right)
{
	/*if (strcmp(left.get_str(), right.get_str()) < 0 )return true;
	else return false;*/
	return strcmp(left.get_str(), right.get_str()) < 0 ? true : false;
}
bool operator>(const String& left, const String& right)
{
	/*if (strcmp(left.get_str(), right.get_str()) < 0 )return true;
	else return false;*/
	return !(left<right);
}
std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
std::istream& operator>>(std::istream& is, String& obj)
{
	char* sz_str = new char[USHRT_MAX] {};
	is >> sz_str;
	sz_str = (char*)realloc(sz_str, strlen(sz_str) + 1);
	obj.set_str(sz_str);
	delete[] sz_str;
	return is;

}
String operator+(const String& str1, const String& str2)
{
	/*String newstring(str1.get_size() + str2.get_size() - 1);
	strcat(newstring.get_str(), str1.get_str());
	strcat(newstring.get_str(), str2.get_str());
	return newstring;*/
	String cat(str1.get_size() + str2.get_size() - 1);
	for (int i = 0; i < str1.get_size(); i++)cat[i] = str1[i];
	for (int i = 0; i < str2.get_size(); i++)cat[i + str1.get_size() - 1] = str2[i];
	return cat;
}

#define BEGINNING
void main()
{
#ifdef BEGINNING
	String str1 = "Hello";
	String str2 = "";
	std::cout << (str1 < str2) << std::endl;
	/*str2.print();*/
#endif // BEG


}
