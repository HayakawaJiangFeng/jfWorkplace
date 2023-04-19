#include <iostream>
#include <cstring>
#include <queue>

int m;
int next[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
int map[305][305];
int distance[305][305];

std::queue<std::pair<int, int> > q;

bool in(int x, int y){

    return x >= 0 && x <= 301 && y >= 0 && y <= 301;
}
bool peopleIn(int x, int y){

    return x >= 0 && y >= 0;
}

int bfs(int x, int y){

    memset(distance, -1, sizeof(distance));
    distance[x][y] = 0;
    q.push(std::make_pair(x,y));

    while (q.size())
    {
        
        std::pair<int, int> temp = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){

            int xx = temp.first + next[i][0];
            int yy = temp.second + next[i][1];

            if(peopleIn(xx,yy) && distance[xx][yy] < 0 && distance[temp.first][temp.second] + 1 < map[xx][yy]){

                distance[xx][yy] = distance[temp.first][temp.second] + 1;
                q.push(std::make_pair(xx,yy));
                if(map[xx][yy] > 1e9){

                    return distance[xx][yy];
                }
            }
        }
    }
    return -1;
}
int main(){

    std::cin >> m;
    memset(map, 0x3f, sizeof(map));
    for(int i = 1; i <= m; i++){

        int x,y,t;
        std::cin >> x >> y >> t;
        map[x][y] = std::min(map[x][y], t);

        for(int i = 0; i < 4; i++){

            int xx = x + next[i][0];
            int yy = y + next[i][1];

            if(in(xx,yy)){

                map[xx][yy] = std::min(map[xx][yy], t);
            }
        }
    }

    std::cout << bfs(0,0) << std::endl;

    return 0;
}