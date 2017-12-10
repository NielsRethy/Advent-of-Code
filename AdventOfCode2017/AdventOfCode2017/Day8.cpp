#include "stdafx.h"
#include "Day8.h"
#include <vector>
#include <map>
#include "fstream"


Day8::Day8()
{
}


Day8::~Day8()
{
}

enum ifCases
{
	EqualTo,
	NotEqualto,
	LessThan,
	GreaterThan,
	LessThanOrEqualTo,
	GreaterThanOrEqualTo

};

struct info
{
	std::string name;
	bool increase;
	int value;
	std::string SecondName;
	ifCases comparisonOperator;
	int Secondvalue;

};

std::string Day8::Task2()
{
	std::ifstream file("../Inputs/Day 8.txt");
	std::string str;
	std::vector<info> information;
	std::map <std::string, int> value;

	while (std::getline(file, str))
	{

		std::string localName;
		info localInfo;
		int counter = 1;
		for (int a = 0; a < str.size(); a++)
		{
			if (str[a] != ' ')
			{
				localName += str[a];

				if (a == str.size() - 1)
				{
					localInfo.Secondvalue = std::stoi(localName);
				}
			}
			else
			{
				switch (counter) {
				case 1:
					localInfo.name = localName;
					localName = "";
					counter++;
					break;
				case 2:
					if (localName == "inc")
					{
						localInfo.increase = true;
					}
					else
					{
						localInfo.increase = false;
					}
					localName = "";
					counter++;
					break;
				case 3:
					localInfo.value = std::stoi(localName);
					localName = "";
					counter++;
					break;
				case 4:
					//ignore
					localName = "";
					counter++;
					break;
				case 5:
					localInfo.SecondName = localName;
					localName = "";
					counter++;
					break;
				case 6:
					if (localName == "==")
					{
						localInfo.comparisonOperator = ifCases::EqualTo;
					}
					else if (localName == "!=")
					{
						localInfo.comparisonOperator = ifCases::NotEqualto;
					}
					else if (localName == "<")
					{
						localInfo.comparisonOperator = ifCases::LessThan;
					}
					else if (localName == ">")
					{
						localInfo.comparisonOperator = ifCases::GreaterThan;
					}
					else if (localName == "<=")
					{
						localInfo.comparisonOperator = ifCases::LessThanOrEqualTo;
					}
					else if (localName == ">=")
					{
						localInfo.comparisonOperator = ifCases::GreaterThanOrEqualTo;

					}
					localName = "";
					counter++;
					break;
				}
			}

		}

		information.push_back(localInfo);
	}


	int largestAllValue = INT_MIN;
	for (int a = 0; a < information.size(); a++)
	{
		switch (information[a].comparisonOperator) {
		case EqualTo:
			if (value[information[a].SecondName] == information[a].Secondvalue)
			{
				if (information[a].increase)
				{
					value[information[a].name] += information[a].value;
					
				}
				else {
					value[information[a].name] -= information[a].value;
				}
			
			}
			break;
		case NotEqualto:
			if (value[information[a].SecondName] != information[a].Secondvalue)
			{
				if (information[a].increase)
				{
					value[information[a].name] += information[a].value;
					
				}
				else {
					value[information[a].name] -= information[a].value;
				}
			}
			break;
		case LessThan:
			if (value[information[a].SecondName] < information[a].Secondvalue)
			{
				if (information[a].increase)
				{
					value[information[a].name] += information[a].value;
					
				}
				else {
					value[information[a].name] -= information[a].value;
				}
			}
			break;
		case GreaterThan:
			if (value[information[a].SecondName] > information[a].Secondvalue)
			{
				if (information[a].increase)
				{
					value[information[a].name] += information[a].value;
					
				}
				else {
					value[information[a].name] -= information[a].value;
				}
			}
			break;
		case LessThanOrEqualTo:
			if (value[information[a].SecondName] <= information[a].Secondvalue)
			{
				if (information[a].increase)
				{
					value[information[a].name] += information[a].value;
				}
				else {
					value[information[a].name] -= information[a].value;
				}
			}
			break;
		case GreaterThanOrEqualTo:
			if (value[information[a].SecondName] >= information[a].Secondvalue)
			{
				if (information[a].increase)
				{
					value[information[a].name] += information[a].value;
				
				}
				else {
					value[information[a].name] -= information[a].value;
				}
			}
			break;
		}

		if (value[information[a].name] > largestAllValue)
		{
			largestAllValue = value[information[a].name];
		}

		
	}

	int largestValue = INT_MIN;
	for (auto element : value)
	{
		if (element.second > largestValue)
		{
			largestValue = element.second;
		}
	}

	return std::to_string(largestAllValue);
}
std::string Day8::Task1()
{

	std::ifstream file("../Inputs/Day 8.txt");
	std::string str;
	std::vector<info> information;
	std::map <std::string, int> value;

	while (std::getline(file, str))
	{

		std::string localName;
		info localInfo;
		int counter = 1;
		for (int a = 0; a < str.size(); a++)
		{
			if (str[a] != ' ')
			{
				localName += str[a];

				if (a == str.size() - 1)
				{
					localInfo.Secondvalue = std::stoi(localName);
				}
			}
			else
			{
				switch (counter) {
				case 1:
					localInfo.name = localName;
					localName = "";
					counter++;
					break;
				case 2:
					if (localName == "inc")
					{
						localInfo.increase = true;
					}
					else
					{
						localInfo.increase = false;
					}
					localName = "";
					counter++;
					break;
				case 3:
					localInfo.value = std::stoi(localName);
					localName = "";
					counter++;
					break;
				case 4:
					//ignore
					localName = "";
					counter++;
					break;
				case 5:
					localInfo.SecondName = localName;
					localName = "";
					counter++;
					break;
				case 6:
					if (localName == "==")
					{
						localInfo.comparisonOperator = ifCases::EqualTo;
					}
					else if (localName == "!=")
					{
						localInfo.comparisonOperator = ifCases::NotEqualto;
					}
					else if (localName == "<")
					{
						localInfo.comparisonOperator = ifCases::LessThan;
					}
					else if (localName == ">")
					{
						localInfo.comparisonOperator = ifCases::GreaterThan;
					}
					else if (localName == "<=")
					{
						localInfo.comparisonOperator = ifCases::LessThanOrEqualTo;
					}
					else if (localName == ">=")
					{
						localInfo.comparisonOperator = ifCases::GreaterThanOrEqualTo;

					}
					localName = "";
					counter++;
					break;
				}
			}

		}

		information.push_back(localInfo);
	}



	for (int a = 0; a < information.size(); a++)
	{
		switch (information[a].comparisonOperator) {
		case EqualTo:
			if (value[information[a].SecondName] == information[a].Secondvalue)
			{
				if (information[a].increase)
				{
					value[information[a].name] += information[a].value;

				}
				else {
					value[information[a].name] -= information[a].value;
				}

			}
			break;
		case NotEqualto:
			if (value[information[a].SecondName] != information[a].Secondvalue)
			{
				if (information[a].increase)
				{
					value[information[a].name] += information[a].value;

				}
				else {
					value[information[a].name] -= information[a].value;
				}
			}
			break;
		case LessThan:
			if (value[information[a].SecondName] < information[a].Secondvalue)
			{
				if (information[a].increase)
				{
					value[information[a].name] += information[a].value;

				}
				else {
					value[information[a].name] -= information[a].value;
				}
			}
			break;
		case GreaterThan:
			if (value[information[a].SecondName] > information[a].Secondvalue)
			{
				if (information[a].increase)
				{
					value[information[a].name] += information[a].value;

				}
				else {
					value[information[a].name] -= information[a].value;
				}
			}
			break;
		case LessThanOrEqualTo:
			if (value[information[a].SecondName] <= information[a].Secondvalue)
			{
				if (information[a].increase)
				{
					value[information[a].name] += information[a].value;
				}
				else {
					value[information[a].name] -= information[a].value;
				}
			}
			break;
		case GreaterThanOrEqualTo:
			if (value[information[a].SecondName] >= information[a].Secondvalue)
			{
				if (information[a].increase)
				{
					value[information[a].name] += information[a].value;

				}
				else {
					value[information[a].name] -= information[a].value;
				}
			}
			break;
		}
	}

	int largestValue = INT_MIN;
	for (auto element : value)
	{
		if (element.second > largestValue)
		{
			largestValue = element.second;
		}
	}

	return std::to_string(largestValue);
}

