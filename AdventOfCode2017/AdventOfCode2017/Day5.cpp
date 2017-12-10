#include "stdafx.h"
#include "Day5.h"
#include <ostream>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>


Day5::Day5()
{
}


Day5::~Day5()
{
}

std::string Day5::Task1() 
{
	std::ifstream file("../Inputs/Day 5.txt");
	std::string str;
	std::vector<int> numbers;

	int numberIndex = 0;
	int counter = 0;

	while (std::getline(file, str))
	{
		//Store all numbers of the input
		numbers.push_back(std::stoi(str));
	}

	//While value is bigger then array, stay in loop. Need to find to leave the maze
	do
	{
		int lastNumber = numberIndex;
		numberIndex += numbers[numberIndex];
		numbers[lastNumber] += 1;

		//Count how many steps it takes
		counter++;
	}
	while (numberIndex < numbers.size());

	//std::cout << "total number " << counter << std::endl;

	return std::to_string(counter);
}

std::string Day5::Task2() 
{
	std::ifstream file("../Inputs/Day 5.txt");
	std::string str;
	std::vector<int> numbers;

	int numberIndex = 0;
	int counter = 0;

	while (std::getline(file, str))
	{
		//Store all numbers of the input
		numbers.push_back(std::stoi(str));
	}

	//While value is bigger then array, stay in loop. Need to find to leave the maze
	do
	{
		
		int lastNumber = numberIndex;
		numberIndex += numbers[numberIndex];

		//Decrease if value is 3 or bigger. Else increase by 1
		if (numbers[lastNumber] >= 3)
		{
			numbers[lastNumber] += -1;
		}
		else
		{
			numbers[lastNumber] += 1;
		}

		//Count how many steps it takes
		counter++;
	} while (numberIndex < numbers.size());

	//std::cout << "total number " << counter << std::endl;

	return std::to_string(counter);
}
