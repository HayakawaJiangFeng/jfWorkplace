#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

const int Max = 410;

int map[Max][Max];
int next[8][2] = {{1,2},{-1,-2},{-1,2},{1,-2},{2,1},{-2,-1},{-2,1},{2,-1}};
int n,m,sx,sy,fx,fy;
bool st[Max][Max];

bool in(int x, int y)
{
    return x > 0 && x <= n && y > 0 && y <= m;
}
void dfs(int x,int y,int cnt)
{
    if(x == fx && y == fy)
    {
        map[x][y] = std::min(map[x][y],cnt);
        return;
    }

    for(int i = 0; i < 8; i++)
    {
        int xx = x + next[i][0];
        int yy = y + next[i][1];

        if(!st[xx][yy] && in(xx, yy))
        {
            st[x][y] = true;
            dfs(xx,yy,cnt + 1);
            st[x][y] = false;
        }
    }   
}
int main()
{
    std::cin >> n >> m >> sx >> sy;
    
    for(fx = 1; fx <= n; fx++)
    {
        for(fy = 1; fy <= m; fy++)
        {
            map[fx][fy] = 999999;
            dfs(sx,sy,0);
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(map[i][j] == 999999)
            {
                map[i][j] = -1;
            }
            std::cout << map[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}