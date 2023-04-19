#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

int n,m;

int main(){

    std::cin >> n >> m;

    std::cout << (n - 1) * (m - 1) - 1 << std::endl;

    return 0;
}