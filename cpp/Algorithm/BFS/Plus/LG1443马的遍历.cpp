#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <cmath>

const int Max = 410;

int n,m,sx,sy;
int dist[Max][Max];
int next[8][2] = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
std::queue<std::pair<int, int> > q;

bool in(int x, int y)
{
    return x > 0 && x <= n && y > 0 && y <= m;
}
void bfs(int sx, int sy)
{
    memset(dist, -1, sizeof(dist));
    q.push(std::make_pair(sx,sy));
    dist[sx][sy] = 0;

    while (q.size())
    {
        std::pair<int, int> temp = q.front();
        q.pop();

        for(int i = 0; i < 8; i++)
        {
            int xx = temp.first + next[i][0];
            int yy = temp.second + next[i][1];

            if(in(xx,yy) && dist[xx][yy] < 0)
            {
                dist[xx][yy] = dist[temp.first][temp.second] + 1;
                q.push(std::make_pair(xx,yy));
            }
        }
    }
    
}
int main()
{
    std::cin >> n >> m >> sx >> sy;

    bfs(sx,sy);

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            std::cout << dist[i][j] << " "; 
        }
        std::cout << std::endl;
    }

    return 0;
}