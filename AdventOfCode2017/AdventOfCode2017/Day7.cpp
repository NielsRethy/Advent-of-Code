#include "stdafx.h"
#include "Day7.h"
#include  "string"
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>
#include <iostream>


Day7::Day7()
{
}


Day7::~Day7()
{
}


struct information
{
	std::string name;
	int weight;
	bool holdingDisc;
	std::vector<std::string> info;
	std::string above;

	/*bool const operator==(const information &o) const {
		return name == o.name && weight == o.weight && holdingDisc == o.holdingDisc ;
	}

	bool const operator<(const information &o) const {
		return weight < o.weight ;
	}*/
};

std::string Day7::Task1()
{
	std::ifstream file("../Inputs/Day 7.txt");
	std::string str;


	bool valid = true;
	int total = 0;

	//std::map<int , information> discs;

	std::vector<information> discs;

	while (std::getline(file, str))
	{
		total++;
		std::string word = "";
		std::string number = "";
		bool SubDisc = false;
		bool foundWord = false;
		bool foundNumber = false;
		std::vector<std::string> names;
		std::string addWord;

		for (int i = 0; i < str.size(); i++)
		{
			if (foundWord && str[i] != ')' && foundWord && str[i] != '(' && !foundNumber)
			{
				number += str[i];
			}
			else if (str[i] == ')')
			{
				foundNumber = true;
			}

			if (str[i] != ' ' && !foundWord)
			{
				word += str[i];
			}
			else if (str[i] == ' ')
			{
				foundWord = true;
			}

		

			if (SubDisc && str[i] != ' ' && foundWord && str[i] != ',')
			{
				addWord += str[i];
				if (i == str.size() - 1)
				{
					names.push_back(addWord);
					
				}
			}
			else if (SubDisc && str[i] == ',')
			{
				names.push_back(addWord);
				addWord = "";
			}
			if (str[i] == '>')
			{
				SubDisc = true;
			}
		}

		discs.push_back(information{ word, std::stoi(number), SubDisc ,names, "" });
		//discs[total] = information{ word, std::stoi(number), SubDisc ,names, "" };

	}

	
	
	
		for (int a = 0; a < discs.size(); a++)
		{
			for (int i = 0; i < discs[a].info.size(); i++)
			{
				for (int b = 0; b < discs.size(); b++)
				{
					if (discs[b].name ==discs[a].info[i])
					{
						discs[b].above = discs[a].name;
					}
				}
			}
		}


	for (auto element : discs)
	{
		if (element.above == "")
		{
			return element.name;
		}
	}
	

	
}

struct information2
{
	std::string name;
	int weight;
	bool holdingDisc;
	std::vector<std::string> info;
	information2 *above;
	int counterAbove;
	std::vector<information2*> infoStruct;
	int totalValue;
	bool correct = false;
	int weigth2;

	/*bool const operator==(const information &o) const {
	return name == o.name && weight == o.weight && holdingDisc == o.holdingDisc ;
	}

	bool const operator<(const information &o) const {
	return weight < o.weight ;
	}*/
};
bool sortVec(information2 a, information2 b) { return  (a.counterAbove < b.counterAbove); }

std::string Day7::Task2()
{
	std::ifstream file("../Inputs/Day 7.txt");
	std::string str;


	bool valid = true;
	int total = 0;

	//std::map<int , information> discs;

	std::vector<information2> discs;

	while (std::getline(file, str))
	{
		total++;
		std::string word = "";
		std::string number = "";
		bool SubDisc = false;
		bool foundWord = false;
		bool foundNumber = false;
		std::vector<std::string> names;
		std::string addWord;

		for (int i = 0; i < str.size(); i++)
		{
			if (foundWord && str[i] != ')' && foundWord && str[i] != '(' && !foundNumber)
			{
				number += str[i];
			}
			else if (str[i] == ')')
			{
				foundNumber = true;
			}

			if (str[i] != ' ' && !foundWord)
			{
				word += str[i];
			}
			else if (str[i] == ' ')
			{
				foundWord = true;
			}



			if (SubDisc && str[i] != ' ' && foundWord && str[i] != ',')
			{
				addWord += str[i];
				if (i == str.size() - 1)
				{
					names.push_back(addWord);

				}
			}
			else if (SubDisc && str[i] == ',')
			{
				names.push_back(addWord);
				addWord = "";
			}
			if (str[i] == '>')
			{
				SubDisc = true;
			}
		}
		std::vector<information2*> d;

		discs.push_back(information2{ word, std::stoi(number), SubDisc ,names, nullptr,0,d,std::stoi(number),false,std::stoi(number) });
		//discs[total] = information{ word, std::stoi(number), SubDisc ,names, "" };

	}




	for (int a = 0; a < discs.size(); a++)
	{
		for (int i = 0; i < discs[a].info.size(); i++)
		{
			for (int b = 0; b < discs.size(); b++)
			{
				if (discs[b].name == discs[a].info[i])
				{
					discs[b].above = &discs[a];
				}

				if (discs[a].info[i] == discs[b].name)
				{
					discs[a].infoStruct.push_back(&discs[b]);
					discs[a].totalValue += discs[b].weight;
				}
			}
		}
	}

	//std::sort(discs.begin(), discs.end(), sortVec);




	std::vector<std::string> FirstOne;

	

	for (int i = 0; i < discs.size(); i++)
	{

		information2 *a = &discs[i];
		int counter = 0;
		do
		{
			a = a->above;

			if (a!= nullptr)
			{
				counter++;
			}

		} while (a != nullptr);
		discs[i].counterAbove = counter;
	}


	std::sort(discs.begin(), discs.end(), sortVec);


	for (int b = 0; b < discs.size(); b++)
	{

		discs[b].totalValue = discs[b].weight;
		
	}


	for (int a = discs.size() - 1; a > 0 ; a--)
	{
		for (int i = 0; i < discs[a].info.size(); i++)
		{
			for (int b = 0; b < discs.size(); b++)
			{
				
				if (discs[a].info[i] == discs[b].name)
				{
					discs[a].weight += discs[b].weight;
				}
			}
		}
	}


	int counter = 1;

	information2 above;
	information2 LastOne;
	int minNumber;

	for (int a = 0; a < discs.size(); a++)
	{
		if (discs[a].above == nullptr)
		{
			above = discs[a];
		}
	}

	/*do {

		for (int a = 0; a < discs.size(); a++)
		{

			if (discs[a].counterAbove == counter && discs[a].holdingDisc)
			{

				std::map<int, int> num;
				int numberToCompare = 0;
				int number = 0;
				for (int i = 0; i < discs[i].infoStruct.size(); i++)
				{
					num[discs[i].totalValue] += 1;
				}

				for (auto t : num)
				{
					if (t.second > number)
					{
						number = t.second;
						numberToCompare = t.first;
					}
				}
				if (numberToCompare != 0)
				{

					for (int b = 0; b < discs[a].infoStruct.size(); b++)
					{
						if (discs[a].infoStruct[b]->totalValue != numberToCompare)
						{
							discs[a].weight -= discs[a].totalValue - numberToCompare;
						}
					}

				}
			}
		}

		--counter;
		int test = 0;

	}
	while (counter > 0);*/

	do {

		std::map<int, information2> num;
		int number = 0;
		int numberToCompare = 0;

		for (int a = 0; a < discs.size(); a++)
		{
			if (discs[a].counterAbove == counter )
			{
				for (int b = 0; b < above.info.size(); b++)
				{
					if (discs[a].name == above.info[b])
					{
						if (num.find(discs[a].weight) == num.end()) {
							// not found

							num[discs[a].weight] = discs[a];
							num[discs[a].weight].correct = true;
						}
						else {
							// found
							num[discs[a].weight].correct = false;
							num[discs[a].weight] = discs[a];
							num[discs[a].weight].correct = false;
						}
					}

				}
			}
		}
		for (auto t : num)
		{
			if (t.second.correct )
			{
				above = t.second;
				LastOne = t.second;
			}
		}
		

		++counter;
		int test = 0;

	} while (counter < 5);

	/*do
	{
		std::map<int, int> num;
		int numberToCompare = 0;
		for (int i = 0; i < discs.size(); i++)
		{
			if (discs[i].counterAbove == counter && discs[i].holdingDisc)
			{
				num[discs[i].totalValue] += 1;
			}
		}
		

		int number = 0;
		for (auto t : num)
		{
			if (t.second > number)
			{
				number = t.second;
				numberToCompare = t.first;
			}
		}

		if (numberToCompare != 0)
		{
			
			for (int i = 0; i < discs.size(); i++)
			{
				if (discs[i].totalValue != numberToCompare && discs[i].holdingDisc  && discs[i].counterAbove == counter)
				{
					discs[i].weight -=  discs[i].totalValue - numberToCompare ;
				}
			}

		}
		
		--counter;
		int test = 0;
			
	}
	while (counter > 0);
*/
	/*for (int i = discs.size() - 1; i >= 0; i--)
	{
		int startvalue = i;
		std::map<std::string, int> values;
		do
		{
			if (!discs[i].holdingDisc)
			{
				break;
			}
			else
			{
				int v = 0;
				for (int b = 0; b < discs[i].infoStruct.size(); b++)
				{
					v += discs[i].infoStruct[b]->weight;
				}
				values[discs[i].name] = v + discs[i].weight;
			}
			i--;
		}
		while (discs[i].counterAbove == discs[startvalue].counterAbove);

		int test = 0;
	}*/



	//do
	//{
	//	std::map<int, int> num;
	//	int numberToCompare = 0;
	//	for (int i = 0; i < discs.size(); i++)
	//	{
	//		if (discs[i].counterAbove == counter && discs[i].holdingDisc)
	//		{
	//			num[discs[i].totalValue] += 1;
	//		}
	//	}

	//	
	//	--counter;
	//	int test = 0;

	//}
	//while (counter < 0);

	//find difference

	int n1 = 0;
	int n2 = 0;
	for (int a = 0; a < discs.size(); a++)
	{
		
		if (discs[a].counterAbove == 1)
		{
			if(n1 != discs[a].weight && n1 == 0 )
			{
				n1 = discs[a].weight;
			}
			else if (n1 != discs[a].weight && n2 != discs[a].weight && n2 == 0)
			{
				n2 = discs[a].weight;
			}
		}
	}

	return std::to_string((LastOne.weigth2 - abs(n1-n2)));


}

