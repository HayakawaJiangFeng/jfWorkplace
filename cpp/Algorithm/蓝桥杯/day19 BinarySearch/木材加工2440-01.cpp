#include <iostream>

int n,k;
int longest;
int numbers[100010];

bool check(int mid){

    int sum = 0;

    for(int i = 0; i < n; i++){

        sum += numbers[i] / mid;

        if(sum >= k){

            return true;
        }
    }
    return false;
}
int main(){

    std::cin >> n >> k;

    for(int i = 0; i < n; i++){

        std::cin >> numbers[i];
        longest = std::max(longest, numbers[i]);
    }

    int left = 0;
    int right = longest;

    while (left + 1 < right)
    {
         
         int mid = (left + right) / 2;
         if(check(mid)){

            left = mid;
         }else{

            right = mid;
         }
    }
    
    if(check(right)){

        std::cout << right << std::endl;
    }
    else{

        std::cout << left << std::endl;
    }

    return 0;
}