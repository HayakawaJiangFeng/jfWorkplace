#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

const int Max = 1e5 + 10;

int values[Max];
int N;

int main(){

    long long  cnt = -1e18;
    int res = 0;
    std::cin >> N;
    
    for(int i = 1; i <= N; i++) scanf("%d", &values[i]);

    for(int l = 1, i = 1; i <= N; i *= 2,l++)
    {
        long long sum = 0;
        for(int j = i; j < i + (1 << (l - 1)) && j <= N; j++)
        {
            sum += values[j];
        }
        if(sum > cnt)
        {
            cnt = sum;
            res = l;
        }
    }

    std::cout << res << std::endl;

    return 0;
}