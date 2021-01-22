#include "../../max.h"
#include <iostream>

using namespace std;

int main()
{
	vector<int> numbers;
	int num;

	while (cin >> num)
	{
		numbers.push_back(num);
	}

	sort(numbers.begin(), numbers.end());

	vector<int> two = sumNum(numbers, 2, 2020);

	cout << "Product based on 2 numbers summing to 2020: " << endl << accumulate(two.begin(), two.end(), 1, std::multiplies<int>()) << endl;

	vector<int> three = sumNum(numbers, 3, 2020);

	cout << "Product based on 3 numbers summing to 2020: " << endl << accumulate(three.begin(), three.end(), 1, std::multiplies<int>()) << endl;
}