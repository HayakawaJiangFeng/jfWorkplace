/*
题目描述

一矩形阵列由数字 
0
0 到 
9
9 组成，数字 
1
1 到 
9
9 代表细胞，细胞的定义为沿细胞数字上下左右若还是细胞数字则为同一细胞，求给定矩形阵列的细胞个数。

输入格式

第一行两个整数代表矩阵大小 
n
n 和 
m
m。

接下来 
n
n 行，每行一个长度为 
m
m 的只含字符 0 到 9 的字符串，代表这个 
n
×
m
n×m 的矩阵。

输出格式

一行一个整数代表细胞个数。
*/

/*
4 10
0234500067
1034560500
2045600671
0000000089
*/

#include <iostream>

int n,m;
char map[105][105];
bool visit[105][105];
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
int res;

bool in(int x, int y){

    return x > 0 && x <= n && y > 0 && y <= m;
}

void dfs(int x, int y){

    visit[x][y] = true;
    for(int i = 0; i < 4; i++){

        int xx = x + next[i][0];
        int yy = y + next[i][1];
        
        if(in(xx,yy) && !visit[xx][yy] && map[xx][yy] != '0'){

            dfs(xx, yy);
        }
    }
}
int main(){

    std::cin >> n >> m;
    for(int i = 1; i <= n; i++){

        for(int j = 1; j <=m; j++){

            std::cin >> map[i][j];
        }
    }
    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= m; j++){

            if(!visit[i][j] && map[i][j] != '0'){

                dfs(i,j);
                res++;
            }
        }
    }
    std::cout << res << std::endl;
    return 0;
}