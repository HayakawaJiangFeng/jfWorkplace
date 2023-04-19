#include <iostream>

int n,m,t,sx,sy,fx,fy;
int res;
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
char map[10][10];
bool visit[10][10];

bool in(int x,int y){

    return x > 0 && x <= n && y > 0 && y <= m;
}
void dfs(int x, int y){

    if(map[x][y] == 'F'){

        res++;
        return;
    }
    for(int i = 0; i < 4; i++){

        int xx = x + next[i][0];
        int yy = y + next[i][1];

        if(in(xx,yy) && !visit[xx][yy] && map[xx][yy] != 'T'){

            //若是要xx,yy 则记得将起始点变true;
            visit[xx][yy] = true;
            dfs(xx,yy);
            visit[xx][yy] = false;
        }
    }
}
int main(){

    std::cin >> n >> m >> t;

    std::cin >> sx >> sy >> fx >> fy;

    map[sx][sy] = 'S';
    map[fx][fy] = 'F';

    for(int i = 0; i < t; i++){

        int tx,ty;
        std::cin >> tx >> ty;

        map[tx][ty] = 'T';
    }

    visit[sx][sy] = true;

    dfs(sx,sy);

    std::cout << res << std::endl;

    return 0;
}