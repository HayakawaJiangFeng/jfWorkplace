#include <iostream>

int n,k;
int cnt;
bool flag;
int values[10005];
bool visit[10005];
int ans[10005];

void dfs(int x){

    if(flag){

        return;
    }
    if(x > n){

        cnt++;

        if(cnt == k + 1){

            flag = true;
            for(int i = 1; i <= n; i++){

                std::cout << ans[i] << " ";
            }
            std::cout << std::endl;
        }
        return;
    }

    for(int i = 1; i <= n; i++){

        if(!cnt){

            i = values[x];
        }
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

    std::cin >> n >> k;

    for(int i = 1; i <= n; i++){

        std::cin >> values[i];
    }

    dfs(1);

    return 0;
}