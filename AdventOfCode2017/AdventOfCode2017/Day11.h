#pragma once
#include "Days.h"
class Day11 :
	public Days
{
public:
	Day11();
	~Day11();

	std::string Task1();
	std::string Task2();

	int getDay() { return day; }

private:
	int day = 11;
};

