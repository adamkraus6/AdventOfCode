#include "../../max.h"

using namespace std;

int solveManhattanDist(vector<string> actions);

int main(int argc, char** argv)
{
	ifstream fin;
	vector<string> actions;
	string line;
	int manhattanDist;

	if (argc != 2)
	{
		cout << "Usage: 2020day12.exe data" << endl;
		exit(0);
	}

	fin.open(argv[1]);
	if (!fin.is_open())
	{
		cout << "Unable to open file " << argv[1] << endl;
		exit(0);
	}

	while (getline(fin, line))
	{
		actions.push_back(line);
	}

	manhattanDist = solveManhattanDist(actions);

	cout << "Manhattan distance after actions" << endl << manhattanDist << endl;
}

int solveManhattanDist(vector<string> actions)
{
	int x = 0, y = 0, heading = 0;

	for (int i = 0; i < (int)actions.size(); i++)
	{
		char c = actions[i].at(0);
		int amount = stoi(actions[i].substr(1));

		switch (c)
		{
		case 'N':
			y += amount;
			break;
		case 'S':
			y -= amount;
			break;
		case 'E':
			x += amount;
			break;
		case 'W':
			y += amount;
			break;
		case 'L':
			heading += amount;
			while (heading >= 360)
			{
				heading -= 360;
			}
			break;
		case 'R':
			heading -= amount;
			while (heading < 0)
			{
				heading += 360;
			}
			break;
		case 'F':
			switch (heading)
			{
			case 0:
				x += amount;
				break;
			case 90:
				y += amount;
				break;
			case 180:
				x -= amount;
				break;
			case 270:
				y -= amount;
				break;
			}
			break;
		}
	}

	return abs(x) + abs(y);
}

int solveWaypointManhattanDist(vector<string> actions)
{
	return 0;
}