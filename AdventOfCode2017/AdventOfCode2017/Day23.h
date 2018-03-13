#pragma once
#include "Days.h"
class Day23 :
	public Days
{
public:
	Day23();
	~Day23();

	std::string Task1();
	std::string Task2();

	int getDay() { return day; }

private:
	int day = 23;
};

