#include <vector>
#include <iostream>
#include <algorithm>
#include <random>

int main()
{
    std::vector<int> v;
    for(int i = 1; i <= 10; i++)
    {
        v.push_back(i);
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(v.begin(),v.end(),g);

    for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        std::cout << *it << " ";
    }
    puts("");

    std::sort(v.begin(), v.end());

    for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        std::cout << *it << " ";
    }
    puts("");

    return 0;
}
