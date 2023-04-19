#include <iostream>

int N,M;
int highest;
int trees[1000010];

bool check(int mid){

    int sum = 0;
    for(int i = 1; i < N + 1; i++){

        sum += std::max(0, trees[i] - mid);

        if(sum >= M){ // 如果sum >= M了，说明高度太低了，得升高一点

            return true;
        }
    }
    return false;
}
int main(){

    std::cin >> N >> M;

    for(int i = 1; i <= N; i++){

        std::cin >> trees[i];
        highest = std::max(highest, trees[i]);
    }
    
    int left = 0;
    int right = highest;

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
    }else{

        std::cout << left << std::endl;
    }

    return 0;
}
