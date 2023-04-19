#include <iostream>

//静态成员
class Person{
public:

    Person(){

    }

    Person(int age){

        person_age = age;
    }

    //静态函数只能访问静态变量
    static void visit(){

        std::cout << "Person age = " << person_age << std::endl;
    }
    //静态变量类内声明
    static int person_age;
};
//静态变量类外定义
int Person::person_age = 0;
int main(){

    std::cout << Person::person_age << std::endl;
    Person p1;
    std::cout << p1.person_age << std::endl;

    Person p2(18);
    std::cout << p2.person_age << std::endl;

    Person::visit();

    return 0;
}