#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int Max = 100010;

int values[Max];
int my_cache[Max];
int N,K;
int res;

int main(){

    std::cin >> N >> K;

    for(int i = 1; i <= N; i++){

        std::cin >> values[i];

        my_cache[i] = my_cache[i - 1] + values[i];
    }

    for(int l = 1; l <= N; l++){

        for(int r = N; r >= l; r--){

            if((my_cache[r] - my_cache[l - 1]) % K == 0){

                res++;
            }
        }
    }

    std::cout << res << std::endl;

    return 0;
}