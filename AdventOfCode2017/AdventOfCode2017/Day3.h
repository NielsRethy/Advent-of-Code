#pragma once
#include <string>
#include "Days.h"

class Day3: public Days
{
public:
	Day3();
	~Day3();

	std::string Task1();
	std::string Task2();
	std::string Task2V2();

	int getDay() { return day; }

private:
	int day = 3;

};

