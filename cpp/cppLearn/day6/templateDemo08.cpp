#include <iostream>

//类模版实例化出的对象，向函数传参的方式
//三种方式
//1.指定传入的类型 --直接显示对象的数据结构
//2.参数模版化 --将对象中的参数变为模版进行传递
//3.整个类模版化 --将这个对象类型模版化进行传递

template <typename nameType, typename ageType>
class Person{

public:
    
    nameType name;
    ageType  age;

    Person(nameType name, ageType age){

        this->name = name;
        this->age  = age;
    }

    void printf(){

        std::cout << name << " " << age << std::endl;
    }
};

//指定传入类型
void printfPerson1(Person<std::string , int>& p){

    p.printf();
}

//参数模版化
template<typename T1,typename T2>
void printfPerson2(Person<T1,T2>& p){

    p.printf();
}

//整个类模版化
template<typename T>
void printfPerson3(T& p){

    p.printf();
}

int main(){

    Person<std::string, int> p1("jiangfeng",18);
    printfPerson1(p1);
    printfPerson2(p1);
    printfPerson3(p1);

    return 0;
}