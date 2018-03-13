#include "stdafx.h"
#include "Day20.h"
#include <fstream>
#include <map>


Day20::Day20()
{
}


Day20::~Day20()
{
}


struct Vector3
{
	long long x;
	long long y;
	long long z;
};

struct Particle
{
	Vector3 Position;
	Vector3 Velocity;
	Vector3 Acceleration;
};

std::string Day20::Task1()
{
	std::ifstream file("../Inputs/Day 20.txt");
	std::string str;

	std::vector<Particle> input;

	while (std::getline(file, str))
	{
		std::string number;
		Particle par;
		bool p = false;
		bool v = false;
		bool a = false;

		bool p1 = false;
		bool p2 = false;
		bool p3 = false;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == 'p')
			{
				p = true;
				v = false;
				a = false;
			}
			if (str[i] == 'v')
			{
				p = false;
				v = true;
				a = false;
			}
			if (str[i] == 'a')
			{
				p = false;
				v = false;
				a = true;
			}
			if (str[i] == '-' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9' || str[i] == '0')
			{
				number += str[i];
				p1 = true;
			}
			else if (str[i] == ',' || str[i] == '>')
			{
				if (p)
				{
					if (p3)
					{
						par.Position.z = std::stoi(number);
						number = "";
						p3 = false;
						p1 = false;
					}
					else if (p2)
					{
						par.Position.y = std::stoi(number);
						number = "";
						p2 = false;
						p3 = true;
					}
					else if (p1)
					{
						par.Position.x = std::stoi(number);
						number = "";
						p1 = false;
						p2 = true;
					}
				}
				if (v)
				{
					if (p3)
					{
						par.Velocity.z = std::stoi(number);
						number = "";
						p3 = false;
						p1 = false;
					}
					else if (p2)
					{
						par.Velocity.y = std::stoi(number);
						number = "";
						p2 = false;
						p3 = true;
					}
					else if (p1)
					{
						par.Velocity.x = std::stoi(number);
						number = "";
						p1 = false;
						p2 = true;
					}
				}
				if (a)
				{
					if (p3)
					{
						par.Acceleration.z = std::stoi(number);
						number = "";
						p3 = false;
						p1 = false;
					}
					else if (p2)
					{
						par.Acceleration.y = std::stoi(number);
						number = "";
						p2 = false;
						p3 = true;
					}
					else if (p1)
					{
						par.Acceleration.x = std::stoi(number);
						number = "";
						p1 = false;
						p2 = true;
					}
				}
			}
		}

		input.push_back(par);
	}

	int index = 0;
	int closestNumber = INT_MAX;

	std::map<int, int> indexes;

	for (int i = 0; i < 1000; ++i)
	{
		for (int a = 0; a < input.size(); ++a)
		{
			input[a].Velocity.x += input[a].Acceleration.x;
			input[a].Velocity.y += input[a].Acceleration.y;
			input[a].Velocity.z += input[a].Acceleration.z;

			input[a].Position.x += input[a].Velocity.x;
			input[a].Position.y += input[a].Velocity.y;
			input[a].Position.z += input[a].Velocity.z;


			if (abs(input[a].Position.x) + abs(input[a].Position.y) + abs(input[a].Position.z) < closestNumber)
			{
				index = a;
				closestNumber = abs(input[a].Position.x) + abs(input[a].Position.y) + abs(input[a].Position.z);
			}
		}
		closestNumber = INT_MAX;
		indexes[index] += 1;
		index = 0;

	}
	int counter = 0;
	for (auto element : indexes)
	{
		if (element.second > counter)
		{
			counter = element.second;
			index = element.first;
		}
	}


	return std::to_string(index);

}

std::string Day20::Task2()
{

	std::ifstream file("../Inputs/Day 20.txt");
	std::string str;

	std::vector<Particle> input;

	while (std::getline(file, str))
	{
		std::string number;
		Particle par;
		bool p = false;
		bool v = false;
		bool a = false;

		bool p1 = false;
		bool p2 = false;
		bool p3 = false;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == 'p')
			{
				p = true;
				v = false;
				a = false;
			}
			if (str[i] == 'v')
			{
				p = false;
				v = true;
				a = false;
			}
			if (str[i] == 'a')
			{
				p = false;
				v = false;
				a = true;
			}
			if (str[i] == '-' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9' || str[i] == '0')
			{
				number += str[i];
				p1 = true;
			}
			else if (str[i] == ',' || str[i] == '>')
			{
				if (p)
				{
					if (p3)
					{
						par.Position.z = std::stoi(number);
						number = "";
						p3 = false;
						p1 = false;
					}
					else if (p2)
					{
						par.Position.y = std::stoi(number);
						number = "";
						p2 = false;
						p3 = true;
					}
					else if (p1)
					{
						par.Position.x = std::stoi(number);
						number = "";
						p1 = false;
						p2 = true;
					}
				}
				if (v)
				{
					if (p3)
					{
						par.Velocity.z = std::stoi(number);
						number = "";
						p3 = false;
						p1 = false;
					}
					else if (p2)
					{
						par.Velocity.y = std::stoi(number);
						number = "";
						p2 = false;
						p3 = true;
					}
					else if (p1)
					{
						par.Velocity.x = std::stoi(number);
						number = "";
						p1 = false;
						p2 = true;
					}
				}
				if (a)
				{
					if (p3)
					{
						par.Acceleration.z = std::stoi(number);
						number = "";
						p3 = false;
						p1 = false;
					}
					else if (p2)
					{
						par.Acceleration.y = std::stoi(number);
						number = "";
						p2 = false;
						p3 = true;
					}
					else if (p1)
					{
						par.Acceleration.x = std::stoi(number);
						number = "";
						p1 = false;
						p2 = true;
					}
				}
			}
		}

		input.push_back(par);
	}

	int index = 0;
	int closestNumber = INT_MAX;

	std::map<int, int> indexes;

	for (int i = 0; i < 100; ++i)
	{
		for (int a = 0; a < input.size(); ++a)
		{
			input[a].Velocity.x += input[a].Acceleration.x;
			input[a].Velocity.y += input[a].Acceleration.y;
			input[a].Velocity.z += input[a].Acceleration.z;

			input[a].Position.x += input[a].Velocity.x;
			input[a].Position.y += input[a].Velocity.y;
			input[a].Position.z += input[a].Velocity.z;

		}
		for (int a = 0; a < input.size(); ++a)
		{
			bool remove = false;
			std::vector<int> removeindex;
			for (int b = 0; b < input.size(); ++b)
			{
				if (a != b)
				{
					if (input[a].Position.x == input[b].Position.x &&input[a].Position.y == input[b].Position.y && input[a].Position.z == input[b].Position.z)
					{
						removeindex.push_back(b);
						remove = true;
					}

				}

			}

			if (remove)
			{
				removeindex.push_back(a);
				std::vector<Particle> local;
				for (int d = 0; d < input.size(); ++d)
				{
					bool add = true;
					for (int e = 0; e < removeindex.size(); ++e)
					{
						if (d == removeindex[e])
						{
							add = false;
						}
					}
					if (add)
					{
						local.push_back(input[d]);
					}
				}
				input = local;

			}

		}
	}
	

	return std::to_string(input.size());

}
