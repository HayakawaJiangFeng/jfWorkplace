/*
题目描述

给定一个 
N
×
M
N×M 方格的迷宫，迷宫里有 
T
T 处障碍，障碍处不可通过。

在迷宫中移动有上下左右四种方式，每次只能移动一个方格。数据保证起点上没有障碍。

给定起点坐标和终点坐标，每个方格最多经过一次，问有多少种从起点坐标到终点坐标的方案。

输入格式

第一行为三个正整数 
N
,
M
,
T
N,M,T，分别表示迷宫的长宽和障碍总数。

第二行为四个正整数 
S
X
,
S
Y
,
F
X
,
F
Y
SX,SY,FX,FY，
S
X
,
S
Y
SX,SY 代表起点坐标，
F
X
,
F
Y
FX,FY 代表终点坐标。

接下来 
T
T 行，每行两个正整数，表示障碍点的坐标。

输出格式

输出从起点坐标到终点坐标的方案总数。
*/

#include <iostream>

int N,M,T;
int SX,SY,FX,FY;
int map[7][7];
int res;
bool st[7][7];
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};


void dfs(int x, int y){

    if(x == FX && y == FY){

        res++;
        return;
    }else{

        for(int i = 0; i < 4; i++){

            int tx = x + next[i][0];
            int ty = y + next[i][1];

            if(!st[tx][ty] && map[tx][ty] == 1){

                st[x][y] = true;
                dfs(tx,ty);
                st[x][y] = false;
            }
        }
    }
}

int main(){

    std::cin >> N >> M >> T;

    for(int i = 1; i <= N; i++){

        for(int j = 1; j <= M; j++){

            map[i][j] = 1;
        }
    }
    std::cin >> SX >> SY >> FX >> FY;

    for(int i = 1; i <= T; i++){

        int x, y;
        std::cin >> x >> y;
        map[x][y] = 0;
    }
    
    dfs(SX, SY);
    
    std::cout << res << std::endl;

    return 0;
}