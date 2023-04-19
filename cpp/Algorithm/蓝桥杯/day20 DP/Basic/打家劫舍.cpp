#include <iostream>

int n;
int values[105];

int dfs(int x, int cnt){

    if(x > n){

        return cnt;
    }
    return std::max(dfs(x + 1,cnt), dfs(x + 2,cnt + values[x]));
}
int main(){

    std::cin >> n;
    
    for(int i = 1; i <= n; i++){

        std::cin >> values[i];
    }

    std::cout << dfs(1,0) << std::endl;
    
    return 0;
}