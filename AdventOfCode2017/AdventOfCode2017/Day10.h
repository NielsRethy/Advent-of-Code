#pragma once
#include "Days.h"
#include <vector>

class Day10 :
	public Days
{
public:
	Day10();
	~Day10();


	std::string Task1();
	std::string Task2();

	int getDay() { return day; }

private:
	int day = 10;

	void ChangeVectorOrder(int begin, int end, std::vector<int> &numbers);
	void SpareHashToDenseHash(std::vector<int> &numbers);

};

