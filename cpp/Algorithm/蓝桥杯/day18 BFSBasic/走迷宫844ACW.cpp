#include <iostream>

int n,m;
int res = 1e9;
int map[105][105];
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
bool st[105][105];

bool in(int x, int y){

    return x > 0 && x <= n && y > 0 && y <= m;
}
void dfs(int x, int y, int cnt){

    if(x == n && y == m){

        res = std::min(res, cnt);
        return;
    }
    for(int i = 0; i < 4; i++){

        int tx = x + next[i][0];
        int ty = y + next[i][1];

        if(!st[tx][ty] && map[tx][ty] == 0 && in(tx,ty)){

            st[x][y] = true;
            dfs(tx, ty, cnt + 1);
            st[x][y] = false;
        }
    }
}

int main(){

    std::cin >> n >> m;

    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= m; j++){

            std::cin >> map[i][j];
        }
    }

    dfs(1,1,0);

    std::cout << res << std::endl;

    return 0;
}