#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

const int Max = 25;

int m,n;
int cnt;
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
char map[25][25];
bool st[25][25];

bool in(int x,int y)
{
    return x > 0 && x <= n && y > 0 && y <= m;
}
void dfs(int sx, int sy)
{
    for(int i = 0; i < 4; i++)
    {
        int xx = sx + next[i][0];
        int yy = sy + next[i][1];
        
        if(!st[xx][yy] && in(xx,yy) && map[xx][yy] != '#')
        {
            st[xx][yy] = true;
            cnt++;
            dfs(xx, yy);
        }
    }
}
int main()
{
    std::cin >> m >> n;
    int sx,sy;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            scanf(" %c",&map[i][j]);
            if(map[i][j] == '@')
            {
                sx = i;
                sy = j;
            }
        }
    }
    cnt++;
    st[sx][sy] = true;
    dfs(sx, sy);

    std::cout << cnt << std::endl;

    return 0;
}