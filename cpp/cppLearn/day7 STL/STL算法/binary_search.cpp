#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    std::vector<int> v;

    for(int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    bool flag = std::binary_search(v.begin(), v.end(), 9);

    if(flag)
    {
        std::cout << "find it" << std::endl;
    }
    else
    {
        std::cout << "cant find it" << std::endl;
    }

    return 0;
}