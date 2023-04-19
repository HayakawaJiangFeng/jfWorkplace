#include <iostream>

//类模版与函数模版区别
//类模版没有主动类型推导的使用方式
//类模版中模版参数中可以有默认参数

template <typename nameType, typename ageType = int>
class Person{

public :

    nameType name;
    ageType age;

    Person(nameType name, ageType age){

        this->name = name;
        this->age  = age;
    }
    void showInfo(){

        std::cout << name << " " << age << std::endl;
    }
};

int main(){

    //Person p1("jiang",18);
    Person<std::string,int> p1("jiang",18);
    p1.showInfo();

    Person<std::string> p2("luna",16);
    p2.showInfo();

    return 0;
}