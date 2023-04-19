#include <iostream>

int n,m,myTime;
bool flag;
char map[110][110];
bool visit[110][110];
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

bool in(int x, int y){

    return x >= 0 && x < n && y >=0 && y < m;
}

void dfs(int x, int y, int t){

    if(t == myTime){

        if(map[x][y] == 'T'){

            flag = true;
        }
        return;
    }
    int x1,y1;
    for(int i = 0; i < 4; i++){

        visit[x][y] = true;
        x1 = x + next[i][0];
        y1 = y + next[i][1];

        if(in(x1,y1) && map[x1][y1] != 'X' && !visit[x1][y1]){

            dfs(x1, y1, t + 1);
        }
        visit[x][y] = false;
    }
}
int main(){

    std::cin >> n >> m >> myTime;

    for(int i = 0; i < n; i++){

        for(int j = 0; j < m; j++){

            std::cin >> map[i][j];
        }
    }

    int sx,sy,tx,ty;
    for(int i = 0; i < n; i++){

        for(int j = 0; j < m; j++){

            if(map[i][j] == 'S'){

                sx = i;
                sy = j;
            } 
            if(map[i][j] == 'T'){

                tx = i;
                ty = j;
            }
        }
    }
    if((sx + sy + tx + ty + myTime) % 2 != 0){

        std::cout << "no" << std::endl;
    }else{

        flag = false;
        dfs(sx, sy, 0);
        if(flag){

            std::cout << "yes" << std::endl;
        }else{

            std::cout << "no" << std::endl;
        }
    }

    return 0;
}