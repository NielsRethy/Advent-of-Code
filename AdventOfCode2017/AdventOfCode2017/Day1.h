#pragma once
#include <string>
#include "Days.h"

class Day1: public Days
{
public:
	Day1();
	~Day1();

	std::string Task1();
	std::string Task2();

	int getDay() { return day; }

private:
	int day = 1;

};

