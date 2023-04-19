#include <iostream>

int n,m;
int res;
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
bool visit[25][25];
char map[25][25];

bool in(int xx, int yy){

    return xx > 0 && xx <= n && yy > 0 && yy <= m;
}
void dfs(int x, int y){

    for(int i = 0; i < 4; i++){

        int xx = x + next[i][0];
        int yy = y + next[i][1];

        if(in(xx,yy) && map[xx][yy] != '#' && !visit[xx][yy]){

            visit[xx][yy] = true;
            res++;
            dfs(xx,yy);
        }
    }
}
int main(){

    std::cin >> m >> n;

    int sx,sy;
    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= m; j++){

            std::cin >> map[i][j];
            if(map[i][j] == '@'){

                sx = i;
                sy = j;
            }
        }
    }
    
    visit[sx][sy] = true;
    res++;
    dfs(sx,sy);

    std::cout << res << std::endl;

    return 0;
}