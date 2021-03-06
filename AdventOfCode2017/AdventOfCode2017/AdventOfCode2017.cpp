// AdventOfCode2017.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Day1.h"
#include "Day2.h"
#include "Day3.h"
#include "Day4.h"
#include "Day5.h"
#include <iostream>
#include "Day6.h"
#include "Day7.h"
#include "Day8.h"
#include "Day9.h"
#include "Day10.h"
#include "Day11.h"

using namespace std;;

int main()
{

	vector<Days *> DailyTest;
	DailyTest.push_back(new Day1);
	DailyTest.push_back(new Day2);
	DailyTest.push_back(new Day3);
	DailyTest.push_back(new Day4);
	DailyTest.push_back(new Day5);
	DailyTest.push_back(new Day6);
	DailyTest.push_back(new Day7);
	DailyTest.push_back(new Day8);
	DailyTest.push_back(new Day9);
	DailyTest.push_back(new Day10);
	DailyTest.push_back(new Day11);

	bool ShowAll = false;
	int day = 11;

	if (ShowAll)
	{
		for (Days *dt : DailyTest)
		{
			cout << "Day " << dt->getDay() << " - Answer 1: " << dt->Task1() << endl;
			cout << "Day " << dt->getDay() << " - Answer 2: " << dt->Task2() << endl;
			cout << endl;
		}
	}
	else
	{
		cout << "Day " << DailyTest[day - 1]->getDay() << " - Answer 1: " << DailyTest[day - 1]->Task1() << endl;
		cout << "Day " << DailyTest[day - 1]->getDay() << " - Answer 2: " << DailyTest[day - 1]->Task2() << endl;
		cout << endl;
	}

	getchar();
	return 0;
}



