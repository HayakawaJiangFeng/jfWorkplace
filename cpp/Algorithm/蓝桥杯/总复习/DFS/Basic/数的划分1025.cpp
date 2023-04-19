#include <iostream>

int n,k;
int res;
int ans[7];

void dfs(int x, int cnt, int start){

    if(x > k){

        if(cnt == n){

            /*
            for(int i = 1; i <= k; i++){

                std::cout << ans[i] << " ";
            }
            std::cout << std::endl;
            */
            res++;
        }
        return;
    }
    if(cnt > n){

        return;
    }
    for(int i = start; cnt + (k - x + 1) * i <= n; i++){
        
        ans[x] = i;
        dfs(x + 1, cnt + i, i);
        ans[x] = 0;
    }
}
int main(){

    std::cin >> n >> k;
    
    dfs(1,0,1);

    std::cout << res << std::endl;

    return 0;
}