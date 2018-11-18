// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include"pch.h"
#include <iostream>
#include <vector>
#include <string>

void input(std::string& blocks)
{
	
	std::cin >> blocks;
	
}

void calculate(std::vector<int>& blockvector,std::string& blocks,int& maxsize)
{

	for (int i = 0; i < blocks.size(); i++)
	{
		if (blocks[i] == ',')
		{
			continue;
		}
		else
		{
			blockvector.push_back(blocks[i]-48);
			
		}
	}
	for (int i = 0; i < blockvector.size(); i++)
	{
		int j = i;
		int size = 0;
		for ( j; j >= 0; j--)//look to the left
		{
			if (blockvector[j] < blockvector[i])
			{
				break;
			}
			else
			{
				size += blockvector[i];
			}
		}
		j = i;
		for (int p=j+1; p < blockvector.size(); p++)//look to the right
		{
			if (blockvector[p] < blockvector[i])
			{
				break;
			}
			else
			{
				size += blockvector[i];
			}
		}
		if (size > maxsize)//record
		{
			maxsize = size;
		}

		
	}
}
int main()
{
	std::vector<int> blockvector;
	std::string blocks="";
	int maxsize = 0;
    input(blocks);
	calculate(blockvector, blocks, maxsize);
    std:: cout << maxsize;
	
	
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
