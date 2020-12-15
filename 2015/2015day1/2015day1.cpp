#include "../../max.h"
#include <fstream>
#include <iostream>

using namespace std;

int finalFloor(string str, bool part2 = false);

int main()
{
	ifstream fin;
	fin.open("data.txt");
	if (!fin.is_open()) exit(0);

	string line;
	fin >> line;

	cout << "Floor after instruction" << endl << finalFloor(line) << endl;

	cout << "Position of first time in basement (Floor -1)" << endl << finalFloor(line, true) << endl;
}

int finalFloor(string str, bool part2)
{
	int floor = 0;

	for (int i = 0; i < str.length(); i++)
	{
		switch (str[i])
		{
		case '(':
			floor++;
			break;
		case ')':
			floor--;
			break;
		}

		if (part2)
		{
			if (floor == -1)
			{
				return i + 1;
			}
		}
	}

	return floor;
}