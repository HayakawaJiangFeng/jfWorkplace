#include <iostream>

int fibonacci(int num){

    if(num == 1 || num == 2){

        return 1;
    }
    return fibonacci(num - 1) + fibonacci(num - 2);
}
int main(){

    int num;
    std::cin >> num;

    int result = fibonacci(num);

    std::cout << result << std::endl;
}