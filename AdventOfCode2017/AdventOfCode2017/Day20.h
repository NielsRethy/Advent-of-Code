#pragma once
#include "Days.h"
class Day20 :
	public Days
{
public:
	Day20();
	~Day20();

	std::string Task1();
	std::string Task2();

	int getDay() { return day; }

private:
	int day = 20;
};

