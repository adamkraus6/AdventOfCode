#include "../../max.h"
#include <fstream>
#include <iostream>

using namespace std;

int solveNecessary(vector<string> presents, bool part2 = false);

int main()
{
	ifstream fin;
	fin.open("data.txt");
	if (!fin.is_open()) exit(0);

	vector<string> presents;
	for (string line; getline(fin, line);)
	{
		presents.push_back(line);
	}

	cout << "Total square feet of wrapping paper needed" << endl << solveNecessary(presents) << endl;

	cout << "Total feet of ribbon needed" << endl << solveNecessary(presents, true) << endl;
}

int solveNecessary(vector<string> presents, bool part2)
{
	int sum = 0;

	for (int i = 0; i < (int)presents.size(); i++)
	{
		vector<string> dimensions = split(presents[i], 'x');
		int w = stoi(dimensions[0]), l = stoi(dimensions[1]), h = stoi(dimensions[2]);
		
		if (part2)
		{
			int w1 = 2 * (w + h), w2 = 2 * (w + l), w3 = 2 * (l + h);

			sum += min(min(w1, w2), w3) + (w * h * l);
		}
		else {
			int s1 = w * h, s2 = w * l, s3 = l * h;

			sum += 2 * s1 + 2 * s2 + 2 * s3 + min(min(s1, s2), s3);
		}
	}

	return sum;
}