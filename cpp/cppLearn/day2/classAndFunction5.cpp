#include <iostream>

class Person1{

    public:
        Person1(int age, int height, int id){

            person_age = age;
            person_height = height;
            person_id = id;

            std::cout << "有参构造函数" << std::endl;
        }

        int person_age;
        int person_height;
        int person_id;
};

//初始化列表的使用
class Person2{

    public:
        Person2(int age, int height, int id) : person_age(age), person_height(height), person_id(id){

            std::cout << "有参构造函数" << std::endl;
        }

        int person_age;
        int person_height;
        int person_id;
};

int main(){

    Person1 p1(19,176,2002);
    std::cout << "p1.age = " << p1.person_age << std::endl;
    std::cout << "p1.height = " << p1.person_height << std::endl;
    std::cout << "p1.id = " << p1.person_id << std::endl;

    Person2 p2(20,177,2001);
    std::cout << "p2.age = " << p2.person_age << std::endl;
    std::cout << "p2.height = " << p2.person_height << std::endl;
    std::cout << "p2.id = " << p2.person_id << std::endl;

    return 0;
}