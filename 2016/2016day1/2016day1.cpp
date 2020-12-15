#include "../../max.h"
#include <fstream>
#include <iostream>

using namespace std;

int blocksAway(vector<string> moves, bool part2 = false);

int main()
{
	ifstream fin;
	fin.open("data.txt");
	if (!fin.is_open()) exit(0);

	string line;
	getline(fin, line);

	fin.close();

	vector<string> moves = split(line, ',');
	for (int i = 0; i < (int)moves.size(); i++)
	{
		sTrim(moves[i]);
	}

	cout << "Blocks away after moving" << endl << blocksAway(moves) << endl;

	cout << "Blocks away from first position visited twice" << endl << blocksAway(moves, true) << endl;
}

int blocksAway(vector<string> moves, bool part2)
{
	int x = 0, y = 0, heading = 1;
	vector<pair<int, int>> visited;

	for (int i = 0; i < (int)moves.size(); i++)
	{
		int value = stoi(moves[i].substr(1));
		if (moves[i][0] == 'L')
		{
			heading++;
		}
		else {
			heading--;
		}
		while (heading < 0) heading += 4;
		while (heading >= 4) heading -= 4;

		for (int j = 0; j < value; j++)
		{
			switch (heading)
			{
			case 0:
				x += 1;
				break;
			case 1:
				y += 1;
				break;
			case 2:
				x -= 1;
				break;
			case 3:
				y -= 1;
				break;
			}

			if (part2)
			{
				for (int j = 0; j < (int)visited.size(); j++)
				{
					pair<int, int> past = visited[j];

					if (past.first == x && past.second == y)
					{
						return abs(x) + abs(y);
					}
				}
			}

			pair<int, int> loc(x, y);

			visited.push_back(loc);
		}
	}

	return abs(x) + abs(y);
}