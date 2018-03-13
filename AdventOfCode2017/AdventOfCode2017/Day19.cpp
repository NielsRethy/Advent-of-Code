#include "stdafx.h"
#include "Day19.h"
#include <fstream>
#include <cstdbool>


Day19::Day19()
{
}


Day19::~Day19()
{
}

std::string Day19::Task1()
{
	std::ifstream file("../Inputs/Day 19.txt");
	std::string str;

	bool horizon = true;

	bool GoOp = false;
	bool GoDown = false;
	bool GoLeft = false;
	bool GoRight = true;

	bool foundStart = false;

	std::vector<std::string> input;
	while (std::getline(file, str))
	{
		input.push_back(str);
	}


	std::string answer;

	for (int a = 0; a < input.size(); ++a)
	{

		for (int i = 0; i < input[a].size();)
		{
			if (!foundStart)
			{
				if (input[a][i] == '|')
				{
					foundStart = true;
					horizon = false;
					GoOp = false;
					GoDown = true;
					GoLeft = false;
					GoRight = false;
				}

			}
			else
			{
				if (input[a][i] != ' ' && input[a][i] != '|' && input[a][i] != '-' && input[a][i] != '+')
				{
					answer += input[a][i];
				}
				if (horizon)
				{
					if (input[a][i] == '+')
					{
						horizon = false;
						if (a + 1 < input.size() )
						{
							if (input[a + 1][i] != ' ' && input[a + 1][i] != '-')
							{
								GoRight = false;
								GoLeft = false;
								GoOp = false;
								GoDown = true;
							}
							else
							{
								GoRight = false;
								GoLeft = false;
								GoOp = true;
								GoDown = false;
							}
						}
						else
						{
							GoRight = false;
							GoLeft = false;
							GoOp = true;
							GoDown = false;
						}
					}
					if (input[a][i] == ' ')
					{
						return answer;
					}
				}
				else {  
					if (input[a][i] == '+')
					{
						horizon = true;

						if (i + 1 < input[a].size() - 1)
						{
							if (input[a][i + 1] != ' ' && input[a][i + 1] != '|')
							{
								GoRight = true;
								GoLeft = false;
								GoOp = false;
								GoDown = false;
							}
							else
							{
								GoRight = false;
								GoLeft = true;
								GoOp = false;
								GoDown = false;
							}
						}
						else
						{
							GoRight = false;
							GoLeft = true;
							GoOp = false;
							GoDown = false;
						}
					}
				}
				if (input[a][i] == ' ')
				{
					return answer;
				}
			}

			if (GoLeft)
			{
				i--;
			}
			if(GoRight)
			{
				i++;
			}
			if(GoDown)
			{
				a++;
			}
			if (GoOp)
			{
				a--;
			}
		}

	}
	return answer;
}

std::string Day19::Task2()
{
	std::ifstream file("../Inputs/Day 19.txt");
	std::string str;

	bool horizon = true;

	bool GoOp = false;
	bool GoDown = false;
	bool GoLeft = false;
	bool GoRight = true;

	bool foundStart = false;

	std::vector<std::string> input;
	while (std::getline(file, str))
	{
		input.push_back(str);
	}


	std::string answer;
	int steps = 0;

	for (int a = 0; a < input.size(); ++a)
	{

		for (int i = 0; i < input[a].size();)
		{
			if (!foundStart)
			{
				if (input[a][i] == '|')
				{
					foundStart = true;
					horizon = false;
					GoOp = false;
					GoDown = true;
					GoLeft = false;
					GoRight = false;
				}

			}
			else
			{
				if (input[a][i] != ' ' && input[a][i] != '|' && input[a][i] != '-' && input[a][i] != '+')
				{
					answer += input[a][i];

				}
				if (horizon)
				{
					if (input[a][i] == '+')
					{
						horizon = false;
						if (a + 1 < input.size())
						{
							if (input[a + 1][i] != ' ' && input[a + 1][i] != '-')
							{
								GoRight = false;
								GoLeft = false;
								GoOp = false;
								GoDown = true;
							}
							else
							{
								GoRight = false;
								GoLeft = false;
								GoOp = true;
								GoDown = false;
							}
						}
						else
						{
							GoRight = false;
							GoLeft = false;
							GoOp = true;
							GoDown = false;
						}
					}
					if (input[a][i] == ' ')
					{
						return std::to_string(steps);
					}
				}
				else {
					if (input[a][i] == '+')
					{
						horizon = true;

						if (i + 1 < input[a].size() - 1)
						{
							if (input[a][i + 1] != ' ' && input[a][i + 1] != '|')
							{
								GoRight = true;
								GoLeft = false;
								GoOp = false;
								GoDown = false;
							}
							else
							{
								GoRight = false;
								GoLeft = true;
								GoOp = false;
								GoDown = false;
							}
						}
						else
						{
							GoRight = false;
							GoLeft = true;
							GoOp = false;
							GoDown = false;
						}
					}
				}
				if (input[a][i] == ' ')
				{
					return std::to_string(steps);
				}
			}

			if (GoLeft)
			{
				i--;
				if (foundStart)
				{
					steps++;
				}
				
			}
			if (GoRight)
			{
				i++;
				if (foundStart)
				{
					steps++;
				}
			}
			if (GoDown)
			{
				a++;
				if (foundStart)
				{
					steps++;
				}
			}
			if (GoOp)
			{
				a--;
				if (foundStart)
				{
					steps++;
				}
			}
		}

	}
	return std::to_string(steps);
}
