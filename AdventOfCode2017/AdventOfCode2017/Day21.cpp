#include "stdafx.h"
#include "Day21.h"
#include <fstream>
#include <map>
#include <iostream>


Day21::Day21()
{
}


Day21::~Day21()
{
}
//
//struct fractal
//{
//	std::vector<int>
//	int std::hash = 0;
//	int point = 0;
//	int size = 0;
//};

std::string Day21::Task1()
{
	std::ifstream file("../Inputs/Day 21.txt");
	std::string str;

	std::vector<std::vector<std::string>> version1;
	std::vector<std::vector<std::string>> version2;

	while (std::getline(file, str))
	{
		bool v1 = true;
		std::vector<std::string> f1;
		std::vector<std::string> f2;
		std::string local;
		for (int i = 0; i < str.size(); i++)
		{
			
			if (str[i] == '/' || str[i] == ' ' && local.size() != 0)
			{
				if (v1)
				{
					f1.push_back(local);
				}
				else
				{
					f2.push_back(local);
				}
				local = "";
			}
			if (str[i] == '=')
			{
				v1 = false;
			}

			if (str[i] == '.' || str[i] == '#')
			{
				local += str[i];
			}
			if (i == str.size() - 1)
			{
				f2.push_back(local);
				local = "";
			}
		}
		version1.push_back(f1);
		version2.push_back(f2);
		
	}

	std::vector<std::string> start;
	start.push_back(".#.");
	start.push_back("..#");
	start.push_back("###");
	std::vector<std::vector<std::string>> square;

	for (int a = 0; a < 2; ++a)
	{


		for (int i = 0; i < 5; ++i)
		{
			std::cout << "rotate" << std::to_string(i) << std::endl;
			for (auto element : start)
			{
				std::cout << element;
			}
			std::cout << std::endl;

			Rotate(start);
		}
		std::cout << "flip" << std::endl;
		std::reverse(start.begin(), start.end());
	}

	for (int i = 0; i < 1; ++i)
	{
		/*int size = 0;
		for (int a = 0; a < start.size(); ++a)
		{
			size += start[a].size();
		}*/

		if ((int)sqrt(start.size() * start[0].size()) % 2 == 0)
		{
			square.clear();
			for (int a = 0; a < start.size() ; a+=2)
			{
				for (int b = 0; b < start[a].size(); b += 2)
				{
					std::vector<std::string> devision;
					std::string t;
					t += start[a][b];
					t += start[a][b + 1];
					devision.push_back(t);
					t = "";
					t += start[a + 1][b];
					t += start[a + 1][b + 1];
					devision.push_back(t);
					square.push_back(devision);
				}
			
			}

		}
		else if ((int)sqrt(start.size() * start[0].size()) % 3 == 0)
		{
			square.clear();
			for (int a = 0; a < start.size(); a+=3)
			{
				for (int b = 0; b <  start[a].size(); b += 3)
				{
					std::vector<std::string> devision;
					std::string t;
					t += start[a][b];
					t += start[a][b + 1];
					t += start[a][b + 2];
					devision.push_back(t);
					t = "";
					t += start[a + 1][b];
					t += start[a + 1][b + 1];
					t += start[a + 1][b + 2];
					devision.push_back(t);
					t = "";
					t += start[a + 2][b];
					t += start[a + 2][b + 1];
					t += start[a + 2][b + 2];
					devision.push_back(t);
					t = "";
					square.push_back(devision);
				}
			}
		}

		std::vector<std::vector<std::string>> rotate = square;

		bool goOut = false;
			for (int a = 0; a < rotate.size(); ++a)
			{
				for (int e = 0; e < 2; ++e)
				{
					for (int k = 0; k < 4; ++k)
					{
						for (int b = 0; b < version1.size(); ++b)
						{
							if (rotate[a].size() == version1[b].size())
							{
								if (rotate[a] == version1[b])
								{
									square[a] = version2[b];
									goOut = true;
									break;
								}
							}
							if (goOut) break;
						}
						if (goOut) break;
						
						Rotate(rotate[a]);
					}
					if (goOut) break;
					std::reverse(rotate[a].begin(), rotate[a].end());
				}
				goOut = false;
				
			}


		
		//for (int a = 0; a < square.size(); ++a)
		//{
		//	/*int pointsSquare = 0;
		//	for (int b = 0; b < square[a].size(); ++b)
		//	{
		//		for (int c = 0; c < square[a][b].size(); ++c)
		//		{
		//			if (square[a][b][c] == '.')
		//			{
		//				pointsSquare++;
		//			}
		//		}
		//		
		//	}
		//	for (int b = 0; b < version1.size(); ++b)
		//	{
		//		int pointsVersion = 0;
		//		if (square[a].size() == version1[b].size())
		//		{
		//			for (int c = 0; c < version1[b].size(); ++c)
		//			{
		//				for (int d = 0; d < version1[b][c].size(); ++d)
		//				{
		//					if (version1[b][c][d] == '.')
		//					{
		//						pointsVersion++;
		//					}
		//				}

		//			}

		//			if (pointsVersion == pointsSquare)
		//			{
		//				square[a] = version2[b];
		//				break;
		//			}
		//		}
		//		
		//	}*/
		//	
		//}
		start.clear();

	/*	for (auto element : square)
		{
			for (auto ele : element)
			{
				std::cout << ele << "/";
			}
		}
		std::cout << std::endl; */


		for (int a = 0; a < square.size(); a+= sqrt(square.size()))
		{

			for (int b = 0; b < square[a].size(); ++b)
			{
				std::string local;
				for (int c = 0; c < sqrt(square.size()); ++c)
				{

					//pakt de verkeerde 1ste
					local += square[a + c][b];
				}
				start.push_back(local);
			}

		}

		/*for (auto element : start)
		{
			std::cout << element << "/";
		}
		std::cout << std::endl;*/
	}

	int answer = 0;
	for (int i = 0; i < start.size(); ++i)
	{
		for (int a = 0; a < start[i].size(); ++a)
		{
			if (start[a][i] == '#')
			{
				answer++;
			}
		}
	}

	return std::to_string(answer);
}

std::string Day21::Task2()
{
	std::ifstream file("../Inputs/Day 21.txt");
	std::string str;

	std::vector<std::vector<std::string>> version1;
	std::vector<std::vector<std::string>> version2;

	while (std::getline(file, str))
	{
		bool v1 = true;
		std::vector<std::string> f1;
		std::vector<std::string> f2;
		std::string local;
		for (int i = 0; i < str.size(); i++)
		{

			if (str[i] == '/' || str[i] == ' ' && local.size() != 0)
			{
				if (v1)
				{
					f1.push_back(local);
				}
				else
				{
					f2.push_back(local);
				}
				local = "";
			}
			if (str[i] == '=')
			{
				v1 = false;
			}

			if (str[i] == '.' || str[i] == '#')
			{
				local += str[i];
			}
			if (i == str.size() - 1)
			{
				f2.push_back(local);
				local = "";
			}
		}
		version1.push_back(f1);
		version2.push_back(f2);

	}

	std::vector<std::string> start;
	start.push_back(".#.");
	start.push_back("..#");
	start.push_back("###");
	std::vector<std::vector<std::string>> square;

	for (int i = 0; i < 5; ++i)
	{

		if ((int)sqrt(start.size() * start[0].size()) % 2 == 0)
		{
			square.clear();
			for (int a = 0; a < start.size(); a += 2)
			{
				for (int b = 0; b < start[a].size(); b += 2)
				{
					std::vector<std::string> devision;
					std::string t;
					t += start[a][b];
					t += start[a][b + 1];
					devision.push_back(t);
					t = "";
					t += start[a + 1][b];
					t += start[a + 1][b + 1];
					devision.push_back(t);
					square.push_back(devision);
				}

			}

		}
		else if ((int)sqrt(start.size() * start[0].size()) % 3 == 0)
		{
			square.clear();
			for (int a = 0; a < start.size(); a += 3)
			{
				for (int b = 0; b < start[a].size(); b += 3)
				{
					std::vector<std::string> devision;
					std::string t;
					t += start[a][b];
					t += start[a][b + 1];
					t += start[a][b + 2];
					devision.push_back(t);
					t = "";
					t += start[a + 1][b];
					t += start[a + 1][b + 1];
					t += start[a + 1][b + 2];
					devision.push_back(t);
					t = "";
					t += start[a + 2][b];
					t += start[a + 2][b + 1];
					t += start[a + 2][b + 2];
					devision.push_back(t);
					t = "";
					square.push_back(devision);
				}
			}
		}

		std::vector<std::vector<std::string>> rotate = square;

		bool goOut = false;
		for (int a = 0; a < rotate.size(); ++a)
		{
			for (int e = 0; e < 2; ++e)
			{
				for (int k = 0; k < 4; ++k)
				{
					for (int b = 0; b < version1.size(); ++b)
					{
						if (rotate[a].size() == version1[b].size())
						{
							if (rotate[a] == version1[b])
							{
								square[a] = version2[b];
								goOut = true;
								break;
							}
						}
						if (goOut) break;
					}
					if (goOut) break;
					Rotate(rotate[a]);
				}
				if (goOut) break;
				std::reverse(rotate[a].begin(), rotate[a].end());
			}
			goOut = false;

		}

		start.clear();

		for (int a = 0; a < square.size(); a += sqrt(square.size()))
		{

			for (int b = 0; b < square[a].size(); ++b)
			{
				std::string local;
				for (int c = 0; c < sqrt(square.size()); ++c)
				{

					//pakt de verkeerde 1ste
					local += square[a + c][b];
				}
				start.push_back(local);
			}

		}

	}

	int answer = 0;
	for (int i = 0; i < start.size(); ++i)
	{
		for (int a = 0; a < start[i].size(); ++a)
		{
			if (start[a][i] == '#')
			{
				answer++;
			}
		}
	}

	return std::to_string(answer);
}


void Day21::Rotate(std::vector<std::string>&rot) 
{
	//same size vector	
	auto r = rot;

	for (int i = 0; i < r.size(); ++i)
	{
		r[i] = "";
	}
	//rotate 90 degrees
	for (int i = 0; i < rot.size(); ++i)
	{
		int index2 = 0;
		for (int a = 0; a < rot[i].size() - 1; a++)
		{
			r[index2] += rot[i][rot[i].size()- 1 - a];
			index2++;
		}
		r[rot[i].size() - 1] += rot[i][0];
	}
	rot = r;
}
