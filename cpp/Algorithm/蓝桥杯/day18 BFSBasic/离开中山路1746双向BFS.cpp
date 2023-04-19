#include <iostream>
#include <queue>
#include <cstring>

int n;
int sx,sy,fx,fy;
char map[1005][1005];
int visit[1005][1005];
int distance[1005][1005];
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

std::queue<std::pair<int, int> > q;

bool in(int x, int y){

    return x > 0 && x <= n && y > 0 && y <= n;
}

int bfs(){

    memset(distance, -1, sizeof(distance));
    memset(visit, -1, sizeof(visit));

    distance[sx][sy] = 0;
    distance[fx][fy] = 0;

    q.push(std::make_pair(sx,sy));
    q.push(std::make_pair(fx,fy));

    visit[sx][sy] = 1;
    visit[fx][fy] = 2;

    while (!q.empty())
    {
        std::pair<int, int> temp = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){

            int xx = temp.first + next[i][0];
            int yy = temp.second + next[i][1];

            if(visit[xx][yy] + visit[temp.first][temp.second] == 3){

                return distance[xx][yy] + distance[temp.first][temp.second] + 1;
            }

            if(in(xx,yy) && map[xx][yy] != '1' && distance[xx][yy] < 0){

                if(visit[xx][yy] == -1){

                    visit[xx][yy] = visit[temp.first][temp.second];
                }
                distance[xx][yy] = distance[temp.first][temp.second] + 1;
                q.push(std::make_pair(xx,yy));
            }
        }
    }
    return -1;
}
int main(){

    std::cin >> n;

    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= n; j++){

            std::cin >> map[i][j];
        }
    }
    std::cin >> sx >> sy >> fx >> fy;
    
    std::cout << bfs() << std::endl;

    return 0;
}