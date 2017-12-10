#include "stdafx.h"
#include "Day1.h"
#include <ostream>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>


Day1::Day1()
{
}


Day1::~Day1()
{
}

std::string Day1::Task2() 
{
	std::vector<int>  numbers;

	std::string numbersInput;


	std::ifstream file("../Inputs/Day 1.txt");
	std::string str;
	while (std::getline(file, str))
	{
		for (char c : str)
		{
			numbers.push_back(c - '0');
		}
	}

	int sum = 0;
	for (int i = 0; i < numbers.size(); i++)
	{

		if (numbers.size() < 2)
		{
		}

		if (i >= numbers.size() / 2)
		{
			if (numbers[i] == numbers[i - numbers.size() / 2])
			{
				sum += numbers[i];
			}
		}
		else if (numbers[i] == numbers[i + numbers.size() / 2])
		{
			sum += numbers[i];
		}
	}

	//std::cout << sum << std::endl;

	return std::to_string(sum);
}

std::string Day1::Task1() 
{
	std::vector<int>  numbers;
	std::string numbersInput;

	std::ifstream file("../Inputs/Day 1.txt");
	std::string str;
	while (std::getline(file, str))
	{
		for (char c : str)
		{
			numbers.push_back(c - '0');
		}
	}

	int sum = 0;
	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers.size() < 2)
		{
		}
		else if (i < 1)
		{
			if (numbers[numbers.size() - 1] == numbers[0])
			{
				sum += numbers[i];
			}
		}
		else if (numbers[i] == numbers[i - 1])
		{
			sum += numbers[i];
		}
	}

	//std::cout << sum << std::endl;

	return std::to_string(sum);
}
