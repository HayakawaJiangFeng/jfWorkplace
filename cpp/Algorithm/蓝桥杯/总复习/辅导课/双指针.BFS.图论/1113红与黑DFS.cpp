#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>

const int Max = 25;

char map[Max][Max];
int n,m;
int res;
int next[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
bool st[Max][Max];

void dfs(int sx, int sy){

    res++;
    for(int i = 0; i < 4; i++)
    {
        int x = sx + next[i][0];
        int y = sy + next[i][1];

        if(x > 0 && x <= n && y > 0 && y <= m && !st[x][y] && map[x][y] != '#')
        {
            st[x][y] = true;
            dfs(x,y);
        }
    }
}
int main(){

    while (std::cin >> m >> n, n || m)
    {
        int sx, sy;

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                std::cin >> map[i][j];
                if(map[i][j] == '@') sx = i, sy = j;
            }
        }
        memset(st,false,sizeof(st));
        res = 0;
        st[sx][sy] = true;
        dfs(sx,sy);
        std::cout << res << std::endl;
    }
    
    return 0;
}