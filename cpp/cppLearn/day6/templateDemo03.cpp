#include <iostream>

//普通函数和函数模版的区别

void myAdd(int num1, int num2){

    std::cout << num1 + num2 << std::endl;
}

template <typename T>
void myAdd1(T num1, T num2){

    std::cout << num1 + num2 << std::endl;
}

void test01(){

    int num1 = 10;
    int num2 = 20;
    char num3 = 'A';

    myAdd(num1,num2);

    //自动类型转换
    myAdd(num1,num3);

    //myAdd1(num1,num3);自动类型推导不会自动类型转换
    myAdd1<int>(num1,num3);
}

int main(){

    test01();
    return 0;
}