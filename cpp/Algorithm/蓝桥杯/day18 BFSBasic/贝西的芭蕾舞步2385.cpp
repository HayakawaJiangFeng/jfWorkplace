#include <iostream>
#include <cstring>
#include <queue>

int M,N,M1,M2;
int sx,sy,fx,fy;
int map[35][35];
int distance[35][35];
int dx[8];
int dy[8];
std::queue<std::pair<int, int> > q;

bool in(int x,int y){

    return x > 0 && x <= M && y > 0 && y <= N;
}
int bfs(int x, int y){

    memset(distance, -1, sizeof(distance));
    distance[x][y] = 0;
    q.push(std::make_pair(x,y));

    while (!q.empty())
    {
        
        std::pair<int, int> temp = q.front();
        q.pop();

        for(int i = 0; i < 8; i++){

            int xx = temp.first + dx[i];
            int yy = temp.second + dy[i];

            if(in(xx,yy) && map[xx][yy] != 0 && distance[xx][yy] < 0){

                distance[xx][yy] = distance[temp.first][temp.second] + 1;
                q.push(std::make_pair(xx,yy));

                if(xx == fx && yy == fy){

                    return distance[fx][fy];
                }
            }
        }
    }
    return distance[fx][fy];
}
int main(){

    std::cin >> M >> N >> M1 >> M2;

    dx[0] = M1;
    dx[1] = M2;
    dx[2] = M1;
    dx[3] = -M1;
    dx[4] = M2;
    dx[5] = -M2;
    dx[6] = -M1;
    dx[7] = -M2;

    dy[0] = M2;
    dy[1] = M1;
    dy[2] = -M2;
    dy[3] = M2;
    dy[4] = -M1;
    dy[5] = M1;
    dy[6] = -M2;
    dy[7] = -M1;

    for(int i = 1; i <= M; i++){

        for(int j = 1; j <= N; j++){

            std::cin >> map[i][j];
            if(map[i][j] == 2){

                map[i][j] = 0;
            }
            if(map[i][j] == 3){

                sx = i;
                sy = j;
            }
            if(map[i][j] == 4){

                fx = i;
                fy = j;
            }
        }
    }
    std::cout << bfs(sx,sy) << std::endl;

    return 0;
}