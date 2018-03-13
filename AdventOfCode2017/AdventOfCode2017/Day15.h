#pragma once
#include "Days.h"
class Day15 :
	public Days
{
public:
	Day15();
	~Day15();


	std::string Task1();
	std::string Task2();

	int getDay() { return day; }

private:
	int day = 1;

	std::string HexToBin(std::string value);
	std::string toBinary(int n);
};

