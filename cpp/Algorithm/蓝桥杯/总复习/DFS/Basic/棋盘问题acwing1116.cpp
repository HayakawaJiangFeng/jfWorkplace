#include <iostream>

int n,k;
int res;
int cnt;
bool visit[10];
char map[10][10];

void dfs(int x){

    if(cnt == k){

        res++;
        return;
    }
    if(x > n){

        return;
    }
    for(int i = 1; i <= n; i++){

        if(map[i][x] == '#' && !visit[x]){

            cnt++;
            visit[x] = true;
            dfs(x + 1);
            visit[x] = false;
            cnt--;
        }
    }
    dfs(x + 1);
}
int main(){

    while (std::cin >> n >> k)
    {
        if(n == -1 && k == -1){

            break;
        }

        for(int i = 1; i <= n; i++){

            for(int j = 1; j <= n; j++){

                std::cin >> map[i][j];
            }
        }

        res = 0;
        cnt = 0;

        dfs(1);
        
        std::cout << res << std::endl;
    }
    return 0;
}