#include "stdafx.h"
#include "Day12.h"
#include <fstream>
#include <vector>
#include <map>
#include <set>


Day12::Day12()
{
}


Day12::~Day12()
{
}

std::string Day12::Task1()
{
	std::vector<std::vector<int>> inputFile;


	std::ifstream file("../Inputs/Day 12.txt");
	std::string str;

	int total = 0;

	while (std::getline(file, str))
	{
		std::vector<int> n;
		std::string number;
		bool firstTime = false;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] != ' ' && !firstTime)
			{
				number += str[i];
			}
			else if (!firstTime)
			{
				n.push_back(std::stoi(number));
				number = "";
				firstTime = true;
			}
			else if (str[i] != '<' && str[i] != '-' && str[i] != '>' && str[i] != ' ' && str[i] != ',' && firstTime)
			{
				number += str[i];
				if (i == str.size() - 1)
				{
					n.push_back(std::stoi(number));
					number = "";
				}
			}
			else if (firstTime && str[i] == ',')
			{
				n.push_back(std::stoi(number));
				number = "";
			}

		}

		inputFile.push_back(n);
	}



	std::set<int> been;
	int numGroups = 0;
	std::vector<int> current;


		if (been.find(0) == been.end())
		{
			current.push_back(0);
			numGroups++;
			while (!current.empty())
			{
				auto n = current.back();
				current.pop_back();
				if (!been.insert(n).second)
				{
					continue;
				}
				for (auto j : inputFile[n])
				{
					current.push_back(j);
				}
			}
			
		}

	
		return std::to_string(been.size());
}




std::string Day12::Task2()
{
	std::vector<std::vector<int>> inputFile;


	std::ifstream file("../Inputs/Day 12.txt");
	std::string str;

	int total = 0;

	while (std::getline(file, str))
	{
		std::vector<int> n;
		std::string number;
		bool firstTime = false;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] != ' ' && !firstTime)
			{
				number += str[i];
			}
			else if (!firstTime)
			{
				n.push_back(std::stoi(number));
				number = "";
				firstTime = true;
			}
			else if (str[i] != '<' && str[i] != '-' && str[i] != '>' && str[i] != ' ' && str[i] != ',' && firstTime)
			{
				number += str[i];
				if (i == str.size() - 1)
				{
					n.push_back(std::stoi(number));
					number = "";
				}
			}
			else if (firstTime && str[i] == ',')
			{
				n.push_back(std::stoi(number));
				number = "";
			}

		}

		inputFile.push_back(n);
	}



	std::set<int> been;
	int numGroups = 0;
	std::vector<int> current;

	for (int i = 0; i < inputFile.size(); i++) {
		if (been.find(i) == been.end())
		{
			current.push_back(i);
			numGroups++;
			while (!current.empty())
			{
				auto n = current.back();
				current.pop_back();
				if (!been.insert(n).second)
				{
					continue;
				}
				for (auto j : inputFile[n])
				{
					current.push_back(j);
				}
			}
		}

	}
	return std::to_string(numGroups);

}

