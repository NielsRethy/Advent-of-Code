#pragma once
#include "Days.h"
class Day22 :
	public Days
{
public:
	Day22();
	~Day22();


	std::string Task1();
	std::string Task2();

	int getDay() { return day; }

private:
	int day = 22;
};

