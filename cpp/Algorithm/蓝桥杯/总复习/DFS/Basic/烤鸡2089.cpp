#include <iostream>

int n;
int cnt;
int ans[10005][15];
int temp[15];

void dfs(int x){

    if(x > 10){

        int sum = 0;
        for(int i = 1; i <= 10; i++){

            sum += temp[i];
        }
        if(sum > n || sum < n){
            
            return;
        }
        if(sum == n){

            cnt++;
            for(int i = 1; i <= 10; i++){

                ans[cnt][i] = temp[i];
            }
        }
        return;
    }
    for(int i = 1; i <= 3; i++){

        temp[x] = i;
        dfs(x + 1);
        temp[x] = 0;
    }
}
int main(){

    std::cin >> n;

    dfs(1);

    if(cnt == 0){

        std::cout << 0 << std::endl;
        return 0;
    }else{

        std::cout << cnt << std::endl;

        for(int i = 1; i <= cnt; i++){

            for(int j = 1; j <= 10; j++){

                std::cout << ans[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    
    return 0;
}