#include "../../max.h"
#include <fstream>
#include <iostream>

using namespace std;

int solveHousesGivenTo(string directions);
void move(char d, int& x, int& y);
int solveRoboSanta(string directions);

int main()
{
	ifstream fin;
	fin.open("data.txt");
	if (!fin.is_open()) exit(0);

	string line;
	getline(fin, line);
	fin.close();

	cout << "Houses that receive at least one present" << endl << solveHousesGivenTo(line) << endl;

	cout << "Houses that receive at least one present (using RoboSanta)" << endl << solveRoboSanta(line) << endl;
}

int solveHousesGivenTo(string directions)
{
	int houses = 1, x = 0, y = 0;
	vector<pair<int, int>> visited;
	visited.push_back(make_pair(0, 0));

	for (int i = 0; i < (int)directions.length(); i++)
	{
		char m = directions[i];
		move(m, x, y);

		bool v = false;
		for (int j = 0; j < (int)visited.size(); j++)
		{
			pair<int, int> p = visited[j];
			if (p.first == x && p.second == y)
			{
				v = true;
			}
		}
		if (!v)
		{
			houses++;
		}

		visited.push_back(make_pair(x, y));
	}

	return houses;
}

void move(char d, int& x, int& y)
{
	switch (d)
	{
	case '^':
		y++;
		break;
	case '<':
		x--;
		break;
	case '>':
		x++;
		break;
	case 'v':
		y--;
		break;
	}
}

int solveRoboSanta(string directions)
{
	int houses = 1, x = 0, y = 0, rx = 0, ry = 0;
	vector<pair<int, int>> visited;
	visited.push_back(make_pair(0, 0));

	for (int i = 0; i < (int)directions.length(); i+= 2)
	{
		char m = directions[i];
		move(m, x, y);

		bool v = false;
		for (int j = 0; j < (int)visited.size(); j++)
		{
			pair<int, int> p = visited[j];
			if (p.first == x && p.second == y)
			{
				v = true;
			}
		}
		if (!v)
		{
			houses++;
		}

		visited.push_back(make_pair(x, y));

		m = directions[i + 1];
		move(m, rx, ry);

		v = false;
		for (int j = 0; j < (int)visited.size(); j++)
		{
			pair<int, int> p = visited[j];
			if (p.first == rx && p.second == ry)
			{
				v = true;
			}
		}
		if (!v)
		{
			houses++;
		}

		visited.push_back(make_pair(rx, ry));
	}

	return houses;
}