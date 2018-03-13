#include "stdafx.h"
#include "Day23.h"
#include <map>
#include <fstream>
#include <iostream>
#include <numeric>


Day23::Day23()
{
}


Day23::~Day23()
{
}
struct input
{
	std::string instruction;
	std::string letter;
	std::string value;
};
std::string Day23::Task1()
{
	std::ifstream file("../Inputs/Day 23.txt");
	std::string str;
	std::vector<input> inputFile;

	int total = 0;

	while (std::getline(file, str))
	{
		std::string value;
		input inputValue;
		for (int i = 0; i < str.size(); i++)
		{
			if (i == 0)
			{
				std::string t;
				t += str[0];
				t += str[1];
				t += str[2];

				inputValue.instruction = t;
				inputValue.letter = str[4];
				i += 5;
			}
			else
			{
				value += str[i];

				if (i == str.size() - 1)inputValue.value = value;
			}
		}
		inputFile.push_back(inputValue);
	}

	std::map<std::string, long long> registers;

	int mullCounter = 0;


	for (auto element : inputFile)
	{
	
		registers[element.letter] = 0;
		
	}
	
	for (int i = 0; i < inputFile.size(); i++)
	{
		
		if (inputFile[i].instruction == "set")
		{
			//check if its a number or a letter
			if (inputFile[i].value.find_first_not_of("-0123456789") == std::string::npos)
			{
				//set new value
				registers[inputFile[i].letter] = std::stoi(inputFile[i].value);
			}
			else
			{
				//set new value
				registers[inputFile[i].letter] = registers[inputFile[i].value];
			}

		}
		else if (inputFile[i].instruction == "sub")
		{
			//check if its a number or a letter
			if (inputFile[i].value.find_first_not_of("-0123456789") == std::string::npos)
			{
				//decrease value
				registers[inputFile[i].letter] -= stoi(inputFile[i].value);
			}
			else
			{
				//decrease value
				registers[inputFile[i].letter] -= registers[inputFile[i].value];
			}

		}
		else if (inputFile[i].instruction == "mul")
		{
			mullCounter++;
			//check if its a number or a letter
			if (inputFile[i].value.find_first_not_of("-0123456789") == std::string::npos)
			{
				//multiply value
				registers[inputFile[i].letter] *= stoi(inputFile[i].value);
			}
			else
			{
				//multiply value
				registers[inputFile[i].letter] *= registers[inputFile[i].value];
			}

		}
		else if (inputFile[i].instruction == "jnz")
		{
		

			if (registers[inputFile[i].letter] != 0 || inputFile[i].letter == "1")
			{
				//new position
				i += stoi(inputFile[i].value);
				// go back 1 because there is a i++ after this
				i -= 1;
			}
		}

	}

	return std::to_string(mullCounter);
}

std::string Day23::Task2()
{

	long long characterH = 0;
	int a = 65 * 100 - (-100000);
	do
	{
		for (int b = 2; b < a / 2; ++b)
		{
			if (a % b == 0)
			{
				++characterH;
				break;
			}
		}
		a += 17;
	} while (a <= 65 * 100 - (-100000) - (-17000));
	return std::to_string(characterH);

	/*do
	{
		registers["f"] = 1;
		registers["d"] = 2;
		do
		{
			registers["e"] = 2;
			do
			{
				registers["g"] = registers["d"] * registers["e"] - registers["b"];
				if (registers["g"] == 0)
				{
					registers["f"] = 0;
				}
				registers["e"] += 1;
				registers["g"] = registers["e"] - registers["b"];
			}
			while (registers["g"] != 0);
		
			registers["d"] += 1;
			registers["g"] = registers["d"] - registers["b"];
		
		}
		while(registers["g"] != 0);

		if (registers["f"] == 0)
		{
			registers["h"] += 1;
		}

		registers["g"] = registers["b"] - registers["c"];
		registers["b"] += 17;

	}
	while (registers["h"] != 0);*/

	return"";
}
