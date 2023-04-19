#include <iostream>
#include <algorithm>

int n,m;
int values[15];
int ans[15];

void dfs(int x, int cnt){

    if(x > m){

        for(int i = 1; i <= m; i++){
            
            std::cout << ans[i] << " ";
        }
        std::cout << std::endl;
        return;
    }
    for(int i = cnt; i <= n; i++){

        if(i != cnt && values[i - 1] == values[i]){
            continue;
        }
        ans[x] = values[i];
        dfs(x + 1, i + 1);
        ans[x] = 0;
    }
}
int main(){

    std::cin >> n >> m;

    for(int i = 1; i <= n; i++){

        std::cin >> values[i];
    }
    std::sort(values, values + n + 1);

    dfs(1,1);

    return 0;
}