#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

const int Max = 100010;

int N,K;
long long values[Max];
long long my_cache[Max];
long long cnt[Max];
long long res;

int main(){

    std::cin >> N >> K;
    for(int i = 1; i <= N; i++){

        std::cin >> values[i];
        my_cache[i] = my_cache[i - 1] + values[i];
    }

    for(int i = 1; i <= N; i++){

        res += cnt[my_cache[i] % K];
        cnt[my_cache[i] % K]++;
    }

    long long resF = res + cnt[0];
    std::cout << resF << std::endl;

    return 0;
}