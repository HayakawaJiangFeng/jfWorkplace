#include <iostream>

//运算符重载
class Person{

    public:

        Person(){

        }
        Person(int age, int id) : person_age(age) , person_id(id){

        }
        int person_age;
        int person_id;

        //成员函数重载运算符
        Person operator+(Person p){

            Person temp;
            temp.person_age = this->person_age + p.person_age;
            temp.person_id  = this->person_id + p.person_id;

            return temp;
        }
};

//全局函数重载运算符
Person operator-(Person p1, Person p2){

    Person temp;
    temp.person_age = p1.person_age - p2.person_age;
    temp.person_id  = p1.person_id  - p2.person_id;

    return temp; 
}
int main(){

    Person p1(18,2002);
    std::cout << p1.person_age << std::endl;
    std::cout << p1.person_id << std::endl;

    Person p2(10,2002);
    std::cout << p2.person_age << std::endl;
    std::cout << p2.person_id  << std::endl;

    Person p3 = p1 + p2;
    std::cout << p3.person_age << std::endl;
    std::cout << p3.person_id  << std::endl;
    
    Person p4 = p1 - p2;
    std::cout << p4.person_age << std::endl;
    std::cout << p4.person_id << std::endl;
    return 0;
}