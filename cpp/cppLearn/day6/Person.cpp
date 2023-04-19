#include "Person.h"

template<typename nameType, typename ageType>
Person<nameType,ageType>::Person(nameType name, ageType age){

    this->name = name;
    this->age  = age;
}

template<typename nameType, typename ageType>
void Person<nameType,ageType>::showInfo(){

    std::cout << "name : " << name << "age : " << age << std::endl;
}