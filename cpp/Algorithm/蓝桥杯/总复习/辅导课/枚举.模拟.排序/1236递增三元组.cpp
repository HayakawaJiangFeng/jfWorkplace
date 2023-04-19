#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

const int Max = 1e5 + 10;

int values[4][Max];
int N;

int main(){

    std::cin >> N;

    for(int i = 1; i <= N; i++){

        for(int j = 1; j <= N; j++){

            std::cin >> values[i][j];
        }
    }

    int res = 0;
    for(int i = 1; i <= N; i++){

        for(int j = 1; j <= N; j++){

            for(int k = 1; k <= N; k++){

                if(values[1][i] < values[2][j] && values[2][j] < values[3][k]){

                    res++;
                }
            }
        }
    }

    std::cout << res << std::endl;

    return 0;
}