#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

long long treesEncountered(vector<string>& layers, int right, int down);

int main()
{
	ifstream fin;
	fin.open("data.txt");
	if (!fin.is_open()) exit(0);

	vector<string> layers;
	long long slopeProduct;
	string line;

	while (getline(fin, line))
	{
		layers.push_back(line);
	}

	fin.close();

	cout << "Trees encountered: " << endl << treesEncountered(layers, 3, 1) << endl;

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