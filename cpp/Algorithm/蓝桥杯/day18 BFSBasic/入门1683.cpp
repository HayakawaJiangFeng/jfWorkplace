#include <iostream>
#include <queue>
#include <cstring>

int W,H;
/*
注意res不能是distance数组中最大的那一个，distance最大的值指的是一条路走到底可以走多长，而这道题求的是
迷宫中有多少可以走的方块，一但这个方块可以走并且没有被走过则+1
*/
int res = 1;
char map[25][25];
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
int distance[25][25];

std::queue<std::pair<int, int> > q;

bool in(int x, int y){

    return x > 0 && x <= H && y > 0 && y <= W;
}
void bfs(int x, int y){

    memset(distance, -1, sizeof(distance));
    std::pair<int, int> p(x,y);
    q.push(p);
    distance[x][y] = 1;

    while (!q.empty())
    {
    
        std::pair<int, int> temp = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){

            int xx = temp.first + next[i][0];
            int yy = temp.second + next[i][1];

            if(in(xx,yy) && map[xx][yy] != '#' && distance[xx][yy] < 0){

                res++;
                std::pair<int, int> p1(xx,yy);
                q.push(p1);
                distance[xx][yy] = distance[temp.first][temp.second] + 1;
            }
        }
    }
    
}

int main(){

    std::cin >> W >> H;

    int sx,sy;
    for(int i = 1; i <= H; i++){

        for(int j = 1; j <= W; j++){

            std::cin >> map[i][j];
            if(map[i][j] == '@'){

                sx = i;
                sy = j;
            }
        }
    }
    bfs(sx, sy);

    for(int i = 1; i <= H; i++){

        for(int j = 1; j <= W; j++){

            std::cout << distance[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << res << std::endl;

    return 0;
}