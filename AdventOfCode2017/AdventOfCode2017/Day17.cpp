#include "stdafx.h"
#include "Day17.h"
#include <fstream>


Day17::Day17()
{
}


Day17::~Day17()
{
}

std::string Day17::Task1()
{
	std::ifstream file("../Inputs/Day 17.txt");
	std::string str;

	std::getline(file, str);
	int input = std::stoi(str);

	int numberToFind = 2017;

	std::vector<int> spinlock;

	int pos = 0;
	spinlock.push_back(0);

	for (int i = 1; i < numberToFind + 1; ++i)
	{
		pos = (pos + input) % (spinlock.size());
	//	pos %= (spinlock.size());
		pos += 1;
		spinlock.insert(spinlock.begin() + pos ,i);
	}
	return  std::to_string(spinlock[pos + 1]);;
}

std::string Day17::Task2()
{
	std::ifstream file("../Inputs/Day 17.txt");
	std::string str;

	std::getline(file, str);
	int input = std::stoi(str);

	int numberToFind = 50000000;

	int answer = 0;
	int pos = 0;
	for (int i = 1; i <= numberToFind; ++i)
	{
		pos = (pos + input) % (i);
		if (pos == 0) answer = i;
		pos += 1;
		
	}
	
	return  std::to_string(answer);;
}
