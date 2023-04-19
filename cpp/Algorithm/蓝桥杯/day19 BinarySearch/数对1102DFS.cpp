#include <iostream>

int n,m;
int res;
int numbers[200005];
int ans[2];
bool visit[200005];

void dfs(int x){

    if(x == 2){

        if(ans[0] - ans[1] == m){

            //std::cout << ans[0] << " " << ans[1] << std::endl;
            res++;
        }
        return;
    }
    for(int i = 0; i < n; i++){

        if(!visit[i]){

            visit[i] = true;
            ans[x] = numbers[i];
            dfs(x + 1);
            ans[x] = 0;
            visit[i] = false;
        }
    }
}
int main(){

    std::cin >> n >> m;

    for(int i = 0; i < n; i++){

        std::cin >> numbers[i];
    }

    dfs(0);

    std::cout << res << std::endl;

    return 0;
}