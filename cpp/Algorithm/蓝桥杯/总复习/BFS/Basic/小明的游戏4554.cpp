#include <iostream>
#include <deque>
#include <cstring>

int n,m;
int sx,sy,fx,fy;
int next[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
char map[505][505];
int distance[505][505];
std::deque<std::pair<int, int> > q;

bool in(int x, int y){

    return x >= 0 && x < n && y >= 0 && y < m;
}

int bfs(int x, int y){

    distance[x][y] = 0;
    q.push_back(std::make_pair(x,y));

    while (q.size())
    {
        std::pair<int, int> temp = q.front();
        q.pop_front();
        char c = map[temp.first][temp.second];

        for(int i = 0; i < 4; i++){

            int xx = temp.first + next[i][0];
            int yy = temp.second + next[i][1];

            if(in(xx,yy) && distance[xx][yy] < 0){

                if(map[xx][yy] != c){

                    distance[xx][yy] = distance[temp.first][temp.second] + 1;
                    q.push_back(std::make_pair(xx,yy));
                }else{

                    distance[xx][yy] = distance[temp.first][temp.second];
                    q.push_front(std::make_pair(xx,yy));
                }

                if(xx == fx && yy == fy){

                    return distance[xx][yy];
                }
            }  
        }
    }
    return distance[fx][fy];
}
int main(){

    bool flag = true;

    while (flag)
    {

        memset(distance, -1, sizeof(distance));      
        q.clear();

        std::cin >> n >> m;
        if(n == 0 && m == 0){

            break;
        }
        for(int i = 0; i < n; i++){

            for(int j = 0; j < m; j++){

                std::cin >> map[i][j];
            }
        }

        std::cin >> sx >> sy >> fx >> fy;

        std::cout << bfs(sx,sy) << std::endl;

        for(int i = 0; i < n; i++){

            for(int j = 0; j < m; j++){

                map[i][j] = '\0';
            }
        }
    }
    
    return 0;
}