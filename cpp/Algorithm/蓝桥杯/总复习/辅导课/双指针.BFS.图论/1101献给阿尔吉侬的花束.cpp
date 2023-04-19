#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstdio>

const int Max = 210;

int T;
int R,C;
int fx,fy;
int dist[Max][Max];
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
char map[Max][Max];
std::queue<std::pair<int, int> > q;

bool in(int xx, int yy){
    
    return xx > 0 && xx <= R && yy > 0 && yy <= C;
}
int bfs(int sx, int sy){

    memset(dist, -1, sizeof(dist));
    q.push(std::make_pair(sx, sy));
    dist[sx][sy] = 0;

    while (q.size())
    {
        std::pair<int, int> temp = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int xx = temp.first + next[i][0];
            int yy = temp.second + next[i][1];
            
            if(in(xx,yy) && dist[xx][yy] < 0 && map[xx][yy] != '#')
            {
                dist[xx][yy] = dist[temp.first][temp.second] + 1;
                q.push(std::make_pair(xx,yy));

                if(xx == fx && yy == fy) return dist[fx][fy];
            }
        }
    }
    return dist[fx][fy];
}
int main(){

    std::cin >> T;
    for(int i = 0; i < T; i++){

        std::cin >> R >> C;

        for(int i = 1; i <= R; i++){

            for(int j = 1; j <= C; j++){

                std::cin >> map[i][j];
            }
        }

        int sx,sy;

        for(int i = 1; i <= R; i++)
        {
            for(int j = 1; j <= C; j++)
            {
                if(map[i][j] == 'S') sx = i, sy = j;
                if(map[i][j] == 'E') fx = i, fy = j;
            }
        }

        q = std::queue<std::pair<int, int> >();
        int res = bfs(sx, sy);
        /*
        for(int i = 1; i <= R; i++){
            for(int j = 1; j <= C; j++){
                std::cout << map[i][j] << " ";
            }
            std::cout << std::endl;
        }
        */
        if(res == -1) std::cout << "oop!" << std::endl;
        else std::cout << res << std::endl;
    }
   
    return 0;
}