#include <iostream>

//类模版与继承
//当子类继承的父类是一个类模版时，子类在声明的时候，要指出父类中T的类型
//如果不指定，编译器无法给子类分配内存
//如果想灵活指定出父类中的T类型，子类也需要变为类模版

template<typename T>
class Person{

public:

    T x;
};

//指定父类中的T类型
class Student : public Person<int>{

public:

    Student(){

    }
};

//子类也变成类模版
template<typename T>
class Teacher : public Person<T>{

public:

    Teacher(){

        std::cout << typeid(T).name() << std::endl;
    }
};

int main(){

    Student s;
    Teacher<std::string> t;

    return 0;
}