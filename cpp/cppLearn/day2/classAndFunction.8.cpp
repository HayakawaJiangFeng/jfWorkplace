#include <iostream>

//this的用法
class Person{

    public:
        Person(int age){

            this->age = age;
        }
        Person& addPersonAge(Person person){

            this->age += person.age;
            return *this;
        }
        int age;
};

int main(){

    Person p1(10);
    std::cout << p1.age << std::endl;

    Person p2(10);
    
    //链式编程思想
    p2.addPersonAge(p1).addPersonAge(p1).addPersonAge(p1);
    std::cout << p2.age << std::endl;
}