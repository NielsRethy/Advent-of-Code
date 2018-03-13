#include "stdafx.h"
#include "Day13.h"
#include <fstream>


Day13::Day13()
{
}


Day13::~Day13()
{
}

struct input
{
	int pos;
	int index;
	int length;
	bool up;
};

struct player
{
	int pos;
	int index;
};

std::string Day13::Task1()
{

	std::ifstream file("../Inputs/Day 13.txt");
	std::string str;
	std::vector<input> inputs;

	int total = 0;

	while (std::getline(file, str))
	{
		std::string number;
		bool firstTime = false;
		input fileInfo;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] != ':' && !firstTime)
			{
				number += str[i];
			}
			else if (!firstTime)
			{
				fileInfo.pos = stoi(number);
				number = "";
				firstTime = true;
			}
			else if (str[i] != ':' && str[i] != ' ' && firstTime)
			{
				number += str[i];
				if (i == str.size() - 1)
				{
					fileInfo.length = stoi(number);
					number = "";
				}
			}
			

		}
		fileInfo.index = 0;
		fileInfo.up = true;
		inputs.push_back(fileInfo);

	}

	int playerPos = 0;
	std::vector<int> cautch; 
	int sum = 0;
	do
	{
		for (int i = 0; i < inputs.size(); i++)
		{
			if (inputs[i].pos == playerPos && inputs[i].index == 0)
			{
				cautch.push_back(inputs[i].pos);
				sum += inputs[i].pos * inputs[i].length;
			}
			if (inputs[i].up)
			{
				if (inputs[i].index < inputs[i].length - 1)
				{
					inputs[i].index++;
					inputs[i].up = true;
				}
				else
				{
					inputs[i].index--;
					inputs[i].up = false;
				}
			}
			else
			{
				if (inputs[i].index > 0)
				{
					inputs[i].index--;
					inputs[i].up = false;
				}
				else
				{
					inputs[i].index++;
					inputs[i].up = true;
				}
			}
			
			
		}
		playerPos++;
	}
	while (playerPos <= inputs[inputs.size() - 1].pos);


	return std::to_string(sum);
}

std::string Day13::Task2()
{

	std::ifstream file("../Inputs/Day 13.txt");
	std::string str;
	std::vector<input> inputs;

	//input
	while (std::getline(file, str))
	{
		std::string number;
		bool firstTime = false;
		input fileInfo;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] != ':' && !firstTime)
			{
				number += str[i];
			}
			else if (!firstTime)
			{
				fileInfo.pos = stoi(number);
				number = "";
				firstTime = true;
			}
			else if (str[i] != ':' && str[i] != ' ' && firstTime)
			{
				number += str[i];
				if (i == str.size() - 1)
				{
					fileInfo.length = stoi(number);
					number = "";
				}
			}


		}
		fileInfo.index = 0;
		fileInfo.up = true;
		inputs.push_back(fileInfo);

	}

	std::vector<input> inputslocal = inputs;


	int indexCounter = 0;
	do
	{
		bool good = true;

		for (auto in : inputs)
		{
			if ((in.pos + indexCounter) % (2 * in.length - 2) == 0)
			{
				good = false;
				break;
			}
		}

	
		if(good)
		{
			return std::to_string(indexCounter);
		}
		indexCounter++;
		
	}
	while (true);
	

	
}

