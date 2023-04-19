#include <iostream>

int n;
long long values[5005];

int main(){

    std::cin >> n;

    values[1] = 1;
    values[2] = 2;

    for(int i = 3; i <= n; i++){

        values[i] = values[i - 1] + values[i - 2];
    }


    long long x1 = 1;
    long long x2 = 2;
    long long newNum = 0;
    for(long long i = 3; i <= n; i++){

        newNum = x1 + x2;
        x1 = x2;
        x2 = newNum;
    }
    std::cout << newNum << std::endl;
    std::cout << values[n] << std::endl;

    return 0;
}
