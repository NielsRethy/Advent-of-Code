#include "stdafx.h"
#include "Day6.h"
#include <vector>
#include <fstream>
#include <map>


Day6::Day6()
{
}


Day6::~Day6()
{
	
}

std::string Day6::Task1()
{
	std::ifstream file("../Inputs/Day 6.txt");
	std::string str;
	std::vector<int> numbers;

	//Get input form file

	while (std::getline(file, str))
	{
		std::string word;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] != '\t')
			{
				word += str[i];
				if (i == str.size() - 1)
				{
					numbers.push_back(stoi(word));
					word = "";
				}
			}
			else
			{
				numbers.push_back(stoi(word));
				word = "";
			}
		}
	}


	std::map<std::vector<int>, int>  AlreadyUsed;
	int counter = 0;
	int t = 0;
	AlreadyUsed[numbers] = 1;

	//count when you start a loop
	do
	{
		int index = FindHighestNumberIndex(numbers);
		ChangeVec(numbers, index);
		AlreadyUsed[numbers] += 1;

		counter++;
	}
	while (AlreadyUsed[numbers] < 2 );

	return std::to_string(counter);
}

std::string Day6::Task2()
{
	std::ifstream file("../Inputs/Day 6.txt");
	std::string str;
	std::vector<int> numbers;

	//Get input form file

	while (std::getline(file, str))
	{
		std::string word;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] != '\t')
			{
				word += str[i];
				if (i == str.size() - 1)
				{
					numbers.push_back(stoi(word));
					word = "";
				}
			}
			else
			{
				numbers.push_back(stoi(word));
				word = "";
			}
		}
	}


	std::map<std::vector<int>, int>  AlreadyUsed;
	int counter = 0;
	int counter2 = 0;
	bool StartCounter2 = false;
	int t = 0;
	AlreadyUsed[numbers] = 1;

	//count when you start a loop
	do
	{
		int index = FindHighestNumberIndex(numbers);
		ChangeVec(numbers, index);
		AlreadyUsed[numbers] += 1;

		counter++;

		//Start second counter to count between 2 cycles 
		if (StartCounter2)
		{
			counter2++;
		}

		if (AlreadyUsed[numbers] >= 2)
		{
			StartCounter2 = true;
		}
	} while (AlreadyUsed[numbers] < 3);


	return std::to_string(counter2);
}

int Day6::FindHighestNumberIndex(std::vector<int> numbers)
{
	//Find the highest index
	int hNumber = INT_MIN;
	int index = 0;
	for(int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i]> hNumber )
		{
			hNumber = numbers[i];
			index = i;
		}
	}
	return index;
}

void Day6::ChangeVec(std::vector<int> &numbers, int index)
{
	//Change your vector as shown in task
	int addNumber =  numbers[index] / (numbers.size() - 1);

	if (addNumber > 0)
	{
		int RestValue = numbers[index] - addNumber *(numbers.size() - 1);

		for (int i = 0; i < numbers.size(); i++)
		{
			if (i == index)
			{
				numbers[i] = RestValue;
			}
			else
			{
				numbers[i] += addNumber;
			}
		}
	}
	else
	{
		int values = numbers[index];
		numbers[index] = 0;
		do
		{
			index++;
			
			numbers[index % numbers.size()] += 1;
			values -= 1;


		}
		while (values > 0);
	}

	
	
}


