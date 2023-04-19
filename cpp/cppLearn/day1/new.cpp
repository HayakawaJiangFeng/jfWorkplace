#include<iostream>

int* fun1(){

    return new int(10);
}
int* fun2(){

    return new int[10];
}
void test1(){

    int* pointer = fun1();
    std::cout << *pointer << std::endl;
    delete pointer;
}
void test2(){

    int* arrP = fun2();
    for(int i = 0; i < 10; i++){

        arrP[i] = 100 + i;
    }
    for(int i = 0; i < 10; i++){

        std::cout << arrP[i] << std::endl;
    }
    //释放数组内存
    delete[] arrP;
}
int main(){

    test1();
    test2();
    return 0;
}