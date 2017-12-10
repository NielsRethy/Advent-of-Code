#pragma once
#include "Days.h"
class Day9 :
	public Days
{
public:
	Day9();
	~Day9();
	std::string Task1();
	std::string Task2();

	int getDay() { return day; }

private:
	int day = 9;
};

