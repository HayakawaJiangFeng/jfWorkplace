#include <iostream>
#include <algorithm>

int n;
int values[15];
int ans[15];
bool visit[15];

void dfs(int x){

    if(x > n){

        for(int i = 1; i <= n; i++){

            std::cout << ans[i] << " ";
        }
        std::cout << std::endl;
        return;
    }

    for(int i = 1; i <= n; i++){

        if(!visit[i]){

            if(values[i] == values[i - 1] && visit[i - 1]){
                continue;
            }
            visit[i] = true;
            ans[x] = values[i];
            dfs(x + 1);
            ans[x] = 0;
            visit[i] = false;
        }
    }
}
int main(){

    std::cin >> n;
    for(int i = 1; i <= n; i++){

        std::cin >> values[i];
    }

    std::sort(values, values + 1 + n);

    dfs(1);

    return 0;
}