#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

const int Max = 10010;

int n;
int values[Max];

int main(){

    std::cin >> n;

    for(int i = 1; i <= n; i++){

        std::cin >> values[i];
    }

    int res = 0;
    for(int i = 1; i <= n; i++){

        int max = -Max;
        int min = Max;

        for(int j = i; j <= n; j++){

            max = std::max(max, values[j]);
            min = std::min(min, values[j]);

            if(max - min == j - i){
                
                res++;
            }
        }
    }
    std::cout << res << std::endl;

    return 0;
}