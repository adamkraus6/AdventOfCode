#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int solveFuel(vector<int>& modules);
int solveMoreFuel(vector<int>& modules);

int main(int argc, char** argv)
{
	ifstream fin;
	vector<int> modules;
	string line;
	int fuel, moreFuel;

	if (argc != 2)
	{
		cout << "Usage: 2019day1.exe data" << endl;
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
		modules.push_back(stoi(line));
	}

	fuel = solveFuel(modules);

	cout << "Fuel required for modules" << endl << fuel << endl;

	moreFuel = solveMoreFuel(modules);

	cout << "Fuel required for fuel for modules" << endl << moreFuel << endl;
}

int solveFuel(vector<int>& modules)
{
	int sum = 0;

	for (int i = 0; i < (int)modules.size(); i++)
	{
		sum += (int)floor(modules[i] / 3) - 2;
	}

	return sum;
}

int solveMoreFuel(vector<int>& modules)
{
	int sum = 0;

	for (int i = 0; i < (int)modules.size(); i++)
	{
		int num = modules[i];
		int fuel = (int)floor(num / 3) - 2;
		sum += fuel;

		while (fuel > 0)
		{
			fuel = (int)floor(fuel / 3) - 2;

			if (fuel > 0)
			{
				sum += fuel;
			}
		}
	}

	return sum;
}