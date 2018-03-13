#pragma once
#include "Days.h"
class Day13 :
	public Days
{
public:
	Day13();
	~Day13();

	std::string Task1();
	std::string Task2();

	int getDay() { return day; }

private:


	int day = 13;

	struct input
	{
		int pos;
		int index;
		int length;
		bool up;
	};


	bool findZero(std::vector<input> info, int index);
};

