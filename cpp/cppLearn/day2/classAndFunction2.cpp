#include <iostream>

//构造函数的分类与构造函数的调用
//如果自己写了有参构造函数，则编译器不再提供默认的无参构造函数，但依旧会提供拷贝构造函数
//如果自己写了拷贝构造函数，则编译器不再提供默认的无参构造函数，也不提供有参构造函数
class Person{
public:
    //无参构造函数
    Person(){

        std::cout << "无参构造函数被调用" << std::endl;
    }

    //有参构造函数
    Person(int number){

        person_age = number;
        std::cout << "有参构造函数被调用" << std::endl;
    }

    //拷贝构造函数
    Person(const Person &p){

        person_age = p.person_age;
        std::cout << "拷贝构造函数被调用" << std::endl;
    }

    //析构函数
    ~Person(){

        std::cout << "析构函数被调用" << std::endl;
    }
    int person_age;
};

int main(){

    //调用构造函数的方式

    //括号法
    Person p1;
    Person p2(18);
    Person p3(p2);

    std::cout << p2.person_age << std::endl;
    std::cout << p3.person_age << std::endl;

    //隐式转换法
    Person p4 = 19;
    Person p5 = p4;
    std::cout << p4.person_age << std::endl;
    std::cout << p5.person_age << std::endl;

    //显示法
    Person p6 = Person(20);
    Person p7 = Person(p6);
    std::cout << p6.person_age << std::endl;
    std::cout << p7.person_age << std::endl;

}