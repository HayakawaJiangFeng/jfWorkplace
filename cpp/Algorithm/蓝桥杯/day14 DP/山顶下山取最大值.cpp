#include <iostream>

int value[100][100];
int dp[100][100];

int n;

int main(){

    std::cin >> n;
    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= i; j++){

            std::cin >> value[i][j];
        }
    }
    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= i; j++){

            if(i == 1 && j == 1){

                dp[i][j] = value[i][j];
            }
            else if(j == 1){

                dp[i][j] = dp[i - 1][j] + value[i][j];
            }
            else if(j == i){

                dp[i][j] = dp[i - 1][j - 1] + value[i][j];
            }
            else{

                dp[i][j] = std::max(dp[i - 1][j - 1], dp[i - 1][j]) + value[i][j];
            }
        }
    }
    int max = 0;
    for(int i = 1; i <= n; i++){

        if(dp[n][i] >= max){

            max = dp[n][i];
        }
    }
    std::cout << max << std::endl;
    return 0;
}