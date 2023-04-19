#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 50;

int n;
int Fibonacci[N];

int main(){

    Fibonacci[0] = 0;
    Fibonacci[1] = 1;
    Fibonacci[2] = 1;

    std::cin >> n;

    for(int i = 3; i <= n; i++){

        Fibonacci[i] = Fibonacci[i - 1] + Fibonacci[i - 2];
    }

    for(int i = 0; i < n; i++){

        printf("%d ",Fibonacci[i]);
    }
    puts("");

    return 0;
}