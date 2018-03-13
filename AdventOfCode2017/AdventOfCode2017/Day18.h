#pragma once
#include "Days.h"

class Day18 : public Days
{
public:
	Day18();
	~Day18();

	std::string Task1();
	std::string Task2();

	int getDay() { return day; }

private:
	int day = 18;
};

