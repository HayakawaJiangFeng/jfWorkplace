#include <iostream>

int n;
int task[15][15];
bool visit[15];
int ans;

void dfs(int x, int time){

    if(x == n){

        if(time < ans){

            ans = time;
        }
    }
    for(int i = 0; i < n; i++){

        if(!visit[i]){

            visit[i] = true;
            dfs(x + 1, time + task[x][i]);
            visit[i] = false;
        }
    }
}

int main(){

    std::cin >> n;

    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){

            std::cin >> task[i][j];
        }
    }
    ans = 200000;
    dfs(0,0);
    std::cout << ans << std::endl;
    return 0;
}