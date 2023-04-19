#include <iostream>

int n;
int res;
int next[2] = {1,2};

void dfs(int x){

    if(x == n){

        res++;
        return;
    }
    for(int i = 0; i < 2; i++){

        if(x + next[i] <= n){

            dfs(x + next[i]);
        }
    }
}
int main(){

    std::cin >> n;

    dfs(0);
    std::cout << res << std::endl;

    return 0;
}