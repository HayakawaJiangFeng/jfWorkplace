#include <iostream>
#include <queue>
#include <cstring>

int n,m;
int res;
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
int distance[25][25];
char map[25][25];
std::queue<std::pair<int, int> > q;

bool in(int xx, int yy){

    return xx > 0 && xx <= n && yy > 0 && yy <= m;
}
void bfs(int x, int y){

    memset(distance, -1, sizeof(distance));
    distance[x][y] = 1;
    q.push(std::make_pair(x,y));
    res++;

    while (q.size())
    {
        
        std::pair<int, int> temp = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){

            int xx = temp.first + next[i][0];
            int yy = temp.second + next[i][1];

            if(in(xx,yy) && map[xx][yy] != '#' && distance[xx][yy] < 0){

                res++;
                distance[xx][yy] = distance[temp.first][temp.second] + 1;
                q.push(std::make_pair(xx,yy));
            }
        }
    }
}
int main(){

    std::cin >> m >> n;

    int sx, sy;
    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= m; j++){

            std::cin >> map[i][j];

            if(map[i][j] == '@'){

                sx = i;
                sy = j;
            }
        }
    }

    bfs(sx,sy);

    std::cout << res << std::endl;

    return 0;
}