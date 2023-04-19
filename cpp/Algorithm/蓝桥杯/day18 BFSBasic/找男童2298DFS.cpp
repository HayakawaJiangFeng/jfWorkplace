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

int n,m;
int res = 1e9;
char map[2005][2005];
int next[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};
bool st[2005][2005];

bool in(int x, int y){

    return x > 0 && x <= n && y > 0 && y <= m;
}

void dfs(int x, int y, int cnt){

    if(map[x][y] == 'd'){

        res = std::min(res, cnt);
        return;
    }

    for(int i = 0; i < 4; i++){

        int xx = x + next[i][0];
        int yy = y + next[i][1];

        if(in(xx,yy) && map[xx][yy] != '#' && !st[xx][yy]){

            st[x][y] = true;
            dfs(xx,yy,cnt + 1);
            st[x][y] = false;
        }
    }
}

int main(){

    std::cin >> n >> m;

    int sx,sy;
    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= m; j++){

            std::cin >> map[i][j];
            if(map[i][j] == 'm'){

                sx = i;
                sy = j;
            }
        }
    }

    dfs(sx,sy,0);

    if(res == 1e9){

        std::cout << "No Way!" << std::endl;
    }else{

        std::cout << res << std::endl;
    }

    return 0;
}