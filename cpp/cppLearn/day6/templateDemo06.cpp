#include <iostream>

template <class nameType, class ageType>
class Person{

public:

    nameType name;
    ageType  age;

    Person(nameType name, ageType age){

        this->name = name;
        this-> age = age;
    }
};


int main(){

    Person<std::string,int> p1("jiangfeng",18);

    std::cout << p1.name << " " << p1.age << std::endl;
    return 0;
}