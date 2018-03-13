#include "stdafx.h"
#include "Day18.h"
#include <fstream>
#include <map>
#include <list>


Day18::Day18()
{
}


Day18::~Day18()
{
}

struct input
{
	std::string instruction;
	std::string letter;
	std::string value;
};

std::string Day18::Task1()
{
	std::ifstream file("../Inputs/Day 18.txt");
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
				i+=5;
			}
			else
			{
				value += str[i];

				if (i == str.size() - 1)inputValue.value = value;
			}
		}
		inputFile.push_back(inputValue);
	}

	int lastPlayedSound;
	std::map<std::string, long long> sounds;



	for (auto element : inputFile)
	{
		sounds[element.letter] = 0;
	}
	for (int i = 0; i < inputFile.size(); i++)
	{
		if (inputFile[i].instruction == "snd")
		{
			lastPlayedSound = sounds[inputFile[i].letter];
		}
		if (inputFile[i].instruction == "set")
		{
			if (inputFile[i].value.find_first_not_of("-0123456789") == std::string::npos)
			{
				sounds[inputFile[i].letter] = stoi(inputFile[i].value);
			}
			else
			{
				sounds[inputFile[i].letter] = sounds[inputFile[i].value];
			}
		
		}
		if (inputFile[i].instruction == "add")
		{
			if (inputFile[i].value.find_first_not_of("-0123456789") == std::string::npos)
			{
				sounds[inputFile[i].letter] += stoi(inputFile[i].value);
			}
			else
			{
				sounds[inputFile[i].letter] += sounds[inputFile[i].value];
			}
		}
		if (inputFile[i].instruction == "mul")
		{
			if (inputFile[i].value.find_first_not_of("-0123456789") == std::string::npos)
			{
				sounds[inputFile[i].letter] *= stoi(inputFile[i].value);
			}
			else
			{
				sounds[inputFile[i].letter] *= sounds[inputFile[i].value];
			}
		}
		if (inputFile[i].instruction == "mod")
		{
			if (inputFile[i].value.find_first_not_of("-0123456789") == std::string::npos)
			{
				sounds[inputFile[i].letter] %= stoi(inputFile[i].value);
			}
			else
			{
				sounds[inputFile[i].letter] %= sounds[inputFile[i].value];
			}
		}
		if (inputFile[i].instruction == "rcv")
		{
			if (sounds[inputFile[i].letter] != 0)
			{
				/*sounds[inputFile[i].letter] = lastPlayedSound;*/
				break;
			}
		}
		if (inputFile[i].instruction == "jgz")
		{

			if (sounds[inputFile[i].letter] > 0)
			{
				if (inputFile[i].value.find_first_not_of("-0123456789") == std::string::npos)
				{
					i -= 1;
					i+= stoi(inputFile[i+1].value);
				}
				else
				{
					i -= 1;
					i+= sounds[inputFile[i+1].letter] %= sounds[inputFile[i+1].value];
				}
			}

		}
	}

	return std::to_string(lastPlayedSound);
}

std::string Day18::Task2()
{
	std::ifstream file("../Inputs/Day 18.txt");
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

	int lastPlayedSound;
	std::map<std::string, long long> sounds;
	std::map<std::string, long long> sounds2;

	std::map<std::map<std::string, long long>, int>;

	std::list<long long> send1;

	std::list<long long> send2;

	bool p1 = true;
	
	bool p1Done = false;
	bool p2Done = false;

	int send = 0;


	for (auto element : inputFile)
	{
		sounds[element.letter] = 0;
		sounds2[element.letter] = 0;
	}


	int index1 = 0;
	int index2 = 0;
	do
	{
		if (p1)
		{
			for (;index1 < inputFile.size(); index1++)
			{
				if (inputFile[index1].instruction == "snd")
				{
					lastPlayedSound = sounds[inputFile[index1].letter];

					send1.push_back(sounds[inputFile[index1].letter]);
				}
				if (inputFile[index1].instruction == "set")
				{
					if (inputFile[index1].value.find_first_not_of("-0123456789") == std::string::npos)
					{
						sounds[inputFile[index1].letter] = stoi(inputFile[index1].value);
					}
					else
					{
						sounds[inputFile[index1].letter] = sounds[inputFile[index1].value];
					}

				}
				if (inputFile[index1].instruction == "add")
				{
					if (inputFile[index1].value.find_first_not_of("-0123456789") == std::string::npos)
					{
						sounds[inputFile[index1].letter] += stoi(inputFile[index1].value);
					}
					else
					{
						sounds[inputFile[index1].letter] += sounds[inputFile[index1].value];
					}
				}
				if (inputFile[index1].instruction == "mul")
				{
					if (inputFile[index1].value.find_first_not_of("-0123456789") == std::string::npos)
					{
						sounds[inputFile[index1].letter] *= stoi(inputFile[index1].value);
					}
					else
					{
						sounds[inputFile[index1].letter] *= sounds[inputFile[index1].value];
					}
				}
				if (inputFile[index1].instruction == "mod")
				{
					if (inputFile[index1].value.find_first_not_of("-0123456789") == std::string::npos)
					{
						sounds[inputFile[index1].letter] %= stoi(inputFile[index1].value);
					}
					else
					{
						sounds[inputFile[index1].letter] %= sounds[inputFile[index1].value];
					}
				}
				if (inputFile[index1].instruction == "rcv")
				{
					if (send2.size() > 0)
					{
						sounds[inputFile[index2].letter] = send2.front();
						send2.pop_front();
						p1Done = false;
						p2Done = false;
					}
					else
					{
						p1 = false;
						p1Done = true;
						//index1--;
						break;
					}
				}
				if (inputFile[index1].instruction == "jgz")
				{

					if (sounds[inputFile[index1].letter] > 0)
					{
						if (inputFile[index1].value.find_first_not_of("-0123456789") == std::string::npos)
						{
							index1 -= 1;
							index1 += stoi(inputFile[index1 + 1].value);
						}
						else
						{
							index1 -= 1;
							index1 += sounds[inputFile[index1 + 1].letter] %= sounds[inputFile[index1 + 1].value];
						}
					}

				}
			}
		}
		else
		{
			for (; index2 < inputFile.size(); index2++)
			{
				if (inputFile[index2].instruction == "snd")
				{
					send++;
					lastPlayedSound = sounds2[inputFile[index2].letter];
					send2.push_back(sounds2[inputFile[index2].letter]);
				}
				if (inputFile[index2].instruction == "set")
				{
					if (inputFile[index2].value.find_first_not_of("-0123456789") == std::string::npos)
					{
						sounds2[inputFile[index2].letter] = stoi(inputFile[index2].value);
					}
					else
					{
						sounds2[inputFile[index2].letter] = sounds2[inputFile[index2].value];
					}

				}
				if (inputFile[index2].instruction == "add")
				{
					if (inputFile[index2].value.find_first_not_of("-0123456789") == std::string::npos)
					{
						sounds2[inputFile[index2].letter] += stoi(inputFile[index2].value);
					}
					else
					{
						sounds2[inputFile[index2].letter] += sounds2[inputFile[index2].value];
					}
				}
				if (inputFile[index2].instruction == "mul")
				{
					if (inputFile[index2].value.find_first_not_of("-0123456789") == std::string::npos)
					{
						sounds2[inputFile[index2].letter] *= stoi(inputFile[index2].value);
					}
					else
					{
						sounds2[inputFile[index2].letter] *= sounds2[inputFile[index2].value];
					}
				}
				if (inputFile[index2].instruction == "mod")
				{
					if (inputFile[index2].value.find_first_not_of("-0123456789") == std::string::npos)
					{
						sounds2[inputFile[index2].letter] %= stoi(inputFile[index2].value);
					}
					else
					{
						sounds2[inputFile[index2].letter] %= sounds2[inputFile[index2].value];
					}
				}
				if (inputFile[index2].instruction == "rcv")
				{
					if(send1.size() > 0)
					{
						sounds2[inputFile[index2].letter] = send1.front();
						send1.pop_front();
						p1Done = false;
						p2Done = false;
					}
					else
					{
						p1 = true;
						p2Done = true;
						//index2--;
						break;
					}

				}
				if (inputFile[index2].instruction == "jgz")
				{

					if (sounds2[inputFile[index2].letter] > 0)
					{
						if (inputFile[index2].value.find_first_not_of("-0123456789") == std::string::npos)
						{
							index2 -= 1;
							index2 += stoi(inputFile[index2 + 1].value);
						}
						else
						{
							index2 -= 1;
							index2 += sounds2[inputFile[index2 + 1].letter] %= sounds2[inputFile[index2 + 1].value];
						}
					}

				}
			}
		}
	}
	while (!p1Done || !p2Done);

	return std::to_string(send);
}
