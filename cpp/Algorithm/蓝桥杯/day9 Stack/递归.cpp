#include <iostream>


long long int factorial(int num){

    if(num <= 1){

        return 1;
    }
    return num * factorial(num - 1);
}
int main(){

    int num;
    std::cin >> num;   

    int res = factorial(num);

    std::cout << res << std::endl;
    return 0;
}