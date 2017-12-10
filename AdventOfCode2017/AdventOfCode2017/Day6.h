#pragma once

#include <string>
#include <vector>
#include "Days.h"

class Day6:public Days
{
public:
	Day6();
	~Day6();

	std::string Task1() ;
	std::string Task2();

	int getDay() { return day; }

private:
	int FindHighestNumberIndex(std::vector<int> numbers);
	void ChangeVec(std::vector<int> &numbers, int index);

	int day = 6;
};

