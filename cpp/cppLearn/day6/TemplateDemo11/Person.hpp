#include <iostream>

//类模版的分文件编写

template <typename nameType, typename ageType>
class Person{

public:

    nameType name;
    ageType  age;
    Person(nameType name, ageType age);
    void showInfo();
};

template<typename nameType, typename ageType>
Person<nameType,ageType>::Person(nameType name, ageType age){

    this->name = name;
    this->age  = age;
}

template<typename nameType, typename ageType>
void Person<nameType,ageType>::showInfo(){

    std::cout << "name : " << name << "age : " << age << std::endl;
}