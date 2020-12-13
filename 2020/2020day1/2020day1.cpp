#include "../../max.h"

using namespace std;

int main(int argc, char** argv)
{
	ifstream fin;
	vector<int> numbers;
	int num;

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

	sort(numbers.begin(), numbers.end());

	vector<int> two = sumNum(numbers, 2, 2020);

	cout << "Product based on 2 numbers summing to 2020: " << endl << accumulate(two.begin(), two.end(), 1, std::multiplies<int>()) << endl;

	vector<int> three = sumNum(numbers, 3, 2020);

	cout << "Product based on 3 numbers summing to 2020: " << endl << accumulate(three.begin(), three.end(), 1, std::multiplies<int>()) << endl;
}