#pragma once
#include "Days.h"

class Day25 : public Days
{
public:
	Day25();
	~Day25();

	std::string Task1();
	std::string Task2();

	int getDay() { return day; }

private:
	int day = 25;

};

