/*
5 6
.#..#.
....#.
d.....
#####.
m.....

12
*/

#include <iostream>
#include <queue>
#include <cstring>

int n,m;
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
int distance[2005][2005];
char map[2005][2005];
std::queue<std::pair<int, int> > q;

bool in(int x, int y){

    return x > 0 && x <= n && y > 0 && y <= m;
}

int bfs(int x, int y){

    memset(distance,-1,sizeof(distance));
    q.push(std::make_pair(x,y));
    distance[x][y] = 0;

    while (!q.empty())
    {
        
        std::pair<int, int> temp = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){

            int xx = temp.first + next[i][0];
            int yy = temp.second + next[i][1];

            if(in(xx,yy) && map[xx][yy] != '#' && distance[xx][yy] < 0){

                distance[xx][yy] = distance[temp.first][temp.second] + 1;
                q.push(std::make_pair(xx,yy));
                if(map[xx][yy] == 'd'){

                    return distance[xx][yy];
                }
            }
        }
    }
    
    return -1;
}
int main(){

    std::cin >> n >> m;
    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= m; j++){

            std::cin >> map[i][j];
        }
    }
    int sx,sy;
    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= m; j++){

            if(map[i][j] == 'm'){

                sx = i;
                sy = j;
            }
        }
    }

    //最好把结果存一下，防止bfs运行两次使得distance数组被污染
    int res = bfs(sx,sy);

    if(res == -1){

        std::cout << "No Way!" << std::endl;
    }else{

        std::cout << res << std::endl;
    } 
    
    return 0;
}