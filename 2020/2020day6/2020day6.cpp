#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solveAnswersAny(vector<string>& answers);
int solveAnswersEvery(vector<string>& answers);

int main(int argc, char** argv)
{
	ifstream fin;
	vector<string> answers;
	string line, a;
	int answeredAny, answeredEvery;

	if (argc != 2)
	{
		cout << "Usage: 2020day6.exe data" << endl;
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
		if (line.empty())
		{
			answers.push_back(a);
			a = "";
		}
		else {
			a += line + ' ';
		}
 	}

	answers.push_back(a);

	answeredAny = solveAnswersAny(answers);

	cout << "Sum of number of questions anyone answered" << endl << answeredAny << endl;

	answeredEvery = solveAnswersEvery(answers);

	cout << "Sum of number of questions everyone answered" << endl << answeredEvery << endl;
}

int solveAnswersAny(vector<string>& answers)
{
	int sum = 0;

	for (int i = 0; i < (int)answers.size(); i++)
	{
		unordered_map<char, int> unique;

		for (int j = 0; j < answers[i].length(); j++) {
			unique[answers[i][j]]++;
		}

		unique.erase(' ');

		sum += (int)unique.size();
	}

	return sum;
}

int solveAnswersEvery(vector<string>& answers)
{
	int sum = 0;

	for (int i = 0; i < (int)answers.size(); i++)
	{
		unordered_map<char, int> unique;

		for (int j = 0; j < answers[i].length(); j++) {
			unique[answers[i][j]]++;
		}

		int peopleInGroup = unique[' '];

		unique.erase(' ');

		for (auto it = unique.begin(); it != unique.end(); it++)
		{
			if (it->second == peopleInGroup)
			{
				sum += 1;
			}
		}
	}

	return sum;
}