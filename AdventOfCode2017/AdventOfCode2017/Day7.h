#pragma once
#include "Days.h"

class Day7 : public Days
{
public:
	Day7();
	~Day7();

	std::string Task1();
	std::string Task2();

	int getDay() { return day; }

private:
	int day = 7;
};

