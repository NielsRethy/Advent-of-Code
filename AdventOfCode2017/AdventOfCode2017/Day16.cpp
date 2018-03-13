#include "stdafx.h"
#include "Day16.h"
#include <fstream>


Day16::Day16()
{
}


Day16::~Day16()
{
}

std::string Day16::Task1()
{
	std::ifstream file("../Inputs/Day 16.txt");
	std::string str;

	std::vector<info> input;

	int total = 0;

	while (std::getline(file, str))
	{

		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == 's')
			{
				char move;
				std::string instruction1;
				move = str[i];
				i++;
				do
				{

					instruction1 += str[i];
					i++;

					if (i == str.size())
					{
						break;
					}
				} while (str[i] != ',');
				input.push_back(info{ move,instruction1 });
			}
			if (str[i] == 'x' || str[i] == 'p')
			{
				char move;
				std::string instruction1;
				std::string instruction2;
				move = str[i];
				i++;
				do
				{
					instruction1 += str[i];
					i++;
				} while (str[i] != '/');

				i++;
				do
				{
					instruction2 += str[i];
					i++;

					if (i == str.size())
					{
						break;
					}
				} while (str[i] != ',');
				input.push_back(info{ move,instruction1,instruction2 });
			}

		}
	}

	std::string programs{ 'a','b','c','d','e','f' ,'g','h','i','j','k','l','m','n','o','p' };

	for (auto element : input)
	{
		if (element.move == 's')
		{
			spin(programs, stoi(element.instruction1));
		}
		if (element.move == 'x')
		{
			Exchange(programs, std::stoi(element.instruction1), std::stoi(element.instruction2));
		}
		if (element.move == 'p')
		{
			Partner(programs, element.instruction1, element.instruction2);
		}
	}


	return programs;
}

std::string Day16::Task2()
{
	std::ifstream file("../Inputs/Day 16.txt");
	std::string str;

	std::vector<info> input;

	int total = 0;

	while (std::getline(file, str))
	{

		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == 's')
			{
				char move;
				std::string instruction1;
				move = str[i];
				i++;
				do
				{

					instruction1 += str[i];
					i++;

					if (i == str.size())
					{
						break;
					}
				} while (str[i] != ',');
				input.push_back(info{ move,instruction1 });
			}
			if (str[i] == 'x' || str[i] == 'p')
			{
				char move;
				std::string instruction1;
				std::string instruction2;
				move = str[i];
				i++;
				do
				{
					instruction1 += str[i];
					i++;
				} while (str[i] != '/');

				i++;
				do
				{
					instruction2 += str[i];
					i++;

					if (i == str.size())
					{
						break;
					}
				} while (str[i] != ',');
				input.push_back(info{ move,instruction1,instruction2 });
			}

		}
	}

	std::string programs{ 'a','b','c','d','e','f' ,'g','h','i','j','k','l','m','n','o','p' };

	std::map<std::string, int> findRepeat;
	long long repeat = 1000000000;

	for (long long i = 0; i < repeat; ++i)
	{
		for (auto element : input)
		{
			if (element.move == 's')
			{
				spin(programs, stoi(element.instruction1));
			}
			if (element.move == 'x')
			{
				Exchange(programs, std::stoi(element.instruction1), std::stoi(element.instruction2));
			}
			if (element.move == 'p')
			{
				Partner(programs, element.instruction1, element.instruction2);
			}
		}
		if (findRepeat[programs] == 1)
		{
			repeat = repeat % i;
			break;
		}

		findRepeat[programs] += 1;
	}

	programs = { 'a','b','c','d','e','f' ,'g','h','i','j','k','l','m','n','o','p' };
	for (long long i = 0; i < repeat; ++i)
	{
		for (auto element : input)
		{
			if (element.move == 's')
			{
				spin(programs, stoi(element.instruction1));
			}
			if (element.move == 'x')
			{
				Exchange(programs, std::stoi(element.instruction1), std::stoi(element.instruction2));
			}
			if (element.move == 'p')
			{
				Partner(programs, element.instruction1, element.instruction2);
			}
		}
	}


	return programs;
}

void Day16::spin(std::string& dance, int amount)
{
	std::string danceLocal;
	for (int i = 0; i < dance.size(); ++i)
	{
		danceLocal.push_back(dance[(dance.size() - amount + i) % dance.size()]);
	}
	dance = danceLocal;
}

void Day16::Exchange(std::string& dance, int p1, int p2)
{
	char i1 = dance[p1% dance.size()];
	dance[p1% dance.size()] = dance[p2% dance.size()];
	dance[p2% dance.size()] = i1;
}

void Day16::Partner(std::string& dance, std::string p1, std::string p2)
{
	int index1 = 0;
	int index2 = 0;
	for (int i = 0; i < dance.size(); ++i)
	{
		if (dance[i] == p1[0])
		{
			index1 = i;
		}
		if (dance[i] == p2[0])
		{
			index2 = i;
		}
	}

	dance[index1] = p2[0];
	dance[index2] = p1[0];
}
