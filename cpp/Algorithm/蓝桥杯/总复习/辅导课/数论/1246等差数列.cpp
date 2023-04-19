#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

const int Max = 1e5 + 10;

int values[Max];

int gcd(int x, int y)
{
    return y ? gcd(y, x % y) : x;
}
int main()
{
    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++) std::cin >> values[i];
    
    std::sort(values, values + n);

    int d = 0;
    for(int i = 1; i < n; i++)
    {
        d = gcd(d, values[i] - values[0]);
    } 
    if(!d) std::cout << n << std::endl;
    else std::cout << ((values[n - 1] - values[0]) / d + 1) << std::endl;

    return 0;
}