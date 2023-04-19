#include <iostream>

/*
样例输入
4 4 3 2 5 10
1 2 3 4
-1 -2 -3 -4
4 0 2 1
-4 -3 -2 -1
样例输出
10
*/
int map[1000][1000]; //地图
int dp[1000][1000];  //dp数组

int n,m; //地图规模
int x,y; //出发坐标
int v,c;//初始血量和血量上限

int main(){

    std::cin >> n >> m >> x >> y >> v >> c;

    //输入地图
    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= m; j++){

            std::cin >> map[i][j];
        }
    }

    //左上角
    for(int i = x; i >= 1 && i <= m; i--){

        for(int j = y; j >=1 && j <= n; j--){

            //出发点的初始血量
            if(i == x && j == y){

                dp[i][j] = v;
            }
            //临界条件,i == x的时候只能是右边的点过来
            else if(i == x){

                //不能超出最大生命值
                dp[i][j] = std::min(c, dp[i][j + 1] + map[i][j]);
            }
            //临界条件,j == y的时候只能是下边的点过来
            else if(j == y){

                dp[i][j] = std::min(c,dp[i + 1][j] + map[i][j]);
            }else{
                
                //可以从下和右的点过来
                dp[i][j] = std::min(c,std::max(dp[i + 1][j], dp[i][j + 1]) + map[i][j]);
            }
            //如果血量<=0,则游戏结束
            if(dp[i][j] <= 0){

                //给一个巨大的负数保证终点<0
                dp[i][j] = -1000000;
            }
        }
    }
    //右上角
    for(int i = x; i >= 1 && i <= n; i--){

        for(int j = y; j >= 1 && j <= m; j++){

            //出发点的初始血量
            if(i == x && j == y){

                dp[i][j] = v;
            }
            //临界条件,i == x的时候只能是左边的点过来
            else if(i == x){

                //不能超出最大生命值
                dp[i][j] = std::min(c, dp[i][j - 1] + map[i][j]);
            }
            //临界条件,j == y的时候只能是下边的点过来
            else if(j == y){

                dp[i][j] = std::min(c,dp[i + 1][j] + map[i][j]);
            }else{
                
                //可以从下和左的点过来
                dp[i][j] = std::min(c,std::max(dp[i + 1][j], dp[i][j - 1]) + map[i][j]);
            }
            //如果血量<=0,则游戏结束
            if(dp[i][j] <= 0){

                //给一个巨大的负数保证终点<0
                dp[i][j] = -1000000;
            }
        }
    }
    //左下角
    for(int i = x; i >= 1 && i <= n; i++){

        for(int j = y; j >= 1 && j <= m; j--){

            //出发点的初始血量
            if(i == x && j == y){

                dp[i][j] = v;
            }
            //临界条件,i == x的时候只能是右边的点过来
            else if(i == x){

                //不能超出最大生命值
                dp[i][j] = std::min(c, dp[i][j + 1] + map[i][j]);
            }
            //临界条件,j == y的时候只能是上边的点过来
            else if(j == y){

                dp[i][j] = std::min(c,dp[i - 1][j] + map[i][j]);
            }else{
                
                //可以从上和右的点过来
                dp[i][j] = std::min(c,std::max(dp[i - 1][j], dp[i][j + 1]) + map[i][j]);
            }
            //如果血量<=0,则游戏结束
            if(dp[i][j] <= 0){

                //给一个巨大的负数保证终点<0
                dp[i][j] = -1000000;
            }
        }
    }
    //右下角
    for(int i = x; i >= 1 && i <= n; i++){

        for(int j = y; j >= 1 && j <= m; j++){

            //出发点的初始血量
            if(i == x && j == y){

                dp[i][j] = v;
            }
            //临界条件,i == x的时候只能是左边的点过来
            else if(i == x){

                //不能超出最大生命值
                dp[i][j] = std::min(c, dp[i][j - 1] + map[i][j]);
            }
            //临界条件,j == y的时候只能是上边的点过来
            else if(j == y){

                dp[i][j] = std::min(c,dp[i - 1][j] + map[i][j]);
            }else{
                
                //可以从上和左的点过来
                dp[i][j] = std::min(c,std::max(dp[i - 1][j], dp[i][j - 1]) + map[i][j]);
            }
            //如果血量<=0,则游戏结束
            if(dp[i][j] <= 0){

                //给一个巨大的负数保证终点<0
                dp[i][j] = -1000000;
            }
        }
    }

    if(std::max(std::max(dp[1][1] , dp[1][m]) ,std::max(dp[n][1], dp[n][m])) <= 0){

        std::cout << "game over" << std::endl;
    }else{

        int ans = std::max(std::max(dp[1][1], dp[1][m]), std::max(dp[n][1], dp[n][m]));
        std::cout << ans << std::endl;
    }

    return 0;
}