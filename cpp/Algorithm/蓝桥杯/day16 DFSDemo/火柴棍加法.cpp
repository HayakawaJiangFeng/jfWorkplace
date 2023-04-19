#include <iostream>

int n;
int res;
int ans[1010];
int stickNum[1010] = {6,2,5,5,4,5,6,3,7,6};

void dfs(int x, int sum){

    if(sum > n){
        
        return;
    }
    if(x > 3){

        if(ans[1] + ans[2] == ans[3] && sum == n){

            res++;
            for(int i = 1; i <= 3; i++){
                std::cout << ans[i] << " ";
            }
            std::cout << std::endl;
        }
        return;
    }
    for(int i = 0; i <= 1000; i++){

        ans[x] = i;
        dfs(x + 1, sum + stickNum[i]);
        ans[x] = 0;
    }
}

int main(){

    std::cin >> n;
    
    n -= 4;
    for(int i = 10; i <= 1000; i++){

        stickNum[i] = stickNum[i % 10] + stickNum[i / 10];
    }

    dfs(1,0);
    std::cout << res << std::endl;

    return 0;
}