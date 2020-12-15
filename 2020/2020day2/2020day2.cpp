#include "../../max.h"
#include <fstream>
#include <iostream>

using namespace std;

int solveOccValid(vector<string> passwords);
int solvePosValid(vector<string> passwords);

int main()
{
	ifstream fin;
	fin.open("data.txt");
	if (!fin.is_open()) exit(0);

	vector<string> passwords;
	string line;

	while (getline(fin, line))
	{
		passwords.push_back(line);
	}

	fin.close();

	cout << "Valid passwords based on letter occurences: " << endl << solveOccValid(passwords) << endl;

	cout << "Valid passwords based on letter positions: " << endl  << solvePosValid(passwords) << endl;
}

int solveOccValid(vector<string> passwords)
{
	int valid = 0;

	for (int i = 0; i < (int)passwords.size(); i++)
	{
		vector<string> parts = split(passwords[i], ' ');
		vector<string> limits = split(parts[0], '-');
		int min = stoi(limits[0]), max = stoi(limits[1]);
		char target = parts[1].at(0);

		int occ = 0;
		for (int j = 0; j < parts[2].length(); j++)
		{
			if (parts[2].at(j) == target) occ++;
		}
		if (inBetween(occ, min, max, true)) valid++;
	}

	return valid;
}

int solvePosValid(vector<string> passwords)
{
	int valid = 0;

	for (int i = 0; i < (int)passwords.size(); i++)
	{
		vector<string> parts = split(passwords[i], ' ');
		vector<string> limits = split(parts[0], '-');
		int first = stoi(limits[0]), second = stoi(limits[1]);
		char target = parts[1].at(0);

		if ((parts[2].at(first - 1) == target && parts[2].at(second- 1) != target)
			|| (parts[2].at(first - 1) != target && parts[2].at(second - 1) == target))
		{
			valid++;
		}
	}

	return valid;
}