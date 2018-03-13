#include "stdafx.h"
#include "Day14.h"
#include <fstream>
#include <sstream>
#include <algorithm>


Day14::Day14()
{
}


Day14::~Day14()
{
}

std::string Day14::Task1()
{

	std::ifstream file("../Inputs/Day 14.txt");
	std::string input;

	std::getline(file, input);
	
	std::vector<int> numbersInputList;
	std::vector<int> addExtra{ 17, 31, 73, 47, 23 };

	for (char c : input)
	{
		numbersInputList.push_back(c);
	}
	std::vector<int> copy = numbersInputList;

	std::getline(file, input);


	int totalCounter = 0;
	for (int i = 0; i < 128; i++)
	{

		numbersInputList = copy;

		numbersInputList.push_back('-');
		std::string test = std::to_string(i);

		for (auto element : test)
		{
			numbersInputList.push_back(element);
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

		result = HexToBin(result);


		int counter = 0;
		for (auto e : result)
		{
			if (e == '1')
			{
				counter++;
			}
		}

		totalCounter += counter;
	}

	


	return std::to_string(totalCounter);
}

std::string Day14::Task2()
{

	std::ifstream file("../Inputs/Day 14.txt");
	std::string input;

	std::getline(file, input);

	std::vector<int> numbersInputList;
	std::vector<int> addExtra{ 17, 31, 73, 47, 23 };

	for (char c : input)
	{
		numbersInputList.push_back(c);
	}
	std::vector<int> copy = numbersInputList;

	std::getline(file, input);


	std::vector<std::string> values;

	int totalCounter = 0;
	for (int i = 0; i < 128; i++)
	{

		numbersInputList = copy;

		numbersInputList.push_back('-');
		std::string test = std::to_string(i);

		for (auto element : test)
		{
			numbersInputList.push_back(element);
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

		result = HexToBin(result);


		int counter = 0;
		for (auto e : result)
		{
			if (e == '1')
			{
				counter++;
			}
		}

		totalCounter += counter;

		values.push_back(result);
	}

	
	int count = 0;

	for (int a = 0; a < values.size(); a++) {

		for (int b = 0; b < values[a].length(); b++) 
		{
			/*if (values[a][b] == '1')
			{
				int counter = 0;

				bool checkaUp = true;
				bool checkbUp = true;
				bool checkaDown = true;
				bool checkbDown = true;
				do
				{

					if (a + counter >= values.size()) checkaUp = false;
					if (a - counter< 0) checkaDown = false;
					if (b - counter< 0) checkbDown = false;
					if (b + counter >= values.size()) checkbUp = false;


					if (checkaUp && values[a + counter][b] == '1')
					{
						values[a + counter][b] = 'x';
					}
					else { checkaUp = false; }
					if (checkbUp && values[a ][b + counter] == '1')
					{
						values[a ][b + counter] = 'x';
					}
					else { checkbUp = false; }
					if (checkaDown && values[a - counter][b] == '1')
					{
						values[a - counter][b] = 'x';
					}
					else { checkaDown = false; }
					if (checkbDown && values[a][b -counter] == '1')
					{
						values[a][b - counter] = 'x';
					}
					else { checkbDown = false; }

					counter++;
				}
				while (checkaUp || checkbUp || checkaDown || checkbDown);
				values[a][b] = 'x';
				count++;

			}
*/
			if (NextRegion(128,128,values, a, b))
			{
				count++;
			}
		}
	}


	return std::to_string(count);
}

std::string Day14::HexToBin(std::string value)
{
	std::string sReturn = "";
	for (int i = 0; i < value.length(); ++i)
	{
		switch (value[i])
		{
		case '0': sReturn.append("0000"); break;
		case '1': sReturn.append("0001"); break;
		case '2': sReturn.append("0010"); break;
		case '3': sReturn.append("0011"); break;
		case '4': sReturn.append("0100"); break;
		case '5': sReturn.append("0101"); break;
		case '6': sReturn.append("0110"); break;
		case '7': sReturn.append("0111"); break;
		case '8': sReturn.append("1000"); break;
		case '9': sReturn.append("1001"); break;
		case 'a': sReturn.append("1010"); break;
		case 'b': sReturn.append("1011"); break;
		case 'c': sReturn.append("1100"); break;
		case 'd': sReturn.append("1101"); break;
		case 'e': sReturn.append("1110"); break;
		case 'f': sReturn.append("1111"); break;
		}
	}
	return sReturn;
}

void Day14::SpareHashToDenseHash(std::vector<int> &spareHash)
{
	std::vector<int> denseHash;

	for (int i = 0; i < spareHash.size(); i += 16)
	{
		denseHash.push_back(spareHash[i] ^ spareHash[i + 1] ^ spareHash[i + 2] ^ spareHash[i + 3] ^
			spareHash[i + 4] ^ spareHash[i + 5] ^ spareHash[i + 6] ^ spareHash[i + 7] ^
			spareHash[i + 8] ^ spareHash[i + 9] ^ spareHash[i + 10] ^ spareHash[i + 11] ^
			spareHash[i + 12] ^ spareHash[i + 13] ^ spareHash[i + 14] ^ spareHash[i + 15]);
	}
	spareHash = denseHash;

}
void Day14::ChangeVectorOrder(int begin, int end, std::vector<int> &numbers)
{
	std::vector<int> localVec;

	for (int i = begin; i < begin + end; i++)
	{
		int number = i % numbers.size();
		localVec.push_back(numbers[i % numbers.size()]);
	}

	std::reverse(localVec.begin(), localVec.end());
	for (int i = begin; i < begin + end; i++)
	{
		int number = i % numbers.size();
		numbers[i% numbers.size()] = localVec[i - begin];
	}

}

bool Day14::NextRegion(int maxRow, int maxCollom, std::vector<std::string> &info, int row, int collom)
{

	bool checkaUp = true;
	bool checkaDown = true;
	bool checkbDown = true;
	bool checkbUp = true;

	if (row + 1 >= maxRow) checkaUp = false;
	
	if (row - 1< 0) checkaDown = false;
	if (collom - 1< 0) checkbDown = false;
	if (collom + 1 >= maxCollom) checkbUp = false;

	//find next neighbour
	if (info[row][collom] == '1') {
		info[row][collom] = 'x';

		if (checkaUp)
		{
			if (info[row + 1][collom] == '1')
			{
				NextRegion(maxRow, maxCollom, info, row + 1, collom);
			}
		}
		if (checkaDown)
		{
			if (info[row - 1][collom] == '1')
			{
				NextRegion(maxRow, maxCollom, info, row - 1, collom);
			}
		}
		if (checkbDown)
		{
			if (info[row ][collom - 1] == '1')
			{
				NextRegion(maxRow, maxCollom, info, row, collom - 1);
			}
		}
		if (checkbUp)
		{
			if (info[row ][collom + 1] == '1')
			{
				NextRegion(maxRow, maxCollom, info, row, collom + 1);
			}
		}

		return true;
	}


	return false;
}
