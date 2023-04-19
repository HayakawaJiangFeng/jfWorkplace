#include <iostream>

char map[1005][1005];
int dir[8][2] = {{1,2},{-1,2},{-1,-2},{1,-2},{2,1},{-2,-1},{-2,1},{2,-1}};
int row,arrange;

void dfs(int x, int y, int step){

    if(step > 3){
        
        return;
    }
    if(x < 0 || x >= row || y < 0 || y >= arrange){

        return;
    }

    map[x][y] = '#';

    for(int i = 0; i < 8; i++){

        int tx,ty;
        tx = x + dir[i][0];
        ty = y + dir[i][1];
        dfs(tx,ty,step+1);
    }
}

int main(){

    int x,y;
    std::cin >> row >> arrange >> x >> y;

    for(int i = 0; i < row; i++){

        for(int j = 0; j < arrange; j++){

            map[i][j] = '.';
        }
    }
    dfs(x - 1,y - 1, 0);
    for(int i = 0; i < row; i++){

        std::cout << map[i] << std::endl;
    }

    return 0;
}