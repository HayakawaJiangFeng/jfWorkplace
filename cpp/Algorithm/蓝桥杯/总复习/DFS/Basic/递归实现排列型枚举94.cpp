#include <iostream>

int n;
int ans[15];
bool visit[15];

void dfs(int x){

    if(x > n){

        for(int i = 1; i <= n; i++){

            std::cout << ans[i] << " ";
        }
        std::cout << std::endl;
    }
    for(int i = 1; i <= n; i++){

        if(!visit[i]){

            visit[i] = true;
            ans[x] = i;
            dfs(x + 1);
            ans[x] = 0;
            visit[i] = false;
        }
    }
}
int main(){

    std::cin >> n;

    dfs(1);

    return 0;
}