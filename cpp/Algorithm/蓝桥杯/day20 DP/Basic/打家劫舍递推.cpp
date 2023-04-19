#include <iostream>

int n;
int values[105];
int f[105];

int main(){

    std::cin >> n;

    for(int i = 1; i <= n; i++){

        std::cin >> values[i];
    }


    for(int i = n; i >= 1; i--){

        f[i] = std::max(f[i + 1], f[i + 2] + values[i]);
    }
    std::cout << f[1] << std::endl;

    return 0;
}