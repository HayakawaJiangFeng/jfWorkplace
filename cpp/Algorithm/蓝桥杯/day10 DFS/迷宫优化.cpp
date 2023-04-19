#include <iostream>

int row, arrange;

//迷宫
std::string maze[110];

//标记数组
int load[110][110];

//方向数组
int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

//判断点是否在迷宫内
bool in(int x, int y){

    return 0 <= x && x < row && 0 <= y && y < arrange;
}

bool dfs(int x, int y){

    if(maze[x][y] == 'T'){

        return true;
    }

    //迷宫路线
    maze[x][y] = 'm';

    //记录已经走到的点
    load[x][y] = 1;


    for(int i = 0; i < 4; i++){

        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        
        if(in(tx,ty) && !load[tx][ty] && maze[tx][ty] != '*'){

            if(dfs(tx,ty)){

                return true;
            }
        }
    }

    //走不通

    //复原地图
    maze[x][y] = '.';

    //清除到过的标记
    load[x][y] = 0;

    return false;
}
int main(){

    //输入迷宫规模
    std::cin >> row >> arrange;

    //输入迷宫
    for(int i = 0; i < row; i++){

        std::cin >> maze[i];
    }

    //输出迷宫
    std::cout << "迷宫 : " << std::endl;
    for(int i = 0; i < row; i++){

        for(int j = 0; j < arrange; j++){

            std::cout << maze[i][j] << " ";
        }
        std::cout << std::endl;
    }

    //找到迷宫起点
    int x,y;
    for(int i = 0; i < row; i++){

        for(int j = 0; j < arrange; j++){

            if(maze[i][j] == 'S'){

                x = i;
                y = j;
            }
        }
    }

    if(dfs(x,y)){

        for(int i = 0; i < row; i++){

            for(int j = 0; j < arrange; j++){

                std::cout << maze[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}