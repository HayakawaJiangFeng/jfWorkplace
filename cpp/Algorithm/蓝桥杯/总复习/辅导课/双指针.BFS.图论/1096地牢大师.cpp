#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>

const int Max = 110;

int z,x,y;
int dir[6][3] = {{1,0,0},{0,1,0},{-1,0,0},{0,-1,0},{0,0,1},{0,0,-1}};
int dist[Max][Max][Max];
char map[Max][Max][Max];
int sx,sy,sz;
int fx,fy,fz;

bool in(int xx, int yy, int zz){

    return zz > 0 && zz <= z && xx > 0 && xx <= x && yy > 0 && yy <= y;
}
int bfs(int sx, int sy, int sz){

    memset(dist, -1, sizeof(dist));
    std::queue<std::pair<int, std::pair<int, int> > >q;
    dist[sx][sy][sz] = 0;
    q.push(std::make_pair(sx,std::make_pair(sy,sz)));

    while (q.size())
    {
        std::pair<int, std::pair<int,int> > temp = q.front();
        q.pop();

        for(int i = 0; i < 6; i++)
        {
            int xx = temp.first + dir[i][0];
            int yy = temp.second.first + dir[i][1];
            int zz = temp.second.second + dir[i][2];

            if(in(xx,yy,zz) && map[xx][yy][zz] != '#' && dist[xx][yy][zz] < 0){

                dist[xx][yy][zz] = dist[temp.first][temp.second.first][temp.second.second] + 1;
                q.push(std::make_pair(xx,std::make_pair(yy,zz)));

                if(zz == fz && xx == fx && yy == fy){
                    
                    return dist[xx][yy][zz];
                }
            }
        }
    }
    return dist[fx][fy][fz];
}
int main(){
    
    while (std::cin >> z >> x >> y, z || x || y)
    {
        memset(map, '\0', sizeof(map));
        int sx,sy,sz;

        for(int k = 1; k <= z; k++)
        {
            for(int i = 1; i <= x; i++)
            {
                for(int j = 1; j <= y; j++)
                {
                    std::cin >> map[i][j][k];
                }
            }
        }
        for(int k = 1; k <= z; k++){
            for(int i = 1; i <= x; i++){
                for(int j = 1; j <= y; j++){
                    if(map[i][j][k] == 'S') sx = i, sy = j, sz = k;
                    if(map[i][j][k] == 'E') fx = i, fy = j, fz = k;
                }
            }
        }
        /*
        std::cout << sx << " " << sy << " " << sz << std::endl;
        
        std::cout << fx << " " << fy << " " << fz << std::endl;
        */
        int res = bfs(sx,sy,sz);
        /*
        for(int k = 1; k <= z; k++){
            for(int i = 1; i <= x; i++){
                for(int j = 1; j <= y; j++){
                    std::cout << dist[i][j][k] << " ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
        */
        if(res == -1) std::cout << "Trapped!" << std::endl;
        else std::cout << "Escaped in " << res << " minute(s)." << std::endl;
    }
    return 0;
}