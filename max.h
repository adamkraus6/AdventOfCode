#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <numeric>
#include <functional>
#include <algorithm>

std::vector<std::string> split(const std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream ts(s);
    while (std::getline(ts, token, delimiter)) tokens.push_back(token);
    return tokens;
}

/** ***************************************************************************
 * @author Adam Kraus
 *
 * @par Description:
 * Checks if there are k numbers in arr that add to sum
 *
 * @param[in] arr - array of numbers supplied
 * @param[in] k - amount of numbers that add
 * @param[in] sum - what the k numbers should add to
 * @param[in] n - current layer of recursion
 * @param[in] numbers - current numbers that could add
 * @param[in] used - determines if a number is currently being used to add
 *
 * @returns array of numbers that add to sum if possible
 *
 *****************************************************************************/
std::vector<int> sumNum(std::vector<int> arr, int k, int sum, int n = 0, std::vector<int> numbers = {}, std::vector<bool> used = {})
{
    // check default values
    if(numbers.size() == 0)
    {
        std::vector<int> n;
        for(int i = 0; i < k; i++)
        {
            n.push_back(0);
        }
        numbers = n;
    }
    if(used.size() == 0)
    {
        std::vector<bool> u;
        for (int i = 0; i < (int)arr.size(); i++)
        {
            u.push_back(false);
        }
        used = u;
    }

    // base case
    if(n == k)
    {
        if(accumulate(numbers.begin(), numbers.end(), 0) == sum)
        {
            return numbers;
        } else {
            return {};
        }
    }

    // recurse
    for(int i = 0; i < (int)arr.size(); i++)
    {
        if(!used[i])
        {
            used[i] = true;
            numbers[n] = arr[i];
            std::vector<int> test = sumNum(arr, k, sum, n + 1, numbers, used);
            used[i] = false;
            if(test.size() > 0)
            {
                return test;
            }
        }
    }

    return {};
}

template <typename T, typename A>
bool find(std::vector<T, A> const& arr, T target)
{
    for(int i = 0; i < (int)arr.size(); i++)
    {
        if(arr[i] == target)
        {
            return true;
        }
    }

    return false;
}