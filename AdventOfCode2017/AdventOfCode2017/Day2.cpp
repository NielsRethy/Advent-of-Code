#include "stdafx.h"
#include "Day2.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>


Day2::Day2()
{
}


Day2::~Day2()
{
}

std::string Day2::Task1() 
{
	std::ifstream file("../Inputs/Day 2.txt");
	std::string str;


	int total = 0;

	while (std::getline(file, str))
	{
		std::string number;
		int BiggestNumber = INT_MIN;
		int SmallestNumber = INT_MAX;
		for (int i = 0; i < str.size() ; i++)
		{
			if (str[i] != '\t')
			{
				number += str[i];

				if (i == str.size() - 1 )
				{
					if (std::stoi(number) > BiggestNumber)
					{
						BiggestNumber = std::stoi(number);
					}
					if (std::stoi(number) < SmallestNumber)
					{
						SmallestNumber = std::stoi(number);
					}
					number = "";
				}
			}
			else
			{
				if (std::stoi(number) > BiggestNumber)
				{
					BiggestNumber = std::stoi(number);
				}
				if (std::stoi(number) < SmallestNumber)
				{
					SmallestNumber = std::stoi(number);
				}
				number = "";
			}
		}

		total += BiggestNumber - SmallestNumber;
	}

	//std::cout << total << std::endl;

	return std::to_string(total);
}

std::string Day2::Task2() 
{
	std::ifstream file("../Inputs/Day 2.txt");
	std::string str;



	int total = 0;

	while (std::getline(file, str))
	{
		std::string number;
		int BiggestNumber = INT_MIN;
		int SmallestNumber = INT_MAX;
		std::vector<int> values;

		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] != '\t')
			{
				number += str[i];

				if (i == str.size() - 1)
				{
					values.push_back(stoi(number));
					number = "";
				}
			}
			else
			{
				values.push_back(stoi(number));
				number = "";
			}
		}

		bool done = false;
		for (int a = 0; a < values.size(); a++)
		{
			if (!done)
			{
				for (int n : values)
				{
					if (values[a] != n && values[a] % n == 0)
					{
						total += values[a] / n;
						done = true;
					}
				}
			}
		}
	}

	//std::cout << total << std::endl;

	return std::to_string(total);
}
