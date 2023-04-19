#include <iostream>
#include <deque>
#include <cstring>

int n,m;
int sx,sy,fx,fy;
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
char map[505][505];
int distance[505][505];
std::deque<std::pair<int, int> > q;

bool in(int x, int y){

    return x >= 0 && x < n && y >= 0 && y < m;
}
int bfs(int x, int y){

    q.push_back(std::make_pair(x,y));
    distance[x][y] = 0;

    while (!q.empty())
    {
        
        std::pair<int, int> temp = q.front();
        char ch = map[temp.first][temp.second];

        q.pop_front();

        for(int i = 0; i < 4; i++){

            int xx = temp.first + next[i][0];
            int yy = temp.second + next[i][1];

            if(in(xx,yy) && distance[xx][yy] < 0){

                if(map[xx][yy] == ch){

                    distance[xx][yy] = distance[temp.first][temp.second];
                    q.push_front(std::make_pair(xx,yy));
                }
                if(map[xx][yy] != ch){

                    distance[xx][yy] = distance[temp.first][temp.second] + 1;
                    q.push_back(std::make_pair(xx,yy));
                }

                if(xx == fx && yy == fy){

                    return distance[fx][fy];
                }
            }
        }
    }
    return -1;
}
int main(){

    while (std::cin >> n >> m, n || m)
    {
        
        for(int i = 0; i < n; i++){

            for(int j = 0; j < m; j++){

                std::cin >> map[i][j];
            }
        }

        memset(distance, -1, sizeof(distance));
        q.clear();

        std::cin >> sx >> sy >> fx >> fy;

        int res = bfs(sx,sy);

        std::cout << res << std::endl;
    }
    
    return 0;
}