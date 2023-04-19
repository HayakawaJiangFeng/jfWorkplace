#include <iostream>

int n,k;
int dfs[17];

int main(){

    std::cin >> n >> k;
    for(int i = 0; i <= n; i++){

        if(i < k){

            dfs[i] = 1;
        }else{

            dfs[i] = dfs[i - 1] + dfs[i - k];
        }
    }
    std::cout << dfs[n] << std::endl;

    return 0;
}