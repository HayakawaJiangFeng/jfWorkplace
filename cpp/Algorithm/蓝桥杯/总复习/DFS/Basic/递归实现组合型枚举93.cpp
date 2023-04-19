#include <iostream>

int n,m;
int ans[1000];

void dfs(int x, int cnt){

    if(x > m){

        for(int i = 1; i <= m; i++){

            std::cout << ans[i] << " ";
        }
        std::cout << std::endl;
        return;
    }
    for(int i = cnt;i <= n; i++){

        ans[x] = i;
        dfs(x + 1, i + 1);
        ans[x] = 0;
    }
}

int main(){

    std::cin >> n >> m;

    dfs(1,1);

    return 0;
}