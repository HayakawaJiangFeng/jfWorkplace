#include <iostream>

int n,k;
int res;
int ans[100];

void dfs(int x, int start, int cnt){

    if(cnt > n){

        return;
    }
    if(x > k){

/*      for(int i = 0; i < k; i++){

            std::cout << ans[i] << " ";
        }
        std::cout << std::endl; */
        if(cnt == n){

            res++;
        }
        return;
    }
    for(int i = start; cnt + i * (k - x + 1) <= n; i++){

        ans[x] = i;
        dfs(x + 1, i, cnt + i);
        ans[x] = 0;
    }
}

int main(){

    scanf("%d %d", &n, &k);

    dfs(1,1,0);

    printf("%d\n",res);

    return 0;
}