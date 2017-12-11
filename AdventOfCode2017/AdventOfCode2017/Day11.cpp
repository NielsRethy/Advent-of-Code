#include "stdafx.h"
#include "Day11.h"
#include <vector>
#include <algorithm>
#include <fstream>


Day11::Day11()
{
}


Day11::~Day11()
{
}
struct CoordinatesNumber
{
	float x;
	float y;
};

std::string Day11::Task1()
{
	std::vector<std::string> way;

	std::ifstream file("../Inputs/Day 11.txt");
	std::string str;

	//getting file info

	while (std::getline(file, str))
	{
		std::string coor;

		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] != ',')
			{
				coor += str[i];

				if (i == str.size() - 1)
				{
					way.push_back(coor);
					coor = "";
				}
			}
			else
			{
				way.push_back(coor);
				coor = "";
			}
		}

	
	}


	//moving to correct coordinates 

	CoordinatesNumber ActiveCoor = {0,0};
	int index = 0;

	for (int i = 0; i < way.size(); ++i)
	{
		if (way[i] == "ne")
		{
			ActiveCoor = { ActiveCoor.x + 0.5f , ActiveCoor.y + 0.5f };
		}
		if (way[i] == "n")
		{
			ActiveCoor = { ActiveCoor.x + 1.f , ActiveCoor.y  };
		}
		if (way[i] == "nw")
		{
			ActiveCoor = { ActiveCoor.x + 0.5f , ActiveCoor.y - 0.5f };
		}
		if (way[i] == "se")
		{
			ActiveCoor = { ActiveCoor.x - 0.5f , ActiveCoor.y + 0.5f };
		}
		if (way[i] == "s")
		{
			ActiveCoor = { ActiveCoor.x - 1.f , ActiveCoor.y };
		}
		if (way[i] == "sw")
		{
			ActiveCoor = { ActiveCoor.x - 0.5f , ActiveCoor.y - 0.5f };
		}
	}


	//calculate steps
	int steps = 0;

	if (abs(ActiveCoor.x) != abs(ActiveCoor.y))
	{
		do
		{
			if (abs(ActiveCoor.x) > abs(ActiveCoor.y))
			{
				if (ActiveCoor.x > 0)
				{
					ActiveCoor.x -= 1;
				}
				else
				{
					ActiveCoor.x += 1;
				}
			}
			else
			{
				if (ActiveCoor.y > 0)
				{
					ActiveCoor.y -= 1;
				}
				else
				{
					ActiveCoor.y += 1;
				}
			}
			steps++;
		} while (abs(ActiveCoor.x) != abs(ActiveCoor.y));
	}
	
	

	steps += 2 * abs(ActiveCoor.x);



	return std::to_string(steps);
}

std::string Day11::Task2()
{
	std::vector<std::string> way;

	std::ifstream file("../Inputs/Day 11.txt");
	std::string str;


	//getting file info
	while (std::getline(file, str))
	{
		std::string coor;

		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] != ',')
			{
				coor += str[i];

				if (i == str.size() - 1)
				{
					way.push_back(coor);
					coor = "";
				}
			}
			else
			{
				way.push_back(coor);
				coor = "";
			}
		}


	}


	//moving to correct coordinates 
	CoordinatesNumber ActiveCoor = { 0,0 };
	int maxSteps = INT_MIN;

	for (int i = 0; i < way.size(); ++i)
	{
		if (way[i] == "ne")
		{
			ActiveCoor = { ActiveCoor.x + 0.5f , ActiveCoor.y + 0.5f };
		}
		if (way[i] == "n")
		{
			ActiveCoor = { ActiveCoor.x + 1.f , ActiveCoor.y };
		}
		if (way[i] == "nw")
		{
			ActiveCoor = { ActiveCoor.x + 0.5f , ActiveCoor.y - 0.5f };
		}
		if (way[i] == "se")
		{
			ActiveCoor = { ActiveCoor.x - 0.5f , ActiveCoor.y + 0.5f };
		}
		if (way[i] == "s")
		{
			ActiveCoor = { ActiveCoor.x - 1.f , ActiveCoor.y };
		}
		if (way[i] == "sw")
		{
			ActiveCoor = { ActiveCoor.x - 0.5f , ActiveCoor.y - 0.5f };
		}


		//calculate biggest step
		int thisStep = 0;

		CoordinatesNumber thisCoor = ActiveCoor;

		if (abs(thisCoor.x) != abs(thisCoor.y))
		{
			do
			{
				if (abs(thisCoor.x) > abs(thisCoor.y))
				{
					if (thisCoor.x > 0)
					{
						thisCoor.x -= 1;
					}
					else
					{
						thisCoor.x += 1;
					}
				}
				else
				{
					if (thisCoor.y > 0)
					{
						thisCoor.y -= 1;
					}
					else
					{
						thisCoor.y += 1;
					}
				}
				thisStep++;
			} while (abs(thisCoor.x) != abs(thisCoor.y));
		}



		thisStep += 2 * abs(thisCoor.x);

		if (thisStep > maxSteps)
		{
			maxSteps = thisStep;
		}
	}

	return std::to_string(maxSteps);
}
