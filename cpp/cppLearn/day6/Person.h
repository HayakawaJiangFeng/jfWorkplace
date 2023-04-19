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