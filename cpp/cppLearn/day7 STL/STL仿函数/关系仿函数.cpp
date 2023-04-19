#include <ctime>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <functional>

int main()
{
    std::srand(std::time(nullptr));
    std::vector<int> v;

    for(int i = 0; i < 10; i++)
    {
        v.push_back(rand() % 100);
    }
    std::sort(v.begin(),v.end());

    for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        std::cout << (*it) << " ";
    }
    std::cout << std::endl;

    std::sort(v.begin(),v.end(),std::greater<int>());
    for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        std::cout << (*it) << " ";
    }
    std::cout << std::endl;

    return 0;
}