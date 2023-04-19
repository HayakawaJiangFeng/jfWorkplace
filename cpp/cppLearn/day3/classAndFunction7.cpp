#include <iostream>

//类的继承
class Person{

    public:

        Person(){
            
        }
        Person(std::string name, int age){

            this->name = name;
            this->age  = age;
        }
        std::string name;
        int age;
};

class Student : public Person{

    public:

        Student(){

        }
        Student(int id){

            this->id = id;
        }
        int id;
};

int main(){

    Student s1;
    s1.name = "jiangfeng";
    s1.age  = 18;
    s1.id   = 2002;

    std::cout << s1.name << std::endl << s1.age << std::endl << s1.id << std::endl;

    return 0;
}