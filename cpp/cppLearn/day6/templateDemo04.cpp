#include <iostream>

//如果函数模版和普通函数都可以实现，优先调用普通函数
//可以通过空模版参数列表来强制调用函数模版
//函数模版可以被重载
//如果函数模版可以产生更好的匹配优先调用函数模版

void myFunction(int num1,int num2){

    std::cout << "调用的是普通函数" << std::endl;
}

template <typename T>
void myFunction(T num1, T num2){

    std::cout << "调用的函数模版" << std::endl;
}

int main(){

    int num1 = 10;
    int num2 = 20;

    myFunction(num1,num2);   

    //通过空模版参数列表强制调用函数模版
    myFunction<>(num1,num2);

    //函数模版更好匹配优先调用函数模版
    char num3 = 'A';
    char num4 = 'B';
    myFunction(num3,num4);

    return 0;
}