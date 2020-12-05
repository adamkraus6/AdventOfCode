#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

long long treesEncountered(vector<string>& layers, int right, int down);

int main(int argc, char** argv)
{
	ifstream fin;
	vector<string> layers;
	int encountered;
	long long slopeProduct;
	string line;

	if (argc != 2)
	{
		cout << "Usage: 2020day3.exe data" << endl;
		exit(0);
	}

	fin.open(argv[1]);
	if (!fin.is_open())
	{
		cout << "Unable to open file: " << argv[1] << endl;
		exit(0);
	}

	while (getline(fin, line))
	{
		layers.push_back(line);
	}

	encountered = treesEncountered(layers, 3, 1);

	cout << "Trees encountered: " << endl << encountered << endl;

	slopeProduct = treesEncountered(layers, 1, 1) * treesEncountered(layers, 3, 1) * treesEncountered(layers, 5, 1) * treesEncountered(layers, 7, 1) *
		treesEncountered(layers, 1, 2);

	cout << "Product of slopes: " << endl << slopeProduct << endl;
}

long long treesEncountered(vector<string>& layers, int right, int down)
{
	int encountered = 0, pos = 0, posToCheck, length = layers[0].length();

	for (int i = 0; i < (int)layers.size() - down; i += down)
	{
		posToCheck = (pos + right) % length;

		if (layers[i + down].at(posToCheck) == '#')
		{
			encountered++;
		}

		pos += right;
	}

	return encountered;
}