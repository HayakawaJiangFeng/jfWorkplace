#include <iostream>

class Person{

public:
    //构造函数
    //没有返回值，可以带形参，可以被重载
    //与类名一致，自动调用，且只运行一次
    Person(){

        std::cout << "构造函数被调用" << std::endl;
    }

    //析构函数
    //没有返回值，不可以带形参，可以被重载
    //与类名一致，自动调用，且只运行一次
    ~Person(){

        std::cout << "析构函数被调用" << std::endl;
    }
};

void test(){

    Person p;
}
int main(){

    test();
    return 0;
}