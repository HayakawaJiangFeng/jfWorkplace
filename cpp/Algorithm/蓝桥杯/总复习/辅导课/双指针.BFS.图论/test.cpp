#include <cstdio>
#include <iostream>

char map[6][6];

int main(){

    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= 5; j++){
            scanf(" %c",&map[i][j]);
        }
    }
    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= 5; j++){
            std::cout << map[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}