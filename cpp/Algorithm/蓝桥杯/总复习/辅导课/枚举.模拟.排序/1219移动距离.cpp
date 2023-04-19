#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>

const int Max = 10010;

int map[Max][Max];
int dist[Max][Max];
int next[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
std::queue<std::pair<int, int> >q;
int n,start,end;
int fx,fy;

bool in(int xx, int yy){

    return xx > 0 && xx <= Max && yy > 0 && yy <= n;
}
int bfs(int sx, int sy){

    memset(dist, -1, sizeof(dist));
    q.push(std::make_pair(sx, sy));
    dist[sx][sy] = 0;

    while (q.size())
    {
        std::pair<int, int> temp = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){

            int xx = temp.first + next[i][0];
            int yy = temp.second + next[i][1];

            if(in(xx,yy) && dist[xx][yy] < 0){

                dist[xx][yy] = dist[temp.first][temp.second] + 1;
                q.push(std::make_pair(xx,yy));
                if(xx == fx && fy == yy){

                    return dist[xx][yy];
                }
            }
        }
    }
    return dist[fx][fy];
}
int main(){
    
    std::cin >> n >> start >> end;

    //1 2 3 4 5 6
    for(int j = 1; j <= Max; j++){

        if(j == 1) {
            
            for(int i = 1; i <= n; i++){

                map[j][i] = i;
            }
        }
        if(j != 1 && j % 2 != 0){

            map[j][1] = map[j - 1][1] + 1;
            for(int i = 2; i <= n; i++){

                map[j][i] = map[j][i - 1] + 1; 
            }
        }
        if(j != 1 && j % 2 == 0){

            map[j][n] = map[j - 1][n] + 1;
            for(int i = n - 1; i >= 1; i--){

                map[j][i] = map[j][i + 1] + 1;
            }
        }
    }
    int sx,sy;
    for(int i = 1; i <= Max; i++){

        for(int j = 1; j <= n; j++){

            if(map[i][j] == start){

                sx = i;
                sy = j;
            }
            if(map[i][j] == end){

                fx = i;
                fy = j;
            }
        }
    }
    std::cout << bfs(sx, sy) << std::endl;
    /*
    for(int i = 1; i <= 20; i++){

        for(int j = 1; j <= 4; j++){

            std::cout << map[i][j] << " ";
        }
        std::cout << std::endl;
    }
    for(int i = 1; i <= 20; i++){

        for(int j = 1; j <= 4; j++){

            std::cout << dist[i][j] << " ";
        }
        std::cout << std::endl;
    }
    */
    return 0;
}