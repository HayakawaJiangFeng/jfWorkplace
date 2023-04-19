#include <iostream>

int value[1000];
int dp[1000];
int n;

int main(){

    std::cin >> n;
    for(int i = 1; i <= n; i++){

        std::cin >> value[i];
    }

    int ans = 0;

    for(int i = n; i >= 1; i--){
        
        dp[i] = dp[i + value[i]] + 1;

        ans = std::max(ans,dp[i]);
    }

    std::cout << ans << std::endl;
    
    return 0;
}