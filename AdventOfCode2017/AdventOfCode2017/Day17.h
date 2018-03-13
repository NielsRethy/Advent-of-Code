#pragma once
#include "Days.h"
class Day17 :
	public Days
{
public:
	Day17();
	~Day17();

	std::string Task1();
	std::string Task2();

	int getDay() { return day; }

private:
	int day = 17;
};

