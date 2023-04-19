#include <iostream>
#include <queue>

const int Max = 25;

int n,m;
int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
char map[Max][Max];

int bfs(int sx, int sy){

    std::queue<std::pair<int, int> > q;
    q.push(std::make_pair(sx,sy));
    map[sx][sy] = '#';
    int res = 0;

    while (q.size())
    {
        std::pair<int, int> temp = q.front();
        q.pop();
        res++;

        for(int i = 0; i < 4; i++)
        {
            int x = temp.first + dir[i][0];
            int y = temp.second + dir[i][1];

            if(x >= 1 && x <= n && y >= 1 && y <= m && map[x][y] != '#')
            {
                map[x][y] = '#';
                q.push(std::make_pair(x,y));
            }
        }
    }
    return res;
}
int main(){

    while (std::cin >> m >> n, n || m)
    {
        int sx,sy;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                std::cin >> map[i][j];
                if(map[i][j] == '@') sx = i, sy = j;
            }
        }
        int res = bfs(sx,sy);
        std::cout << res << std::endl;
    }
    
    return 0;
}