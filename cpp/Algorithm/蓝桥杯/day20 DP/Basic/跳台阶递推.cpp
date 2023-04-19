#include <iostream>

int values[1005];
int n;

int main(){

    values[1] = 1;
    values[2] = 2;

    std::cin >> n;


    for(int i = 3; i <= n; i++){

        values[i] = values[i - 1] + values[i - 2];
    }

    std::cout << values[n] << std::endl;

    return 0;
}