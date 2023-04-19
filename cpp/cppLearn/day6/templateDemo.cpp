#include <iostream>


template<typename T>
void mySwap(T& num1, T& num2){

    int temp = num1;
    num1 = num2;
    num2 = temp;
}

int main(){

    int num1 = 10;
    int num2 = 20;

    //显示类型推导
    mySwap<int>(num1,num2);
    std::cout << num1 << " " << num2 << std::endl;

    //自动类型推导
    mySwap(num1,num2);
    std::cout << num1 << " " << num2 << std::endl;

    return 0;
}