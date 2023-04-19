#include <iostream>

char cake[1005][1005];
bool visit[1005][1005];

int row, arrange,cnt,ans;

void dfs(int x, int y){

    if(x < 0 || x >= row || y < 0 || y >= arrange || cake[x][y] == '.' || visit[x][y]){

        return;
    }
    visit[x][y] = true;
    cnt++;
    dfs(x - 1,y);
    dfs(x + 1,y);
    dfs(x, y - 1);
    dfs(x, y + 1);
}

int main(){

    std::cin >> row >> arrange;

    for(int i = 0; i < row; i++){

        for(int j = 0; j < arrange; j++){

            std::cin >> cake[i][j];
        }
    }

    for(int i = 0; i < row; i++){

        for(int j = 0; j < arrange; j++){

            if(!visit[i][j] && cake[i][j] == '#'){

                cnt = 0;
                dfs(i,j);
                if(cnt > ans){

                    ans = cnt;
                }
            }          
        }
    }
    std::cout << ans << std::endl;
    return 0;
}