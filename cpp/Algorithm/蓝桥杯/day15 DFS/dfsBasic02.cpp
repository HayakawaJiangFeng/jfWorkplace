#include <iostream>

int n;
bool st[100];
int ans[100];

void dfs(int x){

    if(x > n){

        for(int i = 1; i <= n; i++){

            std::cout << ans[i] << " ";
        }
        std::cout << std::endl;
    }
    for(int i = 1; i <= n; i++){

        if(!st[i]){

            ans[x] = i;
            st[i]  = true;
            dfs(x + 1);
            st[i] = false;
            ans[x] = 0;
        }
    }
}
int main(){

    std::cin >> n;
    dfs(1);

    return 0;
}