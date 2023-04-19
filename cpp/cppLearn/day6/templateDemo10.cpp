#include <iostream>

//类模版成员函数的类外实现
//成员函数类外实现时需要加上模版参数列表

template<typename nameType, typename ageType>
class Person{

public:

    nameType name;
    ageType  age;
    Person(nameType name, ageType age);
    void showInfo();
};

//构造函数类外实现
template<typename nameType,typename ageType>
Person<nameType,ageType>::Person(nameType name, ageType age){

    this->name = name;
    this->age  = age;
}

//成员函数类外实现
template<typename nameType,typename ageType>
void Person<nameType,ageType>::showInfo(){

    std::cout << "name : " << name << std::endl;
    std::cout << "age : " << age << std::endl; 
}

int main(){

    Person<std::string, int> p1("jiangfeng",18);
    p1.showInfo();

    return 0;
}