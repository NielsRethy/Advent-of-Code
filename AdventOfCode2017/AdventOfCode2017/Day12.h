#pragma once
#include "Days.h"
class Day12 :
	public Days
{
public:
	Day12();
	~Day12();

	std::string Task1();
	std::string Task2();

	int getDay() { return day; }

private:
	int day = 12;


	struct information
	{
		int number;
		std::vector<int> contactsNumbers;
		std::vector<information*> contactsInfo;
		int index;

		bool const operator==(const information &o) const {
			return number == o.number ;
		}

		bool const operator<(const information &o) const {
			return number < o.number ;
		}
	};


	bool findContact(std::vector<information*> contacts, std::vector<int> contactNUmbers, int number, int ignoreNumber);
	bool findContactv2(information &contact, int &number, int &ignoreNumber);


};

