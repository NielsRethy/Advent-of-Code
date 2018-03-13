#include "stdafx.h"
#include "Day15.h"
#include <fstream>


Day15::Day15()
{
}


Day15::~Day15()
{
}

std::string Day15::Task1()
{

	std::ifstream file("../Inputs/Day 15.txt");
	std::string str;
	
	int numberA = 0;
	int numberB = 0;

	int total = 0;

	while (std::getline(file, str))
	{
		if (numberA == 0)
		{
			numberA = std::stoi(str);
		}
		else
		{
			numberB = std::stoi(str);
		}
	}

	std::vector<uint64_t> generatorA;
	std::vector<uint64_t> generatorB;

	uint64_t multiplyA = 16807;
	uint64_t multiplyB = 48271;
	uint64_t dividing = 2147483647;

	uint64_t amountToDo = 40000000;
	int counter = 0;
	for (uint64_t i = 0; i < amountToDo; ++i)
	{
		if (i == 0)
		{
			

			uint64_t nA = numberA * multiplyA % dividing;
			uint64_t nB = numberB * multiplyB % dividing;

			generatorA.push_back(nA);
			generatorB.push_back(nB);

			std::string a = toBinary(nA);
			if (a.size() < 16)
			{
				std::string localstring;
				for (int c = a.size(); c < 16; ++c)
				{
					localstring += '0';
				}
				a = localstring + a;
			}
			else if (a.size() > 16)
			{
				std::string localstring;
				for (int b = 16; b > 0; --b)
				{
					localstring += a[a.size() - b];
				}
				a = localstring;
			}

			//generatorAbinary.push_back(a);

			std::string b = toBinary(nB);
			if (b.size() < 16)
			{
				std::string localstring;
				for (int c = b.size(); c < 16; ++c)
				{
					localstring += '0';
				}
				b = localstring + b;
			}
			else if (b.size() > 16)
			{
				std::string localstring;
				for (int e = 16; e > 0; --e)
				{
					localstring += b[b.size() - e];
				}
				b = localstring;
			}
			//generatorBbinary.push_back(b);

			if (a == b)
			{
				counter++;
			}
		}
		else
		{
			/*auto a = (generatorA[i - 1] * multiplyA) % 0x7fffffff;
			generatorA.push_back((generatorA[i - 1] * multiplyA) % dividing);
			generatorB.push_back(generatorB[i - 1] * multiplyB % dividing);*/

			uint64_t nA = generatorA[i - 1] * multiplyA % dividing;
			uint64_t nB = generatorB[i - 1] * multiplyB % dividing;

			generatorA.push_back(nA);
			generatorB.push_back(nB);

			std::string a = toBinary(nA);
			if (a.size() < 16)
			{
				std::string localstring;
				for (int c = a.size(); c < 16; ++c)
				{
					localstring += '0';
				}
				a = localstring + a;
			}
			else if (a.size() > 16)
			{
				std::string localstring;
				for (int b = 16; b > 0; --b)
				{
					localstring += a[a.size() - b];
				}
				a = localstring;
			}

			//generatorAbinary.push_back(a);

			std::string b = toBinary(nB);
			if (b.size() < 16)
			{
				std::string localstring;
				for (int c = b.size(); c < 16; ++c)
				{
					localstring += '0';
				}
				b = localstring + b;
			}
			else if (b.size() > 16)
			{
				std::string localstring;
				for (int e = 16; e > 0; --e)
				{
					localstring += b[b.size() - e];
				}
				b = localstring;
			}
			//generatorBbinary.push_back(b);

			if (a == b)
			{
				counter++;
			}
		}
	}

	/*std::vector<std::string> generatorAbinary;
	std::vector<std::string> generatorBbinary;


	for (int i = 0; i < generatorA.size(); ++i)
	{
		std::string a = toBinary(generatorA[i]);
		if (a.size() < 16)
		{
			std::string localstring;
			for (int c = a.size(); c <  16; ++c)
			{
				localstring += '0';
			}
			a = localstring + a;
		}
		else if (a.size() > 16)
		{
			std::string localstring;
			for (int b = 16; b > 0; --b)
			{
				localstring += a[a.size() - b];
			}
			a = localstring;
		}

		generatorAbinary.push_back(a);

		std::string b = toBinary(generatorB[i]);
		if (b.size() < 16)
		{
			std::string localstring;
			for (int c = b.size(); c < 16; ++c)
			{
				localstring += '0';
			}
			b = localstring + b;
		}
		else if (b.size() > 16)
		{
			std::string localstring;
			for (int e = 16; e > 0; --e)
			{
				localstring += b[b.size() - e];
			}
			b = localstring;
		}
		generatorBbinary.push_back(b);
	}

	int counter = 0;
	for (int i = 0; i < generatorBbinary.size(); ++i)
	{
		if (generatorBbinary[i] == generatorAbinary[i])
		{
			counter++;
		}
	}*/


	return std::to_string(counter);
}

std::string Day15::Task2()
{

	std::ifstream file("../Inputs/Day 15.txt");
	std::string str;

	int numberA = 0;
	int numberB = 0;

	int total = 0;

	while (std::getline(file, str))
	{
		if (numberA == 0)
		{
			numberA = std::stoi(str);
		}
		else
		{
			numberB = std::stoi(str);
		}
	}

	std::vector<uint64_t> generatorA;
	std::vector<uint64_t> generatorB;

	uint64_t multiplyA = 16807;
	uint64_t multiplyB = 48271;
	uint64_t dividing = 2147483647;

	uint64_t amountToDo = 5000000;

	int findMultiplyA = 4;
	int findMultiplyB = 8;

	int counter = 0;
	for (uint64_t i = 0; i < amountToDo; ++i)
	{
		if (i == 0)
		{

			uint64_t nA = numberA * multiplyA % dividing;

			do
			{
				nA = nA * multiplyA % dividing;
			} while (nA % findMultiplyA != 0);

			uint64_t nB = numberB * multiplyB % dividing;
			do
			{
				nB = nB * multiplyB % dividing;
			} while (nB % findMultiplyB != 0);

			generatorA.push_back(nA);
			generatorB.push_back(nB);

			std::string a = toBinary(nA);
			if (a.size() < 16)
			{
				std::string localstring;
				for (int c = a.size(); c < 16; ++c)
				{
					localstring += '0';
				}
				a = localstring + a;
			}
			else if (a.size() > 16)
			{
				std::string localstring;
				for (int b = 16; b > 0; --b)
				{
					localstring += a[a.size() - b];
				}
				a = localstring;
			}

			//generatorAbinary.push_back(a);

			std::string b = toBinary(nB);
			if (b.size() < 16)
			{
				std::string localstring;
				for (int c = b.size(); c < 16; ++c)
				{
					localstring += '0';
				}
				b = localstring + b;
			}
			else if (b.size() > 16)
			{
				std::string localstring;
				for (int e = 16; e > 0; --e)
				{
					localstring += b[b.size() - e];
				}
				b = localstring;
			}
			//generatorBbinary.push_back(b);

			if (a == b)
			{
				counter++;
			}
		}
		else
		{
			/*auto a = (generatorA[i - 1] * multiplyA) % 0x7fffffff;
			generatorA.push_back((generatorA[i - 1] * multiplyA) % dividing);
			generatorB.push_back(generatorB[i - 1] * multiplyB % dividing);*/

			
			uint64_t nA = generatorA[i - 1] * multiplyA % dividing;
			if (nA % findMultiplyA != 0)
			{
				do
				{
					nA = nA * multiplyA % dividing;
				} while (nA % findMultiplyA != 0);
			}
	

			uint64_t nB = generatorB[i - 1] * multiplyB % dividing;
			if (nB % findMultiplyB != 0)
			{
				do
				{
					nB = nB * multiplyB % dividing;
				} while (nB % findMultiplyB != 0);
			}


			generatorA.push_back(nA);
			generatorB.push_back(nB);

			std::string a = toBinary(nA);
			if (a.size() < 16)
			{
				std::string localstring;
				for (int c = a.size(); c < 16; ++c)
				{
					localstring += '0';
				}
				a = localstring + a;
			}
			else if (a.size() > 16)
			{
				std::string localstring;
				for (int b = 16; b > 0; --b)
				{
					localstring += a[a.size() - b];
				}
				a = localstring;
			}

			//generatorAbinary.push_back(a);

			std::string b = toBinary(nB);
			if (b.size() < 16)
			{
				std::string localstring;
				for (int c = b.size(); c < 16; ++c)
				{
					localstring += '0';
				}
				b = localstring + b;
			}
			else if (b.size() > 16)
			{
				std::string localstring;
				for (int e = 16; e > 0; --e)
				{
					localstring += b[b.size() - e];
				}
				b = localstring;
			}
			//generatorBbinary.push_back(b);

			if (i == 1050)
			{
				int t = 0;
			}
			if (a == b)
			{
				counter++;
			}
		}
	}
	return std::to_string(counter);
}
std::string Day15::HexToBin(std::string value)
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
std::string Day15::toBinary(int n)
{
	std::string r;
	while (n != 0) { r = (n % 2 == 0 ? "0" : "1") + r; n /= 2; }
	return r;
}