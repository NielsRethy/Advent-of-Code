#pragma once
#include "Days.h"
#include <list>

class Day24 :
	public Days
{
public:
	Day24();
	~Day24();

	std::string Task1();
	std::string Task2();

	int getDay() { return day; }

private:
	int day = 24;

	struct number
	{
		long long number1;
		long long number2;

		bool const operator==(const number &o) const {
			return number1 == o.number1 && number2 == o.number2;
		}

		bool const operator<(const number &o) const {
			return number1 < o.number1 && number2 < o.number2;
		}
	};

	std::vector<std::vector<number>> Sums;

	void findNext(number current, std::list<number> numbers, std::vector<number> numbersFound, bool ignore);

};

