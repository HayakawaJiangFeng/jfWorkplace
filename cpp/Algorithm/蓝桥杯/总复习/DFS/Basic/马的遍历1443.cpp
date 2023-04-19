#include <iostream>

int n,m,sx,sy;
int ii,jj;
int map[405][405];
bool visit[405][405];
int next[8][2] = {{1,2},{-1,-2},{-1,2},{1,-2},{2,1},{-2,-1},{-2,1},{2,-1}};

bool in(int x, int y){

    return x > 0 && x <= n && y > 0 && y <= m;
}
void dfs(int x, int y, int cnt){

    if(x == ii && y == jj){

        map[x][y] = std::min(map[x][y], cnt);
        return;
    }
    for(int i = 0; i < 8; i++){

        int xx = x + next[i][0];
        int yy = y + next[i][1];

        if(in(xx,yy) && !visit[xx][yy]){

            visit[x][y] = true;
            dfs(xx,yy,cnt + 1);
            visit[x][y] = false;
        }
    }
}
int main(){

    std::cin >> n >> m >> sx >> sy;

    for(ii = 1; ii <= n; ii++){

        for(jj = 1; jj <= m; jj++){

            map[ii][jj] = 1e9;
            dfs(sx,sy,0);
        }
    }

    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= m; j++){

            if(map[i][j] == 1e9){

                map[i][j] = -1;
            }
            std::cout << map[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}