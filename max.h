#include <string>
#include <vector>
#include <sstream>
#include <numeric>
#include <algorithm>

std::vector<std::string> split(const std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream ts(s);
    while (std::getline(ts, token, delimiter)) tokens.push_back(token);
    return tokens;
}

template <typename T, typename A = allocator<T>>
std::vector<T, A> sumNum(std::vector<T, A> arr, int k, T sum, int layer = 0, std::vector<T, A> numbers = {}, std::vector<bool> used = {})
{
    // check default values
    if(numbers.size() == 0)
    {
        std::vector<T, A> n;
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
    if(layer == k)
    {
        if(std::accumulate(numbers.begin(), numbers.end(), (T)0) == sum)
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
            numbers[layer] = arr[i];
            std::vector<T, A> test = sumNum(arr, k, sum, layer + 1, numbers, used);
            used[i] = false;
            if(test.size() > 0)
            {
                return test;
            }
        }
    }

    return {};
}

bool inBetween(int num, int min, int max, bool inclusive)
{
    if (inclusive)
    {
        return min <= num && num <= max;
    }
    else {
        return min < num&& num < max;
    }
}

std::vector<long long> subset(std::vector <long long> arr, int min, int max)
{
    std::vector<long long> sub;

    for (int i = min; i < max; i++)
    {
        sub.push_back(arr[i]);
    }

    return sub;
}

void sTrim(std::string& str)
{
    bool empty = true;
    for (auto it = str.begin(); it != str.end(); it++)
    {
        if (!isspace(*it))
        {
            empty = false;
        }
    }
    if (empty)
    {
        str.clear();
        return;
    }
    if (str.empty()) return;

    for (auto it = str.begin(); it != str.end(); it++)
    {
        if (!isspace(*it))
        {
            str.erase(str.begin(), it);
            break;
        }
    }

    for (auto it = str.end() - 1; it != str.begin(); --it)
    {
        if (!isspace(*it))
        {
            str.erase(it + 1, str.end());
            break;
        }
    }
}