#pragma once
#include "Days.h"
class Day21 :
	public Days
{
public:
	Day21();
	~Day21();

	std::string Task1();
	std::string Task2();

	int getDay() { return day; }

private:
	int day = 21;

	void Rotate(std::vector<std::string>&rot);
};

