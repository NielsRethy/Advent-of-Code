#include "stdafx.h"
#include "Day4.h"
#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <algorithm>


Day4::Day4()
{
}


Day4::~Day4()
{
}

std::string Day4::Task1()
{
	std::ifstream file("../Inputs/Day 4.txt");
	std::string str;


	bool valid = true;
	int total = 0;

	while (std::getline(file, str))
	{
		std::map<std::string, int> words;
		std::string word;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] != ' ')
			{
				word += str[i];
				if (i == str.size() - 1)
				{
					words[word] = words[word] += 1;
					word = "";
				}
			}
			else
			{
				words[word] = words[word] += 1;
				word = "";
			}
		}

		for (auto w : words)
		{
			if (w.second < 2)
			{
				valid = true;
			}
			else
			{
				valid = false;
				break;
			}
		}

		if (valid)
		{
			total += 1;
		}


	}

	//std::cout << "total number " << total << std::endl;

	return std::to_string(total);

}

std::string Day4::Task2() 
{
	std::ifstream file("../Inputs/Day 4.txt");
	std::string str;


	bool valid = true;
	int total = 0;

	while (std::getline(file, str))
	{
		std::map<std::string, int> words;
		std::string word;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] != ' ')
			{
				word += str[i];
				if (i == str.size() - 1)
				{
					std::sort(word.begin(), word.end());
					words[word] = words[word] += 1;
					word = "";
				}
			}
			else
			{
				std::sort(word.begin(), word.end());
				words[word] = words[word] += 1;
				word = "";
			}
		}

		for (auto w : words)
		{
			if (w.second < 2)
			{
				valid = true;
			}
			else
			{
				valid = false;
				break;
			}
		}

		if (valid)
		{
			total += 1;
		}


	}

	//std::cout << "total number " << total << std::endl;

	return std::to_string(total);
}
