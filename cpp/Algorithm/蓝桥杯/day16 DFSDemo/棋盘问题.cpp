#include <iostream>

int n,k;
char map[25][25];
bool st[25];
int res;

void dfs(int x, int cnt){

    if(cnt == k){

        res++;
        return;
    }
    if(x >= n){

        return;
    }
    for(int i = 0; i < n; i++){

        if(!st[i] && map[x][i] == '#'){

            st[i] = true;
            dfs(x + 1, cnt + 1);
            st[i] = false;
        }
    }
    dfs(x + 1, cnt);
}

int main(){

    while(std::cin >> n >> k , n > 0 && k > 0){

        for(int i = 0; i < n; i++){

            for(int j = 0; j < n; j++){

                std::cin >> map[i][j];
            }
        }
        res = 0;

        dfs(0,0);
        
        std::cout << res << std::endl;
    }

    return 0;
}