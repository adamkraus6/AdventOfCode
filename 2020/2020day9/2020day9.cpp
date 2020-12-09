#include "../../max.h"

using namespace std;

int solveFirstWrongNumber(vector<long long> numbers);
long long solveEncryptionWeakness(vector<long long> numbers, int invalidNumIndex);

int main(int argc, char** argv)
{
	ifstream fin;
	vector<long long> numbers;
	int firstInvalidIndex;
	long long encryptionWeakness, value;

	if (argc != 2)
	{
		cout << "Usage: 2020day9.exe data" << endl;
		exit(0);
	}

	fin.open(argv[1]);
	if (!fin.is_open())
	{
		cout << "Unable to open file " << argv[1] << endl;
		exit(0);
	}

	while (fin >> value)
	{
		numbers.push_back(value);
	}

	firstInvalidIndex = solveFirstWrongNumber(numbers);

	cout << "First number with sum of 2 numbers in preamble" << endl << numbers[firstInvalidIndex] << endl;

	encryptionWeakness = solveEncryptionWeakness(numbers, firstInvalidIndex);

	cout << "Encryption weakness" << endl << encryptionWeakness << endl;
}

int solveFirstWrongNumber(vector<long long> numbers)
{
	for (int i = 25; i < (int)numbers.size(); i++)
	{
		bool hasSum = false;

		for (int j = i - 25; j < i; j++)
		{
			for (int k = i - 25; k < i; k++)
			{
				if (j != k)
				{
					if (numbers[j] + numbers[k] == numbers[i])
					{
						hasSum = true;
					}
				}
			}
		}

		if (!hasSum)
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