#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

const int Max = 1010;

int N,V;
int v[Max];
int w[Max];
int f[Max][Max];

int main(){

    std::cin >> N >> V;

    for(int i = 1; i <= N; i++){

        std::cin >> v[i] >> w[i];
    }

    for(int i = 1; i <= N; i++){

        for(int j = 1; j <= V; j++){

            f[i][j] = f[i - 1][j];
            if(j >= v[i]){

                f[i][j] = std::max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);
            }
        }
    }
    std::cout << f[N][V] << std::endl;

    return 0;
}