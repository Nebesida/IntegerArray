#pragma once
#include <iostream>

class Exception
{
public:
	Exception() {}
	virtual void Show() { std::cout << "Exception" << std::endl; }
};
