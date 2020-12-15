#include "../../max.h"
#include <iostream>
#include <fstream>

using namespace std;

int solveFirstWrongNumber(vector<long long> numbers);
vector<long long> subset(vector<long long> arr, int min, int max);
long long solveEncryptionWeakness(vector<long long> numbers, int invalidNumIndex);

int main()
{
	ifstream fin;
	fin.open("data.txt");
	if (!fin.is_open()) exit(0);

	vector<long long> numbers;
	int firstInvalidIndex;
	long long encryptionWeakness, value;

	while (fin >> value)
	{
		numbers.push_back(value);
	}

	fin.close();

	firstInvalidIndex = solveFirstWrongNumber(numbers);

	cout << "First number with sum of 2 numbers in preamble" << endl << numbers[firstInvalidIndex] << endl;

	encryptionWeakness = solveEncryptionWeakness(numbers, firstInvalidIndex);

	cout << "Encryption weakness" << endl << encryptionWeakness << endl;
}

int solveFirstWrongNumber(vector<long long> numbers)
{
	for (int i = 25; i < (int)numbers.size(); i++)
	{
		vector<long long> past = subset(numbers, i - 25, i);
		vector<long long> sum = sumNum(past, 2, numbers[i]);
		if (sum.size() < 2)
		{
			return i;
		}
	}

	return 0;
}

long long solveEncryptionWeakness(vector<long long> numbers, int invalidNumIndex)
{
	long long invalidNum = numbers[invalidNumIndex];

	long long sum;
	// starting point
	for (int i = 0; i < (int)numbers.size(); i++)
	{
		sum = 0;

		// add to sum until over invalidNum
		int j = i;
		while (sum < invalidNum)
		{
			sum += numbers[j];
			j++;
		}

		if (sum == invalidNum)
		{
			int start = i, end = j;
			int minIndex = start, maxIndex = start;

			// find min/max numbers
			for (int k = start + 1; k < end; k++)
			{
				if (numbers[k] < numbers[minIndex])
				{
					minIndex = k;
				}

				if (numbers[k] > numbers[maxIndex])
				{
					maxIndex = k;
				}
			}

			return numbers[minIndex] + numbers[maxIndex];
		}
	}

	return 0;
}