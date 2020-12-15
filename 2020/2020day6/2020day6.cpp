#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solveAnswersAny(vector<string>& answers);
int solveAnswersEvery(vector<string>& answers);

int main()
{
	ifstream fin;
	fin.open("data.txt");
	if (!fin.is_open()) exit(0);

	vector<string> answers;
	string line, a;

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

	fin.close();

	answers.push_back(a);

	cout << "Sum of number of questions anyone answered" << endl << solveAnswersAny(answers) << endl;

	cout << "Sum of number of questions everyone answered" << endl << solveAnswersEvery(answers) << endl;
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