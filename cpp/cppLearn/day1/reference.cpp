#include <iostream>

//引用作为函数返回值，可以作为左值
//引用作为函数返回值，不能返回局部变量
int& fun1(){

    static int num1 = 10;
    return num1;
}

int main(){

    int ref = fun1();
    std::cout << ref << std::endl;
    std::cout << ref << std::endl;

    fun1() = 20;
    std::cout << fun1() << std::endl;
    std::cout << fun1() << std::endl;

    //引用的本质,int* const refNum1 = &num1
    int num1 = 10;
    int &refNum1 = num1;
    std::cout << refNum1 << std::endl;
    //*refNum1 = 30
    refNum1 = 30;
    std::cout << num1 << std::endl;

    int num2 = 1;
    int* const refNum2 = &num2;
    std::cout << *refNum2 << std::endl;

    *refNum2 = 2;
    std::cout << num2 << std::endl;

    return 0;
}