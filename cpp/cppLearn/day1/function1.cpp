#include <iostream>

//函数形参可以有默认值
void function1(int num1,int num2 = 10){

    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
}
//占位参数
void function2(int num1, int){

    std::cout << "num1 = " << num1 << std::endl;
}
int main(){

    function1(10,20); // 10 20
    function1(10);    // 10 10
    function2(10,10);
    return 0;
}