#include <iostream>

//函数重载的三个条件
//1.作用域相同
//2.函数名字相同
//3.函数参数类型，个数或者顺序不一样

void function(int number){

    std::cout << number << std::endl;
}
void function(double number){

    std::cout << number << std::endl;
}
int main(){

    int number1 = 10;
    double number2 = 10;

    function(number1);
    function(number2);

    return 0;
}