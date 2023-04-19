#include <iostream>

/*
4
0 1 1 1
1 0 2 1
5 5 0 6
1 1 3 0
*/
int n;
int city[20][20];
bool visit[20];

int ans = 1000;

void dfs(int u, int cnt, int sum){

    if(sum > ans){
        
        return;
    }
    if(cnt == n){

        ans = std::min(ans, sum + city[u][1]);
        return;
    }
    visit[u] = true;
    for(int i = 1; i <= n; i++){

        if(!visit[i]){

            dfs(i, cnt + 1, sum + city[u][i]);
        }
    }
    visit[u] = false;
}
int main(){

    std::cin >> n;

    for(int i = 1; i <=n; i++){

        for(int j = 1; j <= n; j++){

            std::cin >> city[i][j];
        }
    }
    dfs(1,1,0);
    std::cout << ans << std::endl;
    return 0;
}