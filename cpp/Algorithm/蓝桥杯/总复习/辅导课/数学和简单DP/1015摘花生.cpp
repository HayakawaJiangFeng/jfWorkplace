#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

const int Max = 110;

int T;
int map[Max][Max];
int f[Max][Max];

int main(){

    std::cin >> T;

    for(int i = 1; i <= T; i++){

        int x,y;
        std::cin >> x >> y;
        
        for(int i = 1; i <= x; i++){

            for(int j = 1; j <= y; j++){
                
                std::cin >> map[i][j];
            }
        }
        for(int i = 1; i <= x; i++){

            for(int j = 1; j <= y; j++){

                f[i][j] = std::max(f[i - 1][j], f[i][j - 1]) + map[i][j];
            }
        }

        std::cout << f[x][y] << std::endl;
    }

    return 0;
}