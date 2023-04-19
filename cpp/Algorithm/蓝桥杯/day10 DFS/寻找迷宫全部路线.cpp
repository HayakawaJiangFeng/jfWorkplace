#include <iostream>

int row,arrange,ans;

char map[15][15];
bool visit[15][15];

void dfs(int x, int y){

    if(visit[x][y] || x < 0 || y < 0 || x >= row || y >= arrange || map[x][y] == '#'){

        return;
    }

    if(map[x][y] == 'e'){

        ans++;
        return;
    }
    visit[x][y] = true;
    dfs(x - 1,y);
    dfs(x + 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);

    visit[x][y] = false;
}
int main(){

    std::cin >> row >> arrange;
    for(int i = 0; i < row; i++){

        for(int j = 0; j < arrange; j++){

            std::cin >> map[i][j];
        }
    }

    int x,y;
    
    for(int i = 0; i < row; i++){

        for(int j = 0; j < arrange; j++){

            if(map[i][j] == 's'){

                x = i;
                y = j;
            }
        }
    }

    dfs(x, y);
    std::cout << ans << std::endl;

    return 0;
}