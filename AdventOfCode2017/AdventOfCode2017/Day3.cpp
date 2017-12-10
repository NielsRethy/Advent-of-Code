#include "stdafx.h"
#include "Day3.h"
#include <vector>
#include <iostream>
#include <list>
#include <map>


Day3::Day3()
{
}


Day3::~Day3()
{
}

struct CoordinatesNumber
{
	int x;
	int y;
	int number;
};

std::string Day3::Task1()
{

	int numberToFind = 368078;
	int spiralSize = 400000;
	std::vector<CoordinatesNumber> coor;
	//Positie x + y
	int x = 0;
	int y = 0;
	coor.push_back(CoordinatesNumber{ 0,0,1 });
	for (int i = 2; i < spiralSize ; ++i)
	{
		if (abs(x) <= abs(y) && (x != y || x >= 0))
		{
			if (y >= 0)
			{
				x += 1;
			}
			else
			{
				x += -1;
			}
		}
		else
		{
			if (x >= 0)
			{
				y += -1;
			}
			else
			{
				y += 1;
			}
		}

		coor.push_back(CoordinatesNumber{ x,y,i });
	}

	for (CoordinatesNumber c : coor)
	{
		if (c.number == numberToFind)
		{
			//std::cout << "Position = " << abs(c.x) + abs(c.y) << '\n';

			return std::to_string((abs(c.x) + abs(c.y)));
		}
	}

	
}

//std::string Day3::Task2(int numberToFind, int spiralSize)
//{
//
//
//	int numberToFind = 368078;
//	int spiralSize = 400000;
//
//	std::vector<CoordinatesNumber> coor;
//	//Positie x + y
//	int x = 0;
//	int y = 0;
//	coor.push_back(CoordinatesNumber{ 0,0,1 });
//	for (int i = 2; i < spiralSize; ++i)
//	{
//		if (abs(x) <= abs(y) && (x != y || x >= 0))
//		{
//			if (y >= 0)
//			{
//				x += 1;
//			}
//			else
//			{
//				x += -1;
//			}
//		}
//		else
//		{
//			if (x >= 0)
//			{
//				y += -1;
//			}
//			else
//			{
//				y += 1;
//			}
//		}
//
//		int number = 0;
//
//		//check neighbors 
//
//		std::list<CoordinatesNumber> test;
//
//		for (CoordinatesNumber c : coor)
//		{
//			if(c.x == x - 1 || c.x == x + 1 || c.x == x)
//			{
//				if (c.y == y - 1 || c.y == y + 1 || c.y == y)
//				{
//					number += c.number;
//				}
//			}
//		}
//		
//
//
//		coor.push_back(CoordinatesNumber{ x,y,number });
//	}
//
//	for (CoordinatesNumber c : coor)
//	{
//		if (c.number > numberToFind )
//		{
//			std::cout << "number = " << c.number << '\n';
//			return std::to_string(c.number);
//			break;
//		}
//	}
//}


struct Coordinates
{
	int x;
	int y;

	bool const operator==(const Coordinates &o) const {
		return x == o.x && y == o.y;
	}

	bool const operator<(const Coordinates &o) const {
		return x < o.x || (x == o.x && y < o.y);
	}
};
std::string Day3::Task2()
{

	int numberToFind = 368078;
	int spiralSize = 400000;
	std::map<Coordinates,int> coor;

	//Positie x + y
	int x = 0;
	int y = 0;
	coor.insert(std::pair<Coordinates, int>(Coordinates{ 0,0}, 1));


	for (int i = 2; i < spiralSize; ++i)
	{
		if (abs(x) <= abs(y) && (x != y || x >= 0))
		{
			if (y >= 0)
				x += 1;
			else
				x += -1;
		}
		else
		{
			if (x >= 0)
				y += -1;
			else
				y += 1;
		}

		//check neighbors 

		
		int number = 0;
		if (coor.find(Coordinates{ x,y }) != coor.end() || coor.rbegin()->first == Coordinates{ x,y })
			number += coor.find(Coordinates{ x,y })->second;
		if (coor.find(Coordinates{ x - 1,y }) != coor.end() || coor.rbegin()->first == Coordinates{ x - 1,y })
			number += coor.find(Coordinates{ x - 1,y })->second;
		if (coor.find(Coordinates{ x + 1,y }) != coor.end() || coor.rbegin()->first == Coordinates{ x + 1,y })
			number += coor.find(Coordinates{ x + 1,y })->second;
		if (coor.find(Coordinates{ x,y + 1 }) != coor.end() || coor.rbegin()->first == Coordinates{ x,y + 1 })
			number += coor.find(Coordinates{ x,y + 1 })->second;
		if (coor.find(Coordinates{ x,y - 1}) != coor.end() || coor.rbegin()->first == Coordinates{ x,y - 1 })
			number += coor.find(Coordinates{ x,y  - 1})->second;
		if (coor.find(Coordinates{ x + 1,y + 1 }) != coor.end() || coor.rbegin()->first == Coordinates{ x + 1,y + 1 })
			number += coor.find(Coordinates{ x + 1,y + 1 })->second;
		if (coor.find(Coordinates{ x - 1,y - 1 }) != coor.end() || coor.rbegin()->first == Coordinates{ x - 1,y - 1 })
			number += coor.find(Coordinates{ x - 1,y - 1 })->second;
		if (coor.find(Coordinates{ x + 1,y - 1 }) != coor.end() || coor.rbegin()->first == Coordinates{ x + 1,y - 1})
			number += coor.find(Coordinates{ x + 1,y - 1 })->second;
		if (coor.find(Coordinates{ x - 1,y + 1 }) != coor.end() || coor.rbegin()->first == Coordinates{ x - 1,y + 1 })
			number += coor.find(Coordinates{ x - 1,y + 1 })->second;

		coor.insert(std::pair<Coordinates, int>(Coordinates{ x,y }, number));
		if (number > numberToFind)
		{
			//std::cout << "number = " << number << '\n';
			return std::to_string(number);
		}
	}
}

