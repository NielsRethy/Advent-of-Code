#pragma once
#include <string>
#include "Days.h"

class Day5 : public Days
{
public:
	Day5();
	~Day5();

	std::string Task1();
	std::string Task2();

	int getDay() { return day; }

private:
	int day = 5;

};

