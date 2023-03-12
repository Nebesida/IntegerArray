#pragma once
#include "Exception.h"

class Bad_range : public Exception
{
public:
	Bad_range() {}
	virtual void Show() override { std::cout << "Bad_range" << std::endl; }
};
