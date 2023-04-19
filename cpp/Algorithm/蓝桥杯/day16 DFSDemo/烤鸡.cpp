#include <iostream>

int n;
int ans[100];
int function[59055][20];
int sum;
int res;

void dfs(int x, int sum){

    if(sum > n){

        return;
    }

    if(x > 10){

        if(sum == n){

            res++;
            for(int i = 1; i <= 10; i++){
                
                function[res][i] = ans[i];
            }
        }

        return;
    }

    for(int i = 1; i <= 3; i++){

        ans[x] = i;
        dfs(x + 1, sum + i);
        ans[x] = 0;
    }
}

int main(){

    scanf("%d",&n);
    
    dfs(1,0);
    printf("%d\n",res);

    for(int i = 1; i <= res; i++){

        for(int j = 1; j <= 10; j++){

            printf("%d ",function[i][j]);
        }
        printf("\n");
    }

    return 0;
}