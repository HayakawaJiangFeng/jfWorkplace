#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

const int Max = 50;

int n;
int fibonacci[Max];

int main()
{
    std::cin >> n;

    fibonacci[0] = 0;
    fibonacci[1] = 1;
    
    for(int i = 2; i <= Max; i++)
    {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }

    for(int i = 0; i < n; i++)
    {
        std::cout << fibonacci[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
