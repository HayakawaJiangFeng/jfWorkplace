#include <iostream>

int n;
int number(int x){

    if(x == n){

        return 1;
    }else{

        return (number(x + 1) + 1) * 2;
    }
}
int main(){

    std::cin >> n;
    std::cout << number(1) << std::endl;
    return 0;
}