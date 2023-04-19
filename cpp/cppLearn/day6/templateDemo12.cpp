#include <iostream>

//类模版与友元
template<typename nameType, typename ageType>
class Person;

template<typename nameType, typename ageType>
void showInfo2(Person<nameType,ageType>& p){

    std::cout << "name : " << p.name <<  " " << "age : " << p.age << std::endl;
}

template<typename nameType, typename ageType>
class Person{

//全局函数类外实现
friend void showInfo2<>(Person<nameType, ageType>& p);

//全局函数类内实现
friend void showInfo(Person<nameType, ageType>& p){

    std::cout << "name : " << p.name << " " << "age : " << p.age << std::endl;
}
public:

    Person(nameType name, ageType age){

        this->name = name;
        this->age  = age;
    }
private:

    nameType name;
    ageType  age;
};

int main(){

    Person<std::string, int> p1("jiangfeng",18);
    showInfo(p1);
    showInfo2(p1);

    return 0;
}