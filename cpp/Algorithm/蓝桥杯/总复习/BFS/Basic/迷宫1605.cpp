#include <iostream>
#include <queue>
#include <cstring>

int n,m,t,sx,sy,fx,fy;
int res;
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
char map[10][10];
std::queue<std::pair<int, int> > q;
int distance[10][10];

bool in(int x, int y){

    return x > 0 && x <= n && y > 0 && y <= m;
}
void bfs(int x, int y){

    memset(distance, -1, sizeof(distance));
    q.push(std::make_pair(x,y));
    distance[x][y] = 0;

    while (q.size())
    {
        std::pair<int, int> temp = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){

            int xx = temp.first + next[i][0];
            int yy = temp.second + next[i][1];

            if(in(xx,yy) && map[xx][yy] != 'T' && distance[xx][yy] < 0){

                distance[xx][yy] = distance[temp.first][temp.second] + 1;
                if(map[xx][yy] == 'F'){

                    res++;
                }
                q.push(std::make_pair(xx,yy));
            }
        }
    }
    
}
int main(){
    
    std::cin >> n >> m >> t;
    std::cin >> sx >> sy >> fx >> fy;
    
    map[sx][sy] = 'S';
    map[fx][fy] = 'F';

    for(int i = 0; i < t; i++){

        int tx,ty;
        std::cin >> tx >> ty;

        map[tx][ty] = 'T';
    }

    bfs(sx,sy);

    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= m; j++){

            std::cout << distance[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << res << std::endl;

    return 0;
}