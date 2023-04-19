#include <iostream>

int n;
int map[1005][1005];
int memory[1005][1005];
int f[1005][1005];
int f1[1005];

int dfs(int x, int y){

    int temp = 0;
    if(memory[x][y]){

        return memory[x][y];
    }
    if(x > n || y > n){

        return 0;
    }
    temp = std::max(dfs(x + 1, y), dfs(x + 1, y + 1)) + map[x][y];
    memory[x][y] = temp;
    return temp;
}
int main(){

    std::cin >> n;
    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= i; j++){

            std::cin >> map[i][j];
        }
    }

    std::cout << dfs(1,1) << std::endl;

    /*
    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= i; j++){

            std::cout << map[i][j];
        }
        std::cout << std::endl;
    }
    */

    //递推

    for(int i = n; i >= 1; i--){

        for(int j = 1; j <= i; j++){

            f[i][j] = std::max(f[i + 1][j], f[i + 1][j + 1]) + map[i][j];           
        }
    }
    std::cout << f[1][1] << std::endl;

    for(int i = n; i >= 1; i--){

        for(int j = 1; j <= i; j++){

            f1[j] = std::max(f1[j],f1[j + 1]) + map[i][j];
        }
    }
    std::cout << f1[1] << std::endl;
    return 0;
}