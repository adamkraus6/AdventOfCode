#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int solve2(vector<int>& numbers);
int solve3(vector<int>& numbers);

int main(int argc, char** argv)
{
	ifstream fin;
	vector<int> numbers;
	int num, answer1, answer2;

	if (argc != 2)
	{
		cout << "Usage: 2020day1.exe data" << endl;
		exit(0);
	}

	fin.open(argv[1]);
	if (!fin.is_open())
	{
		cout << "Unable to open file " << argv[1] << endl;
		exit(0);
	}

	while (fin >> num)
	{
		numbers.push_back(num);
	}

	answer1 = solve2(numbers);

	cout << answer1 << endl;

	answer2 = solve3(numbers);

	cout << answer2 << endl;
}

int solve2(vector<int>& numbers)
{
	for (int i = 0; i < numbers.size(); i++)
	{
		for (int j = 0; j < numbers.size(); j++)
		{
			if (i != j && numbers[i] + numbers[j] == 2020)
			{
				return numbers[i] * numbers[j];
			}
		}
	}

	return 0;
}

int solve3(vector<int>& numbers)
{
	for (int i = 0; i < numbers.size(); i++)
	{
		for (int j = 0; j < numbers.size(); j++)
		{
			for (int k = 0; k < numbers.size(); k++)
			{
				if (i != j != k && numbers[i] + numbers[j] + numbers[k] == 2020)
				{
					return numbers[i] * numbers[j] * numbers[k];
				}
			}
		}
	}

	return 0;
}