#include <iostream>

int n;
int ans = 1;
bool visit[10];

void dfs(int cnt, int num){

    if(cnt == n){

        std::cout << num << std::endl;
        return;
    }
    for(int i = 1; i <= n; i++){

        visit[i] = true;
        dfs(cnt + 1, num * 10 + i);
        visit[i] = false;
    }
}
int main(){

    std::cin >> n;

    for(int i = 1; i <= n; i++){

        ans *= i;
    }
    std::cout << ans << std::endl;
    dfs(0,0);
    return 0;
}