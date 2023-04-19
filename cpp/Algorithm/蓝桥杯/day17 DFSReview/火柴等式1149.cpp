#include <iostream>

int n;
int sticks[1005] = {6,2,5,5,4,5,6,3,7,6};
int ans[4];
int res;

void dfs(int x, int cnt){

    if(cnt > n - 4){

        return;
    }
    if(x == 3){

        if(cnt == n - 4 && ans[0] + ans[1] == ans[2]){

            res++;
            for(int i = 0; i < 3; i++){
                std::cout << ans[i] << " ";
            }
            std::cout << std::endl;
        }
        return;
    }
    for(int i = 0; i < 1000; i++){

        ans[x] = i;
        dfs(x + 1, cnt + sticks[i]);
        ans[x] = 0;
    }
}

int main(){

    std::cin >> n;

    for(int i = 10 ; i < 1000; i++){

        sticks[i] = sticks[i / 10] + sticks[i % 10];
    }
    dfs(0,0);
    std::cout << res << std::endl;

    return 0;
}