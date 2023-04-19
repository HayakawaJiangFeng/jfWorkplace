#include <iostream>

int N,M;
int hightest;
int numbers[1000005];

bool check(int x){

    int sum = 0;

    for(int i = 0; i < N; i++){

        sum += std::max(0, numbers[i] - x);
        if(sum >= M){

            return true;
        }
    }
    return false;
}
int main(){

    std::cin >> N >> M;

    for(int i = 0; i < N; i++){

        std::cin >> numbers[i];
        hightest = std::max(hightest,numbers[i]);
    }

    int left = 0;
    int right = hightest;

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