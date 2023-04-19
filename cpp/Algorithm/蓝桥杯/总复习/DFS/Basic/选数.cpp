#include <iostream>

int n,k;
int cnt;
int ans[25];
int values[25];

bool is_prime(int x){

    if(x < 2){

        return false;
    }
    for(int i = 2; i <= x / i; i++){

        if(x % i == 0){

            return false;
        }
    }
    return true;
}
void dfs(int x, int start){

    if(x > k){

        int sum = 0;
        for(int i = 1; i <= k; i++){

            sum += ans[i];
        }
        if(is_prime(sum)){

            cnt++;
        }
        return;
    }
    for(int i = start; i <= n; i++){
        
        ans[x]   = values[i];
        dfs(x + 1, i + 1);
        ans[x]   = 0;
    }
}

int main(){

    std::cin >> n >> k;
    for(int i = 1; i <= n; i++){

        std::cin >> values[i];
    }
    dfs(1,1);
    std::cout << cnt << std::endl;

    return 0;
}