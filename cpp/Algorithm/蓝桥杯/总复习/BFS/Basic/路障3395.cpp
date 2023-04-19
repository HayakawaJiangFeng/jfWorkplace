#include <iostream>
#include <cstring>
#include <queue>

int T;
int n;
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
int map[2005][2005];
int dist[2005][2005];
std::queue<std::pair<int, int> > q;

bool in(int x, int y){

    return x > 0 && x <= n && y > 0 && y <= n;
}

void bfs(int x, int y){

    dist[x][y] = 0;
    q.push(std::make_pair(x,y));
    if(x == n && y == n){

        std::cout << "Yes" << std::endl;
        return;
    }

    while (q.size())
    {
        
        std::pair<int, int> temp = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){

            int xx = temp.first + next[i][0];
            int yy = temp.second + next[i][1];

            if(in(xx,yy) && dist[xx][yy] < 0 && dist[temp.first][temp.second] + 1 <= map[xx][yy]){

                dist[xx][yy] = dist[temp.first][temp.second] + 1;
                q.push(std::make_pair(xx,yy));

                if(xx == n && yy == n){

                    std::cout << "Yes" << std::endl;
                    return;
                }
            }
        }
    }
    std::cout << "No" << std::endl;
    return;
}
int main(){

    std::cin >> T;

    for(int i = 1; i <= T; i++){

        q = std::queue<std::pair<int, int> >();
        memset(map, 0x3f, sizeof(map));
        memset(dist, -1, sizeof(dist));

        std::cin >> n;

        for(int i = 1; i <= 2 * n - 2; i++){

            int x,y;
            std::cin >> x >> y;
            map[x][y] = std::min(map[x][y], i);
        }
        /*
        for(int i = 1; i <= n; i++){

            for(int j = 1; j <= n; j++){

                std::cout << map[i][j] << " ";
            }
            std::cout << std::endl;
        }
        */
        bfs(1,1);
        /*
        for(int i = 1; i <= n; i++){

            for(int j = 1; j <= n; j++){

                std::cout << dist[i][j] << " ";
            }
            std::cout << std::endl;
        }
        */
    }

    return 0;
}