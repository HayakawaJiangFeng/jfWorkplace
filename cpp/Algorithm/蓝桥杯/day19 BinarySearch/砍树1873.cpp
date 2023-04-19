/*
4 7
20 15 10 17

15

5 20
4 42 40 26 46

36
*/

#include <iostream>

int N,M;
int highest;
int sum;
int res;
int numbers[1000005];

int main(){

    std::cin >> N >> M;

    for(int i = 0; i < N; i++){

        std::cin >> numbers[i];
        highest = std::max(numbers[i], highest);
    }


    for(int i = 1; i <= highest; i++){

        sum = 0;
        for(int j = 0; j < N; j++){

            sum += std::max(0, numbers[j] - i);
            if(sum >= M){

                res = std::max(i, res);
                continue;
            }
        }
    }
    std::cout << res << std::endl;

    return 0;
}