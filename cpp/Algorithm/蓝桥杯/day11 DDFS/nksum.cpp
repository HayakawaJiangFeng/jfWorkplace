#include <iostream>

//从n个数中选k个数使得k个数的和为sum

int n,k,sum,ans;
int numbers[40];

void dfs(int i, int cnt, int s){

    if(i == n){

        if(cnt == k && s == sum){

            ans++;
        }
        return;
    }
    
    dfs(i + 1, cnt, s);
    dfs(i + 1, cnt + 1, s + numbers[i]);
}

int main(){

    std::cin >> n >> k >> sum;

    for(int i = 0; i < n; i++){

        std::cin >> numbers[i];
    }
    dfs(0,0,0);
    std::cout << ans << std::endl;
    return 0;
}