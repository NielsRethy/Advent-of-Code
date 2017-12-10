#include "stdafx.h"
#include "Day9.h"
#include "fstream"


Day9::Day9()
{
}


Day9::~Day9()
{
}

std::string Day9::Task1()
{

	std::ifstream file("../Inputs/Day 9.txt");
	std::string str;


	bool ignoreNext = false;
	bool garbage = false;
	bool checknow = false;
	std::string input;

	while (std::getline(file, str))
	{
		for (int i = 0; i < str.size(); i++)
		{
			checknow = false;
			if (!ignoreNext)
			{
				if (str[i] == '!')
				{
					ignoreNext = true;
					checknow = true;
				}
				else if (str[i] == '<')
				{
					garbage = true;
				}

				if (!ignoreNext && !garbage)
				{
					input += str[i];
				}
				if (str[i] == '>')
				{
					garbage = false;
				}
			}

			if (!checknow)
			{
				if (i > 0)
				{
					if (ignoreNext && str[i - 1] == '!')
					{
						ignoreNext = false;
					}
				}
			}
		}
	}

	int counter = 0;
	int total = 0;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '{')
		{
			counter++;
			total += counter;
		}
		if (input[i] == '}')
		{
			counter--;
		}
	}


	return std::to_string(total);
}

std::string Day9::Task2()
{
	std::ifstream file("../Inputs/Day 9.txt");
	std::string str;


	bool ignoreNext = false;
	bool garbage = false;
	bool checknow = false;
	std::string input;

	while (std::getline(file, str))
	{
		for (int i = 0; i < str.size(); i++)
		{
			checknow = false;
			if (!ignoreNext)
			{
				if (str[i] == '!')
				{
					ignoreNext = true;
					checknow = true;
				}
				if (str[i] == '>')
				{
					garbage = false;
				}
				if (!ignoreNext && garbage)
				{
					input += str[i];
				}
				if (str[i] == '<')
				{
					garbage = true;
				}

			
			}

			if (!checknow)
			{
				if (i > 0)
				{
					if (ignoreNext && str[i - 1] == '!')
					{
						ignoreNext = false;
					}
				}
			}
		}
	}

	


	return std::to_string(input.size());
}
