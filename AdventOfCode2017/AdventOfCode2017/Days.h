#pragma once
#include <string>

class Days
{
public:
	Days();
	~Days();

	virtual std::string Task1() { return ""; }
	virtual std::string Task2() { return ""; }

	virtual int getDay() { return day; }

private:
	int day;


};

