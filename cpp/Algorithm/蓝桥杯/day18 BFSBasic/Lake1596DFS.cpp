/*
10 12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.

3
*/

#include <iostream>

int N,M;
int res;
int next[8][2] = {{-1,0},{0,-1},{1,0},{0,1},{1,1},{-1,-1},{1,-1},{-1,1}};
char map[105][105];
bool visit[105][105];
bool st[105][105];

bool in(int x, int y){

    return x > 0 && x <= N && y > 0 && y <= M;
}
void dfs(int x, int y){

    for(int i = 0; i < 8; i++){

        int xx = x + next[i][0];
        int yy = y + next[i][1];

        if(in(xx,yy) && map[xx][yy] == 'W' && !st[xx][yy]){

            st[x][y] = true;
            visit[xx][yy] = true;
            dfs(xx,yy);
            st[x][y] = false;
        }
    }
}
int main(){

    std::cin >> N >> M;

    for(int i = 1; i <= N; i++){

        for(int j = 1; j <= M; j++){

            std::cin >> map[i][j];
        }
    }

    for(int i = 1; i <= N; i++){

        for(int j = 1; j <= M; j++){

            if(map[i][j] == 'W' && !visit[i][j]){

                dfs(i,j);
                res++;
            }
        }
    }
    
    std::cout << res << std::endl;

    return 0;
}