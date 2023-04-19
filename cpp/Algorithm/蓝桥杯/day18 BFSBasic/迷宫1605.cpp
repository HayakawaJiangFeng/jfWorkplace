/*
2 2 1
1 1 2 2
1 2

1
*/

#include <iostream>
#include <queue>
#include <cstring>

int N,M,T,sx,sy,fx,fy;
int res;
char map[10][10];
bool st[10][10];
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

bool in(int x, int y){

    return x > 0 && x <= N && y > 0 && y <= M;
}

void dfs(int sx, int sy){

    if(map[sx][sy] == 'F'){

        res++;
        return;
    }

    for(int i = 0; i < 4; i++){

        int xx = sx + next[i][0];
        int yy = sy + next[i][1];

        if(in(xx,yy) && map[xx][yy] != '1' && !st[xx][yy]){

            st[sx][sy] = true;
            dfs(xx,yy);
            st[sx][sy] = false;
        }
    }
}
int main(){

    std::cin >> N >> M >> T;

    std::cin >> sx >> sy >> fx >> fy;
    map[sx][sy] = 'S';
    map[fx][fy] = 'F';

    for(int i = 0; i < T; i++){

        int tx,ty;
        std::cin >> tx >> ty;
        map[tx][ty] = '1';
    }

    dfs(sx,sy);

    std::cout << res << std::endl;

    return 0;
}