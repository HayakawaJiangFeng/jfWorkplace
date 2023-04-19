/*
6 8
.....#.#
##.....#
##.....#
.......#
#......#
#..#...#

There are 5 ships.
*/

#include <iostream>

int R,C;
int res;
bool visit[1005][1005];
char map[1005][1005];
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

bool in(int x, int y){

    return x > 0 && x <= R && y > 0 && y <= C;
}
bool judge(int x, int y){

    int cnt = 0;
    if(map[x][y] == '#')cnt++;
    if(map[x+1][y] == '#')cnt++;
    if(map[x][y+1] == '#')cnt++;
    if(map[x+1][y+1] == '#')cnt++;
    if(cnt == 3) return false;
    return true;
}
void dfs(int x, int y){

    visit[x][y] = true;
    for(int i = 0; i < 4; i++){

        int xx = x + next[i][0];
        int yy = y + next[i][1];

        if(in(xx,yy) && !visit[xx][yy] && map[xx][yy] == '#'){

            visit[xx][yy] = true;
            dfs(xx,yy);
        }
    }
}

int main(){

    std::cin >> R >> C;

    for(int i = 1; i <= R; i++){

        for(int j = 1; j <= C; j++){

            std::cin >> map[i][j];
        }
    }

    for(int i = 1; i <= R; i++){

        for(int j = 1; j <= C; j++){

            if(!judge(i,j)){

                std::cout << "Bad placement." << std::endl;
                return 0;
            }
        }
    }
    for(int i = 1; i <= R; i++){

        for(int j = 1; j <= C; j++){

            if(!visit[i][j] && map[i][j] == '#'){

                dfs(i,j);
                res++;
            }
        }
    }
    
    std::cout << "There are " << res << " ships." << std::endl;

    return 0;
}