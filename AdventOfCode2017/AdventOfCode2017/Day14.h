#pragma once
#include "Days.h"
class Day14 :
	public Days
{
public:
	Day14();
	~Day14();

	std::string Task1();
	std::string Task2();

	int getDay() { return day; }

private:
	int day = 14;

	std::string HexToBin(std::string value);
	void SpareHashToDenseHash(std::vector<int> &spareHash);
	void ChangeVectorOrder(int begin, int end, std::vector<int> &numbers);

	bool Day14::NextRegion(int maxRow , int maxCollom,std::vector<std::string> &info, int row, int col);
};

