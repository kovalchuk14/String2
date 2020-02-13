#include <iostream>

class Box
{
	double width;
	double height;
	double lenght;
	bool closed;
public:
	Box(double width, double height, double lenght) :width(width), height(height), lenght(lenght),closed(true)
	{
		std::cout << "BoxConstructor:\t" << this << std::endl;
	}
	~Box()
	{
		std::cout << "BoxDestructor:\t" << this << std::endl;
	}

	void open()
	{
			closed = false;
	}
	void close()
	{
			closed = true;
	}
	void get_status()const
	{
		std::cout << "Box is " << (closed ? "closed" : "opened") << std::endl;
	}
};

class GiftBox :public Box
{
	std::string color;
	bool bant;
public:
	GiftBox(double width, double height, double lenght, std::string color):Box(width,height,lenght)
	{
		std::cout << "GBConstructor:\t" << this << std::endl;
	}
	~GiftBox()
	{
		std::cout << "GBDestructor:\t" << this << std::endl;
	}
};

void main()
{
	GiftBox box2(2,2,1,"green");
	box2.get_status();
}
