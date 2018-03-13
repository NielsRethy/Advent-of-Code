#include "stdafx.h"
#include "Day24.h"
#include <fstream>
#include <list>


Day24::Day24()
{
}


Day24::~Day24()
{
}


std::string Day24::Task1()
{
	std::ifstream file("../Inputs/Day 24.txt");
	std::string str;

	std::list<number> input;
	
	int total = 0;

	while (std::getline(file, str))
	{
		number num;
		std::string number;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] != '/')
			{
				number += str[i];
				if (i == str.size() - 1)
				{
					num.number2 = std::stoi(number);
				}
			}
			else
			{
				num.number1 = std::stoi(number);
				number = "";
			}
		}
		input.push_back(num);
	}

	std::vector<int> sums;
	for (auto e : input)
	{
		if (e.number1 == 0)
		{
			std::vector<number> nf;
			nf.push_back(e);
			auto next = input;
			next.remove(e);
			findNext(e, next, nf,true);
		}
	}

	long long bridgje = 0;

	for (auto element : Sums)
	{
		long long sum = 0;
		for (auto el : element)
		{
			sum += el.number1 + el.number2;
		}

		if (bridgje < sum )
		{
			bridgje = sum;
		}
	}

	return std::to_string(bridgje);

 }

std::string Day24::Task2()
{
	std::ifstream file("../Inputs/Day 24.txt");
	std::string str;

	std::list<number> input;

	int total = 0;

	while (std::getline(file, str))
	{
		number num;
		std::string number;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] != '/')
			{
				number += str[i];
				if (i == str.size() - 1)
				{
					num.number2 = std::stoi(number);
				}
			}
			else
			{
				num.number1 = std::stoi(number);
				number = "";
			}
		}
		input.push_back(num);
	}

	std::vector<int> sums;
	for (auto e : input)
	{
		if (e.number1 == 0)
		{
			std::vector<number> nf;
			nf.push_back(e);
			auto next = input;
			next.remove(e);
			findNext(e, next, nf, true);
		}
	}

	
	int longestBridje = 0;
	for (auto element : Sums)
	{
		if (element.size() > longestBridje)
			longestBridje = element.size();


	}


	long long bridgje = 0;

	for (auto element : Sums)
	{
		if (element.size() == longestBridje)
		{
			long long sum = 0;
			for (auto el : element)
			{
				sum += el.number1 + el.number2;
			}

			if (bridgje < sum)
			{
				bridgje = sum;
			}
		}
	
	}

	return std::to_string(bridgje);
}

void Day24::findNext(number current, std::list<number> numbers, std::vector<number> numbersFound, bool ignoreFirst)
{
	bool foundOne = false;
	for (auto b : numbers)
	{
		if (ignoreFirst)
		{
			if (current.number2 == b.number1)
			{
					auto next = numbers;
					auto nf = numbersFound;
					nf.push_back(b);
					//int localSum = sum += b.number1 + b.number2;
					next.remove(b);
					findNext(b, next, nf, true);
					foundOne = true;
			}
			else if (current.number2 == b.number2)
			{
				auto next = numbers;
				auto nf = numbersFound;
				nf.push_back(b);
				//int localSum = sum += b.number1 + b.number2;
				next.remove(b);
				findNext(b, next, nf, false);
				foundOne = true;
			}
		}
		else
		{
			if (current.number1 == b.number1 )
			{


				auto next = numbers;
				auto nf = numbersFound;
				nf.push_back(b);
				//int localSum = sum += b.number1 + b.number2;
				next.remove(b);
				findNext(b, next, nf, true);
				foundOne = true;
			}
			if (current.number1 == b.number2)
			{


				auto next = numbers;
				auto nf = numbersFound;
				nf.push_back(b);
				//int localSum = sum += b.number1 + b.number2;
				next.remove(b);
				findNext(b, next, nf, false);
				foundOne = true;
			}
		}
		
	}
	if (!foundOne)
	{
		Sums.push_back(numbersFound);
	}
}
