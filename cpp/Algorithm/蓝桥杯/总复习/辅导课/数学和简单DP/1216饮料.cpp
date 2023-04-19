#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

const int Max = 10010;

int n;

int main(){

    std::cin >> n;

    int res = n;

    while (n >= 3)
    {
        res += n / 3;
        n = n / 3 + n % 3;
    }
    std::cout << res << std::endl;

    return 0;
}