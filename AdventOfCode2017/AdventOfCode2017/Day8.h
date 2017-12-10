#pragma once
#include <string>
#include "Days.h"

class Day8: public Days
{
public:
	Day8();
	~Day8();

	std::string Task1();
	std::string Task2();

	int getDay() { return day; }

private:
	int day = 8;
};

