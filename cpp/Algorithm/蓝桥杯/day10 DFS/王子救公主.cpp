#include <iostream>

int row,arrange;
char map[1005][1005];
int visit[1005][1005][2];

void dfs(int x, int y, int d){

    if(x < 0 || x >= row || y < 0 || y >= arrange || visit[x][y][d] || map[x][y] == '#'){

        return;
    }
    visit[x][y][d] = true;
    
    dfs(x + (2 - d), y, d);
    dfs(x - (2 - d), y, d);
    dfs(x, y - (2 - d), d);
    dfs(x, y + (2 - d), d);
}

int main(){

    std::cin >> row >> arrange;

    for(int i = 0; i < row; i++){

        std::cin >> map[i];
    }

    int wx,wy,gx,gy;
    for(int i = 0; i < row; i++){

        for(int j = 0; j < arrange; j++){

            if(map[i][j] == 'w'){

                wx = i;
                wy = j;
            }
            if(map[i][j] == 'g'){

                gx = i;
                gy = j;
            }
        }
    }
    dfs(wx, wy ,0);
    dfs(gx, gy ,1);
    
    bool ans = false;
    for(int i = 0; i < row; i++){

        for(int j = 0; j < arrange; j++){

            if(visit[i][j][1] && visit[i][j][0]){

                ans = true;
            }
        }
    }

    if(ans){

        std::cout << "yes" << std::endl;
    }else{

        std::cout << "no" << std::endl;
    }
}