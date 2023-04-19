#include <iostream>
#include <queue>

int n;
int sx,sy,fx,fy;
char map[1005][1005];
int flag[1005][1005];
int distance[1005][1005];
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
std::queue<std::pair<int, int> > q;

bool in(int xx, int yy){

    return xx > 0 && xx <= n && yy > 0 && yy <= n;
}
int bfs(int sx, int sy, int fx, int fy){
    
    memset(distance, -1, sizeof(distance));

    q.push(std::make_pair(sx,sy));
    q.push(std::make_pair(fx,fy));

    flag[sx][sy] = 1;
    flag[fx][fy] = 2;

    distance[sx][sy] = 0;
    distance[fx][fy] = 0;
    
    while (q.size())
    {
        std::pair<int, int> temp = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){

            int xx = temp.first + next[i][0];
            int yy = temp.second + next[i][1];

            if(flag[xx][yy] + flag[temp.first][temp.second] == 3){

                return distance[xx][yy] + distance[temp.first][temp.second] + 1;
            }
            if(in(xx,yy) && map[xx][yy] != '1' && distance[xx][yy] < 0){

                flag[xx][yy] = flag[temp.first][temp.second];
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

    std::cout << bfs(sx,sy,fx,fy) << std::endl;

    return 0;
}