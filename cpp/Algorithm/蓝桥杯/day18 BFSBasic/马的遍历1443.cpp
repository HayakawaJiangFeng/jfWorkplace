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

输入输出样例
*/

#include <iostream>
#include <cstring>
#include <queue>

int n,m,x,y;
int next[8][2] = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
int distance[405][405];
std::queue<std::pair<int, int> > q;
int ii,jj;

bool in(int x, int y){

    return x > 0 && x <= n && y > 0 && y <= m;
}

void bfs(int x, int y){

    memset(distance, -1, sizeof(distance));
    distance[x][y] = 0;
    std::pair<int, int> p(x,y);
    q.push(p);

    while (!q.empty())
    {
        
        std::pair<int, int> temp = q.front();
        q.pop();

        for(int i = 0; i < 8; i++){

            int xx = temp.first + next[i][0];
            int yy = temp.second + next[i][1];

            if(in(xx,yy) && distance[xx][yy] < 0){

                std::pair<int, int> p1(xx,yy);
                q.push(p1);
                distance[xx][yy] = distance[temp.first][temp.second] + 1;
            }
        }
    }
    return;
}
int main(){

    std::cin >> n >> m >> x >> y;

    bfs(x,y);
    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= m; j++){

            std::cout << distance[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}