#include <iostream>

int n, m;
int f[35][35];

int main(){

    std::cin >> n >> m;

    f[0][1] = 1;
    for(int i = 1; i <= m; i++){

        for(int j = 1; j <= n; j++){

            if(j == 1){

                f[i][j] = f[i - 1][2] + f[i - 1][n];
            }
            else if(j == n){

                f[i][j] = f[i - 1][1] + f[i - 1][n - 1];
            }else{

                f[i][j] = f[i - 1][j - 1] + f[i - 1][j + 1];
            }
        }
    }
    std::cout << f[m][1] << std::endl;
    return 0;
}