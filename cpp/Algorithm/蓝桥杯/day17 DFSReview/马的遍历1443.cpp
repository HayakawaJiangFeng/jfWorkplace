/*
题目描述

有一个 
n
×
m
n×m 的棋盘，在某个点 
(
x
,
y
)
(x,y) 上有一个马，要求你计算出马到达棋盘上任意一个点最少要走几步。

输入格式

输入只有一行四个整数，分别为 
n
,
m
,
x
,
y
n,m,x,y。

输出格式

一个 
n
×
m
n×m 的矩阵，代表马到达某个点最少要走几步（不能到达则输出 
−
1
−1）。
*/

#include <iostream>

int n,m,x,y;
int next[8][2] = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
bool st[405][405];
int ans[405][405];
int ii,jj;

bool in(int x, int y){

    return x > 0 && x <= n && y > 0 && y <= m;
}

void dfs(int x, int y,int cnt){

    if(x == ii && y == jj){

        ans[ii][jj] = std::min(ans[ii][jj], cnt);
        return;
    }
    for(int i = 0; i < 8; i++){

        int tx = x + next[i][0];
        int ty = y + next[i][1];

        if(in(tx,ty) && !st[tx][ty]){

            st[x][y] = true;
            dfs(tx, ty, cnt + 1);
            st[x][y] = false;
        }
    }
}

int main(){

    scanf("%d %d %d %d",&n,&m,&x,&y);
    
    for(ii = 1; ii <= n; ii++){

        for(jj = 1; jj <= m; jj++){

            ans[ii][jj] = 1e9;
            dfs(x,y,0);
        }
    }

    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= m; j++){

            if(ans[i][j] == 1e9){

                ans[i][j] = -1;
            }
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}