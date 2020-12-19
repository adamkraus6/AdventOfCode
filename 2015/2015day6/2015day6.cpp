#include "../../max.h"
#include <fstream>
#include <iostream>

using namespace std;

int lightsLit(vector<string> instructions);
int lightsBrightness(vector<string> instructions);

int main()
{
	ifstream fin;
	fin.open("data.txt");
	if (!fin.is_open()) exit(0);

	vector<string> instructions;
	for (string line; getline(fin, line);)
	{
		instructions.push_back(line);
	}
	fin.close();

	cout << "Lights lit at end" << endl << lightsLit(instructions) << endl;

	cout << "Lights accumulated brightness at end" << endl << lightsBrightness(instructions) << endl;
}

int lightsLit(vector<string> instructions)
{
	bool lights[1000][1000] = { false };

	for (string ins : instructions)
	{
		vector<string> parts = split(ins, ' ');
		vector<string> from, to;

		if (parts[0] == "toggle")
		{
			// toggle 322,558 through 977,958
			from = split(parts[1], ',');
			int fromCol = stoi(from[0]), fromRow = stoi(from[1]);
			to = split(parts[3], ',');
			int toCol = stoi(to[0]), toRow = stoi(to[1]);

			// row
			for (int i = fromRow; i <= toRow; i++)
			{
				// column
				for (int j = fromCol; j <= toCol; j++)
				{
					lights[i][j] = !lights[i][j];
				}
			}
		}
		else {
			// turn off 660,55 through 986,197
			from = split(parts[2], ',');
			int fromCol = stoi(from[0]), fromRow = stoi(from[1]);
			to = split(parts[4], ',');
			int toCol = stoi(to[0]), toRow = stoi(to[1]);

			bool l = (parts[1] == "on") ? true : false;

			// row
			for (int i = fromRow; i <= toRow; i++)
			{
				// column
				for (int j = fromCol; j <= toCol; j++)
				{
					lights[i][j] = l;
				}
			}
		}
	}

	int lit = 0;

	// row
	for (int i = 0; i < 1000; i++)
	{
		// column
		for (int j = 0; j < 1000; j++)
		{
			if (lights[i][j])
			{
				lit++;
			}
		}
	}

	return lit;
}

int lightsBrightness(vector<string> instructions)
{
	int lights[1000][1000] = { 0 };


	for (string ins : instructions)
	{
		vector<string> parts = split(ins, ' ');
		vector<string> from, to;
		int fromCol, toCol, fromRow, toRow, add;

		if (parts[0] == "toggle")
		{
			// toggle 322,558 through 977,958
			from = split(parts[1], ',');
			fromCol = stoi(from[0]);
			fromRow = stoi(from[1]);

			to = split(parts[3], ',');
			toCol = stoi(to[0]);
			toRow = stoi(to[1]);

			add = 2;
		}
		else {
			// turn off 660,55 through 986,197
			from = split(parts[2], ',');
			fromCol = stoi(from[0]);
			fromRow = stoi(from[1]);

			to = split(parts[4], ',');
			toCol = stoi(to[0]);
			toRow = stoi(to[1]);

			add = (parts[1] == "on") ? 1 : -1;
		}

		// row
		for (int i = fromRow; i <= toRow; i++)
		{
			// column
			for (int j = fromCol; j <= toCol; j++)
			{
				int next = lights[i][j] + add;
				lights[i][j] = (next < 0) ? 0 : next;
			}
		}
	}

	int brightness = 0;

	// row
	for (int i = 0; i < 1000; i++)
	{
		// column
		for (int j = 0; j < 1000; j++)
		{
			brightness += lights[i][j];
		}
	}

	return brightness;
}