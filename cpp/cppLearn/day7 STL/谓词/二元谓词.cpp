#include <ctime>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>

class MyCompare
{
public : 

    bool operator()(int val1, int val2) const
    {
        return val1 > val2;
    }
};

int main()
{
    std::vector<int> v;

    std::srand(time(nullptr));

    for(int i = 1; i < 10; i++)
    {
        v.push_back(std::rand() % 100);
    }

    std::sort(v.begin(),v.end());

    for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        std::cout << (*it) << " ";
    }

    std::cout << std::endl;

    std::sort(v.begin(),v.end(),MyCompare());

    for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        std::cout << (*it) << " ";
    }

    return 0;
}