#include "stdafx.h"
#include "Day25.h"


Day25::Day25()
{
}


Day25::~Day25()
{
}

struct state
{
	char currentState;
	long long value1;
	bool left;
	char newState;
	long long value2;
	bool left2;
	char newState2;
};

std::string Day25::Task1()
{
	std::vector<state> states;
	states.push_back(state{ 'A', 1,false,'B',0,true,'C' });
	states.push_back(state{ 'B', 1,true,'A',1,true,'D' });
	states.push_back(state{ 'C', 1,false,'D',0,false,'C' });
	states.push_back(state{ 'D', 0,true,'B',0,false,'E' });
	states.push_back(state{ 'E', 1,false,'C',1,true,'F' });
	states.push_back(state{ 'F', 1,true,'E',1,false,'A' });

	long long checks = 12656374;
	char currentState = 'A';

	std::vector<long long> diagnostic;

	for (long long i = 0; i < checks; ++i)
	{
		diagnostic.push_back(0);
	}

	int currentIndex = diagnostic.size() / 2;

	for (long long i = 0; i < checks; ++i)
	{
		for (auto element : states)
		{
			if (currentState == element.currentState)
			{
				if (diagnostic[currentIndex] == 0)
				{
					diagnostic[currentIndex] = element.value1;
					if (element.left) currentIndex -= 1;
					else currentIndex += 1;
					currentState = element.newState;
					break;
				}
				else
				{
					diagnostic[currentIndex] = element.value2;
					if (element.left2) currentIndex -= 1;
					else currentIndex += 1;
					currentState = element.newState2;
					break;
				}
			}
		}
	}

	long long sum = 0;

	for (auto element : diagnostic)
	{
		sum += element;
	}
	return std::to_string(sum);
}

std::string Day25::Task2()
{
	return"";
}
