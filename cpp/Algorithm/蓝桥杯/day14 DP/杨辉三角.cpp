#include <iostream>

long long F[100][100];

int main(){

    for(int i = 1; i < 100; i++){

        for(int j = 1; j <= i; j++){

            if(j == 1){

                F[i][j] = 1;
            }else{

                F[i][j] = F[i - 1][j - 1] + F[i - 1][j];
            }
        }
    }

    int n,m;
    std::cin >> n >> m;
    std::cout << F[n][m] << std::endl;

    return 0;
}