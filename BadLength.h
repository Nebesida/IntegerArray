#pragma once
#include "Exception.h"

class Bad_length : public Exception
{
public:
	Bad_length() {}
	virtual void Show() override { std::cout << "Bad_length" << std::endl; }
};
