#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

const int Max = 10;

int res;
int n,m,t;
int sx,sy,fx,fy;
int map[Max][Max];
int next[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
bool st[Max][Max];


bool in(int xx, int yy)
{
    return xx > 0 && xx <= n && yy > 0 && yy <= m;
}
void dfs(int sx, int sy)
{
    if(sx == fx && sy == fy)
    {
        res++;
        return;
    }

    for(int i = 0; i < 4; i++)
    {
        int xx = sx + next[i][0];
        int yy = sy + next[i][1];

        if(in(xx,yy) && map[xx][yy] != 1 && !st[xx][yy])
        {
            st[sx][sy] = true;
            dfs(xx, yy);
            st[sx][sy] = false;
        }
    }
}
int main()
{
    std::cin >> n >> m >> t;
    std::cin >> sx >> sy >> fx >> fy;

    for(int i = 0; i < t; i++)
    {
        int tx,ty;
        std::cin >> tx >> ty;
        map[tx][ty] = 1;
    }

    dfs(sx,sy);
    
    std::cout << res << std::endl;

    return 0;
}