#include <iostream>

int a[100][100];
int dp[100][100];

/*
3 3
0 3 4
6 2 5
5 4 3
12
*/
int main(){

    int n = 0,m = 0;
    std::cin >> n >> m;

    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= m; j++){

            std::cin >> a[i][j];
        }
    }

    dp[1][1] = 0;

    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= m; j++){

            if(i == 1 && j == 1){

                continue;
            }
            //临界关系，当i == 1的时候只能从左边的点过来
            else if(i == 1){

                dp[i][j] = dp[i][j - 1] + a[i][j];
            }
            //临界关系，当j == 1的时候只能从下边的点过来
            else if(j == 1){

                dp[i][j] = dp[i - 1][j] + a[i][j];
            }
            else{
                
                //左下都可以
                dp[i][j] = std::min(dp[i][j - 1], dp[i - 1][j]) + a[i][j];
            }
        }
    }

    std::cout << dp[n][m] << std::endl;
    return 0;
}