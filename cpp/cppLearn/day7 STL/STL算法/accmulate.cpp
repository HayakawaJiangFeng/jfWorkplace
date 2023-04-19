#include <vector>
#include <iostream>
#include <numeric>

int main()
{
    std::vector<int> v;

    for(int i = 1; i <= 100; i++)
    {
       v.push_back(i); 
    }
    int sum = std::accumulate(v.begin(), v.end(), 0);
    std::cout << sum << std::endl;

    return 0;
}