#include <iostream>

int numbers[100005];
const int mod = 1e+7;

int main(){

    numbers[1] = 1;
    numbers[2] = 1;
    
    int n = 0;
    std::cin >> n;

    for(int i = 3; i <= n; i++){

        numbers[i] = (numbers[i - 1] + numbers[i - 2]) % mod;
    }
    std::cout << numbers[n] << std::endl;
    return 0;
}