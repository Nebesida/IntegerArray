#pragma once
#include "Exception.h"

class Bad_value : public Exception
{
public:
	Bad_value() {}
	virtual void Show() override { std::cout << "Bad_value" << std::endl; }
};