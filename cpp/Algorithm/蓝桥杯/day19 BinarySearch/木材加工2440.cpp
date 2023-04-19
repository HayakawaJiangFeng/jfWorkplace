#include <iostream>

int n,k;
int longest;
int res;
int trees[100010];

int main(){

    std::cin >> n >> k;
    
    for(int i = 0; i < n; i++){

        std::cin >> trees[i];
        longest = std::max(longest, trees[i]);
    }

    //暴力遍历
    int sum;
    for(int L = 1; L <= longest; L++){

        sum = 0;
        for(int i = 0; i < n; i++){

            sum += trees[i] / L;
            if(sum >= k){
                
                res = std::max(res,L);
                continue;
            }
        }
    }

    std::cout << res << std::endl;

    return 0;
}