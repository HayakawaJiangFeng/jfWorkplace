#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

const int Max = 1010;

int N;
int values[Max];
int f[Max];

int main(){

    std::cin >> N;

    for(int i = 1; i <= N; i++){
        
        std::cin >> values[i];
    }

    int res = 0;

    for(int i = 1; i <= N; i++){

        f[i] = 1;
        for(int j = 1; j < i; j++){

            if(values[i] > values[j]){

                f[i] = std::max(f[i], f[j] + 1);
            }
        }
        res = std::max(res, f[i]);
    }

    std::cout << res << std::endl;

    return 0;
}