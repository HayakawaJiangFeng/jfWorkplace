#include <iostream>

int n,m,x,y;
int v, c;

int map[100][100];
int dp[100][100];

int main(){

    std::cin >> n >> m >> x >> y >> v >> c;

    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= m; j++){

            std::cin >> map[i][j];
        }
    }

    int xx[4] = {-1,-1,1,1};
    int yy[4] = {-1,1,-1,1};

    for(int k = 0; k < 4; k++){

        for(int i = x; i > 0 && i <= n; i -= xx[k]){

            for(int j = y; j > 0 && j <= m; j -= yy[k]){

                if(i == x && j == y){

                    dp[i][j] = v;                   
                }
                else if(i == x){

                    dp[i][j] = std::min(c,(dp[i][j + yy[k]]) + map[i][j]);
                }
                else if(j == y){

                    dp[i][j] = std::min(c,(dp[i + xx[k]][j]) + map[i][j]);
                }else{

                    dp[i][j] = std::min(c, std::max(dp[i + xx[k]][j], dp[i][j + yy[k]]) + map[i][j]);
                }
                if(dp[i][j] <= 0){

                    dp[i][j] = -1;
                }
            }
        }
    }
    int ans = std::max(std::max(dp[1][1],dp[1][n]), std::max(dp[n][m], dp[n][1]));
    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= m; j++){

            std::cout << dp[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << ans << std::endl;
    return 0;
}