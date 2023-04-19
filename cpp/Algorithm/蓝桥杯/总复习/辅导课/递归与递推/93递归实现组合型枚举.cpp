#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 30;

int n,k;
int ans[N];

void dfs(int x, int start){

    if(x > k){

        for(int i = 1; i <= k; i++){

            printf("%d ",ans[i]);
        }
        puts("");
        
        return;
    }

    for(int i = start; i <= n; i++){


        ans[x] = i;
        dfs(x + 1, i + 1);
        ans[x] = 0;
    }
}
int main(){

    std::cin >> n >> k;
    
    dfs(1,1);

    return 0;
}