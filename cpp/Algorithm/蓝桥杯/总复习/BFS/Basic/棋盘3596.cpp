#include <iostream>
#include <deque>
#include <cstring>

int m,n;
int map[1005][1005];
int next[4][2] = {{1,0},{0,1},{-1,0},{-1,0}};
int dist[1005][1005];
std::deque<std::pair<int, int> > q;

bool in(int x, int y){

    return x > 0 && x <= m && y > 0 && y <= m;
}

int bfs(int x, int y){

    memset(dist, -1, sizeof(dist));
    dist[x][y] = 0;
    q.push_back(std::make_pair(x,y));

    while (q.size())
    {
        std::pair<int, int> temp = q.front();
        q.pop_front();

        for(int i = 0; i < 4; i++){

            int xx = temp.first + next[i][0];
            int yy = temp.second + next[i][1];

            if(in(xx,yy) && dist[xx][yy] < 0){

                if(map[xx][yy] != 0 && map[xx][yy] == map[temp.first][temp.second]){

                    dist[xx][yy] = dist[temp.first][temp.second];
                    q.push_front(std::make_pair(xx,yy));
                }else if(map[xx][yy] != 0 && map[xx][yy] != map[temp.first][temp.second]){

                    dist[xx][yy] = dist[temp.first][temp.second] + 1;
                    q.push_back(std::make_pair(xx,yy));
                }else{

                    dist[xx][yy] = dist[temp.first][temp.second] + 2;
                    map[xx][yy] = map[temp.first][temp.second];
                    q.push_back(std::make_pair(xx,yy));
                    map[xx][yy] = 0;
                }
                if(xx == m && yy == m){
                    
                    return dist[xx][yy];
                }
            }
        }
    }
    return dist[m][m];
}

int main(){

    std::cin >> n >> m;

    for(int i = 0; i < m; i++){

        int x,y,c;
        std::cin >> x >> y >> c;

        map[x][y] = c;
    }

    std::cout << bfs(1,1) << std::endl;

    return 0;
}