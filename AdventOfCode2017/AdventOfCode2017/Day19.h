#pragma once
#include "Days.h"
class Day19 :
	public Days
{
public:
	Day19();
	~Day19();

	std::string Task1();
	std::string Task2();

	int getDay() { return day; }

private:
	int day = 19;
};

