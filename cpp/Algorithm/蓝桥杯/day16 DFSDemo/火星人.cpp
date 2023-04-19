#include <iostream>

int n,m;
int res;

int mars[100000];
int ans[100000];
bool st[100000];

bool flag;

void dfs(int x){

    if(flag){

        return;
    }

    if(x > n){

        res++;
        if(res == m + 1){

            flag = true;
            for(int i = 1; i <= n; i++){

                printf("%d ",ans[i]);
            }
        }
        return;
    }

    for(int i = 1; i <= n; i++){

        if(!res){

            i = mars[x];
        }
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

    scanf("%d %d",&n,&m);

    for(int i = 1; i <= n; i++){

        scanf("%d",&mars[i]);
    }

    dfs(1);

    return 0;
}