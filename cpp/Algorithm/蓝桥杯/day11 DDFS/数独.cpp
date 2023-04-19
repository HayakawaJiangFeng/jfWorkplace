#include <cstdio>
//数独，9 * 9 宫格中，每一行和没一列和每一个 3 * 3 的宫格中不能出现重复数字
/*
* 2 6 * * * * * *
* * * 5 * 2 * * 4
* * * 1 * * * * 7
* 3 * * 2 * 1 8 *
* * * 3 * 9 * * *
* 5 4 * 1 * * 7 *
5 * * * * 1 * * *
6 * * 9 * 7 * * *
* * * * * * 7 5 *

1 2 6 7 3 4 5 9 8
3 7 8 5 9 2 6 1 4
4 9 5 1 6 8 2 3 7
7 3 9 4 2 5 1 8 6
8 6 1 3 7 9 4 2 5
2 5 4 8 1 6 3 7 9
5 4 7 2 8 1 9 6 3
6 1 3 9 5 7 8 4 2
9 8 2 6 4 3 7 5 1
*/
char s[10][10];
bool flag;
bool vx[10][10],vy[10][10],vv[10][10];

void dfs(int x, int y){

    if(flag){

        return;
    }
    if(x == 9){

        flag = true;
        for(int i = 0; i < 9; i++){

            for(int j = 0; j < 9; j++){

                if(j != 8){

                    printf("%c ",s[i][j]);
                }else{

                    printf("%c\n",s[i][j]);
                }
            }
        }
        return;
    }
    if(y == 9){

        dfs(x + 1, 0);
        return;
    }
    if(s[x][y] != '*'){

        dfs(x,y+1);
        return;
    }

    for(int i = 1; i <= 9; i++){

        if(!vx[x][i] && !vy[y][i] && !vv[x / 3 * 3 + y / 3][i]){

            s[x][y] = '0' + i;
            vx[x][i] = true;
            vy[y][i] = true;
            vv[x / 3 * 3 + y / 3][i] = true;
            dfs(x, y + 1);
            vx[x][i] = false;
            vy[y][i] = false;
            vv[x / 3 * 3 + y / 3][i] = false;
            s[x][y] = '*';
        }   
    }
}

int main(){

    for(int i = 0; i < 9; i++){

        for(int j = 0; j < 9; j++){

            scanf(" %c",&s[i][j]);
        }
    }
    for(int i = 0; i < 9; i++){

        for(int j = 0; j < 9; j++){

            if(s[i][j] != '*'){

                vx[i][s[i][j] - '0'] = true;
                vy[j][s[i][j] - '0'] = true;
                vv[i / 3 * 3 + j / 3][s[i][j] - '0'] = true;
            }
        }
    }
    dfs(0,0);

    return 0;
}