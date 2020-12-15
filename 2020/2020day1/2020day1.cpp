#include "../../max.h"
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	ifstream fin;
	fin.open("data.txt");
	if (!fin.is_open()) exit(0);

	vector<int> numbers;
	int num;

	while (fin >> num)
	{
		numbers.push_back(num);
	}

	fin.close();

	sort(numbers.begin(), numbers.end());

	vector<int> two = sumNum(numbers, 2, 2020);

	cout << "Product based on 2 numbers summing to 2020: " << endl << accumulate(two.begin(), two.end(), 1, std::multiplies<int>()) << endl;

	vector<int> three = sumNum(numbers, 3, 2020);

	cout << "Product based on 3 numbers summing to 2020: " << endl << accumulate(three.begin(), three.end(), 1, std::multiplies<int>()) << endl;
}