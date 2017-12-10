#include "stdafx.h"
#include "Day10.h"
#include "fstream"
#include <vector>
#include <sstream>
#include <filesystem>


Day10::Day10()
{
}


Day10::~Day10()
{
}

std::string Day10::Task1()
{

	std::ifstream file("../Inputs/Day 10.txt");
	std::string str;

	std::vector<int> numbersInputList;

	std::string number;
	int total = 0;

	while (std::getline(file, str))
	{
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] != ',')
			{
				number += str[i];
				if (i == str.size() - 1)
				{
					numbersInputList.push_back(std::stoi(number));
					number = "";
				}
			}
			else
			{
				numbersInputList.push_back(std::stoi(number));
				number = "";
			}
		}
	}

	//making list
	std::vector<int> circularList;
	int maxValue = 256;

	for (int i = 0; i < maxValue; i++)
	{
		circularList.push_back(i);
	}

	//knot
	int skipSize = 0;

	for (int i = 0; i < numbersInputList.size(); i++)
	{
		ChangeVectorOrder(skipSize, numbersInputList[i], circularList);
		skipSize += numbersInputList[i] + i;
	}

	


	return std::to_string((circularList[0] * circularList[1]));
}

std::string Day10::Task2()
{
	std::ifstream file("../Inputs/Day 10.txt");
	std::string str;

	std::vector<int> numbersInputList;
	std::vector<int> addExtra { 17, 31, 73, 47, 23 };

	std::string number;
	int total = 0;

	while (std::getline(file, str))
	{
		for (int i = 0; i < str.size(); i++)
		{
			numbersInputList.push_back(str[i]);
		}
	}

	for (int i = 0; i < addExtra.size(); i++)
	{
		numbersInputList.push_back(addExtra[i]);
	}

	//making list
	std::vector<int> circularList;
	int maxValue = 256;

	for (int i = 0; i < maxValue; i++)
	{
		circularList.push_back(i);
	}

	//knot
	int skipSize = 0;
	int length = 0;
	int extraLoop = 64;
	std::vector<int> localV;

	localV = numbersInputList;
	for (int i = 0; i < extraLoop; i++)
	{
		for (int a = 0; a < numbersInputList.size(); a++)
		{
			ChangeVectorOrder(length, numbersInputList[a], circularList);
			length += numbersInputList[a] + skipSize;
			skipSize += 1;
			
		}
	
		numbersInputList = localV;
	}

	//hash to dense
	SpareHashToDenseHash(circularList);

	//dex to hex
	std::string result;
	for (int i = 0; i < circularList.size(); i++)
	{
		std::string name;
		std::stringstream ss;
		ss << std::hex << circularList[i];
		ss >> name;
		if (name.size() < 2)
		{
			name = "0" + name;
		}
		result += name;
	}

	return result;
}

void Day10::ChangeVectorOrder(int begin, int end, std::vector<int> &numbers)
{
	std::vector<int> localVec;

	for (int i = begin; i <  begin + end ; i++)
	{
		int number = i % numbers.size();
		localVec.push_back(numbers[i % numbers.size() ]);
	}

	std::reverse(localVec.begin(), localVec.end());
	for (int i = begin; i <  begin + end; i++)
	{
		int number = i % numbers.size();
		numbers[i% numbers.size()] = localVec[i - begin];
	}

}


void Day10::SpareHashToDenseHash(std::vector<int> &spareHash)
{
	std::vector<int> denseHash;

	for (int i = 0; i < spareHash.size(); i+= 16)
	{
		denseHash.push_back(spareHash[i] ^ spareHash[i + 1] ^ spareHash[i + 2] ^ spareHash[i + 3] ^
			spareHash[i + 4] ^ spareHash[i + 5] ^ spareHash[i + 6] ^ spareHash[i + 7] ^
			spareHash[i + 8] ^ spareHash[i + 9] ^ spareHash[i + 10] ^ spareHash[i + 11] ^
			spareHash[i + 12] ^ spareHash[i + 13] ^ spareHash[i + 14] ^ spareHash[i + 15]);
	}
	spareHash = denseHash;

}
