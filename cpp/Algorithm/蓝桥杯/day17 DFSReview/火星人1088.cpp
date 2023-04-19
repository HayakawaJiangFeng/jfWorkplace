/*
输入n个数字 如 n = 5,
(1,2,3,4,5)
(1,2,3,5,4)
(1,2,4,3,5)
(1,2,4,5,3)

以此类推...

若输入n = 5， k = 3， （1，2，3，4，5）
则输出 1 2 4 5 3
*/

#include <iostream>

int n,k;
int res;
int ans[100005];
int numbers[100005];
bool st[100005];
bool flag;

void dfs(int x){

    if(flag){

        return;
    }

    if(x > n){

        res++;
        if(res == k + 1){

            flag = true;
            for(int i = 1; i <= n; i++){

                printf("%d ",ans[i]);
            }
            printf("\n");
        }
        return;
    }
    for(int i = 1; i <= n; i++){

        if(!res){
            
            i = numbers[x];
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

    scanf("%d %d",&n,&k);

    for(int i = 1; i <= n; i++){

        scanf("%d",&numbers[i]);
    }

    dfs(1);

    return 0;
}