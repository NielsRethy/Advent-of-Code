#pragma once
#include "Days.h"
#include <map>

class Day16 :
	public Days
{
public:
	Day16();
	~Day16();

	std::string Task1();
	std::string Task2();

	int getDay() { return day; }

private:
	int day = 16;


	struct info
	{
		char move;
		std::string instruction1;
		std::string instruction2;

	};

	void spin(std::string &dance, int amount);
	void Exchange(std::string &dance, int p1, int p2);
	void Partner(std::string &dance, std::string p1, std::string p2);

};

