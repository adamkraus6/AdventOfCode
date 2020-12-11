#include "../../max.h"

using namespace std;

enum Seat {OCCUPIED, EMPTY, FLOOR};

int solveOccupied(vector<vector<Seat>> seats);
int getAdjacentEquals(vector<vector<Seat>> seats, Seat target, int row, int col);

int main(int argc, char** argv)
{
	ifstream fin;
	vector<vector<Seat>> seats;
	string line;
	int occupied;

	if (argc != 2)
	{
		cout << "Usage: 2020day11.exe data" << endl;
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
		vector<Seat> row;

		for (int i = 0; i < line.length(); i++)
		{
			Seat s;
			s = (line.at(i) == 'L') ? EMPTY : FLOOR;
			row.push_back(s);
		}

		seats.push_back(row);
	}

	occupied = solveOccupied(seats);

	cout << "Seats occupied at end" << endl << occupied << endl;
}

int solveOccupied(vector<vector<Seat>> seats)
{
	return 0;
}