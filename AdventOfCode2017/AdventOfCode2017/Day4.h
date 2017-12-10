#pragma once
#include <string>
#include "Days.h"

class Day4: public Days
{
public:
	Day4();
	~Day4();

	std::string Task1();
	std::string Task2();

	int getDay() { return day; }

private:
	int day = 4;

};

