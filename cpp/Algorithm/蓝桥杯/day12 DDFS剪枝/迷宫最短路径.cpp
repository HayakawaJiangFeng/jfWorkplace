#include <iostream>

char maze[110][110];
bool visit[110][110];
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
int ans = 10000;
int n,m;

bool in(int x, int y){

    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y, int step){

    visit[x][y] = true;

    if(step >= ans){

        return;
    }
    if(maze[x][y] == 'T'){

        ans = step;
        return;
    }
    int tx,ty;
    for(int i = 0; i < 4; i++){

        tx = x + next[i][0];
        ty = y + next[i][1];
        if(in(tx,ty) && !visit[tx][ty] && maze[tx][ty] != '*'){

            dfs(tx, ty, step + 1);
        }
    }
    visit[x][y] = false;
}

int main(){

    std::cin >> n >> m;
    for(int i = 0; i < n; i++){

        for(int j = 0; j < m; j++){

            std::cin >> maze[i][j];
        }
    }
    int x,y;
    for(int i = 0; i < n; i++){

        for(int j = 0; j < m; j++){
            

            if(maze[i][j] == 'S'){

                x = i;
                y = j;
            }
        }
    }
    dfs(x, y, 0);

    std::cout << ans << std::endl;

    return 0;
}