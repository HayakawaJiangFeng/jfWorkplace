#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

const int Max = 1e5 + 10;

int values[Max];

int main()
{
    int N;
    std::cin >> N;
    int res = 0;

    for(int i = 0; i < N; i++)
    {
        std::cin >> values[i];
    }
    
    for(int i = 0,j = 1; j < N; i++,j++)
    {
        if(values[j] < values[i]) continue;
        else res += values[j] - values[i];
    }
    std::cout << res << std::endl;

    return 0;
}