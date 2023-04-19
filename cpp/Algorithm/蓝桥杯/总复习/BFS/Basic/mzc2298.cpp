#include <iostream>
#include <cstring>
#include <queue>

int n,m;
char map[2005][2005];
int distance[2005][2005];
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
std::queue<std::pair<int, int> > q;

bool in(int x,int y){

    return x > 0 && x <= n && y > 0 && y <= m;
}

void bfs(int x, int y){

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

            if(in(xx,yy) && distance[xx][yy] < 0 && map[xx][yy] != '#'){

                distance[xx][yy] = distance[temp.first][temp.second] + 1;
                q.push(std::make_pair(xx,yy));
            }
        }
    }
    
}
int main(){

    std::cin >> n >> m;

    int sx,sy;
    int fx,fy;
    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= m; j++){

            std::cin >> map[i][j];
            if(map[i][j] == 'm'){

                sx = i;
                sy = j;
            }
            if(map[i][j] == 'd'){

                fx = i;
                fy = j;
            }
        }
    }
    bfs(sx,sy);

    if(distance[fx][fy] == -1){

        std::cout << "No Way!" << std::endl;
    }else{

        std::cout << distance[fx][fy] << std::endl;
    }

    return 0;
}