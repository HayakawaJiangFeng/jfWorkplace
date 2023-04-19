#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

const int N = 15;

int n;
int ans[N];
bool st[N];

void dfs(int x){

    if(x > n){

        for(int i = 1; i <= n; i++){

            printf("%d ",ans[i]);
        }
        puts("");

        return;
    }

    for(int i = 1; i <= n; i++){

        if(!st[i]){

            st[i] = true;
            ans[x] = i;
            dfs(x + 1);
            ans[x] = 0;
            st[i] = false;
        }
    }
}
int main(){

    std::cin >> n;
    
    dfs(1);

    return 0;
}