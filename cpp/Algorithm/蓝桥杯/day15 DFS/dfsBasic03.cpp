#include <iostream>

int ans[100];

int n,k;

void dfs(int x, int start){

    //剪枝
    if((x - 1) + (n - start + 1) < k){

        return;
    }
    if(x > k){

        for(int i = 1; i <= k; i++){

            std::cout << ans[i] << " ";
        }
        std::cout << std::endl;
    }else{

        for(int i = start; i <= n; i++){

            ans[x] = i;
            dfs(x + 1, i + 1);
            ans[x] = 0; 
        }
    }
}

int main(){

    std::cin >> n >> k;

    dfs(1,1);

    return 0;
}