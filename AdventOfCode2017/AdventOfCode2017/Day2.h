#pragma once
#include <string>
#include "Days.h"

class Day2: public Days
{
public:
	Day2();
	~Day2();

	std::string Task1();
	std::string Task2();

	int getDay() { return day; }

private:
	int day = 2;

};

