#include "stdafx.h"
#include "Day22.h"
#include <fstream>
#include <iostream>


Day22::Day22()
{
}


Day22::~Day22()
{
}
struct pos
{
	int row;
	int column;
	int facing; // 0 == up 1 == Right 2 == Down 3 == Left
};

std::string Day22::Task1()
{
	std::ifstream file("../Inputs/Day 22.txt");
	std::string str;
	std::vector<std::string> input;
	while (std::getline(file, str))
	{
		input.push_back(str);
	}

	std::vector<std::string> grid;

	int size = 1000;

	for (int height = 0; height < size; ++height)
	{
		std::string row;
		for (int length = 0; length < size; ++length)
		{
			row += '.';
		}
		grid.push_back(row);
	}

	int middle = grid.size() / 2;
	for (int i = 0; i < input.size(); ++i)
	{
		int row = middle - (input.size() / 2) + i;
		for (int a = 0; a < input.size(); ++a)
		{
			int length = middle - (input[i].size() / 2) + a;
			grid[row][length] = input[i][a];
		}
	}
	pos position { middle ,middle ,0};

	int infections = 0;
	int trys = 10000;
	for (int i = 0; i < trys; ++i)
	{
		if (grid[position.row][position.column] == '#')
		{
			grid[position.row][position.column] = '.';
			switch (position.facing) {
			case 0: position.column++;
				position.facing = 1;
				break;
			case 1: position.row++;
				position.facing = 2;
				break;
			case 2: position.column--;
				position.facing = 3;
				break;
			case 3: position.row--;
				position.facing = 0;
				break;
			}
		}
		else
		{
			infections++;
			grid[position.row][position.column] = '#';
			switch (position.facing) {
			case 0: position.column--;
				position.facing = 3;
				break;
			case 1: position.row--;
				position.facing = 0;
				break;
			case 2: position.column++;
				position.facing = 1;
				break;
			case 3: position.row++;
				position.facing = 2;
				break;
			}
		}
	}

	

	//make grid
	return std::to_string(infections);
}

std::string Day22::Task2()
{
	std::ifstream file("../Inputs/Day 22.txt");
	std::string str;
	std::vector<std::string> input;
	while (std::getline(file, str))
	{
		input.push_back(str);
	}

	std::vector<std::string> grid;

	int size = 1000;

	for (int height = 0; height < size; ++height)
	{
		std::string row;
		for (int length = 0; length < size; ++length)
		{
			row += '.';
		}
		grid.push_back(row);
	}

	int middle = grid.size() / 2;
	for (int i = 0; i < input.size(); ++i)
	{
		int row = middle - (input.size() / 2) + i;
		for (int a = 0; a < input.size(); ++a)
		{
			int length = middle - (input[i].size() / 2) + a;
			grid[row][length] = input[i][a];
		}
	}
	pos position{ middle ,middle ,0 };

	int infections = 0;
	int trys = 10000000;
	for (int i = 0; i < trys; ++i)
	{
		if (grid[position.row][position.column] == '#')
		{
			grid[position.row][position.column] = 'F';
			switch (position.facing) {
			case 0: position.column++;
				position.facing = 1;
				break;
			case 1: position.row++;
				position.facing = 2;
				break;
			case 2: position.column--;
				position.facing = 3;
				break;
			case 3: position.row--;
				position.facing = 0;
				break;
			}
		}
		else if (grid[position.row][position.column] == '.')
		{
			
			grid[position.row][position.column] = 'W';
			switch (position.facing) {
			case 0: position.column--;
				position.facing = 3;
				break;
			case 1: position.row--;
				position.facing = 0;
				break;
			case 2: position.column++;
				position.facing = 1;
				break;
			case 3: position.row++;
				position.facing = 2;
				break;
			}
		}
		else if (grid[position.row][position.column] == 'W')
		{
			infections++;
			grid[position.row][position.column] = '#';
			switch (position.facing) {
			case 0: position.row--;
				break;
			case 1: position.column++;
				break;
			case 2: position.row++;
				break;
			case 3: position.column--;
				break;
			}
		}
		else if (grid[position.row][position.column] == 'F')
		{
			grid[position.row][position.column] = '.';
			switch (position.facing) {
			case 0: position.row++;
				position.facing = 2;
				break;
			case 1: position.column--;
				position.facing = 3;
				break;
			case 2: position.row--;
				position.facing = 0;
				break;
			case 3: position.column++;
				position.facing = 1;
				break;
			}
		}

	}



	//make grid
	return std::to_string(infections);
}
