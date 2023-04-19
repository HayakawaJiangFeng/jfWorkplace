#include <iostream>

//拷贝构造函数的使用

class Person{
public:
    Person(){

        std::cout << "无参构造函数被调用" << std::endl;
    }
    Person(const Person &p){

        std::cout << "拷贝构造函数被调用" << std::endl;
    }
    ~Person(){

        std::cout << "析构函数被调用" << std::endl;
    }
};

void function1(Person p){

    std::cout << "hello" << std::endl;
}
Person function2(){

    Person p;
    std::cout << "p4" << std::endl;

    return p;
}

int main(){

    //使用一个已经初始化的对象来初始化新的对象
    Person p1;
    Person p2(p1);

    //值传递的方式给函数参数传值   
    Person p3;
    function1(p3);

    //返回局部对象
    Person p4 = function2();

    return 0;
}