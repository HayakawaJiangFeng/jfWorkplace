#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

const int Max = 1e5 + 10;

int values[Max];
int my_cache[Max];

int main()
{
    int n,k;
    std::cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        std::cin >> values[i];
        my_cache[i] += my_cache[i - 1] + values[i];
    }
    for(int i = 1; i <= k; i++)
    {
        int x,y;
        std::cin >> x >> y;

        std::cout << my_cache[y] - my_cache[x - 1] << std::endl;
    }
}