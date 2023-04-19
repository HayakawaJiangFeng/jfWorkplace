#include <iostream>

//重载=号运算符

class Person{

    public :

        Person(){

        };
        Person(int age){

            person_age = new int(age);
        };
        Person(const Person& p){

            this->person_age = new int(*p.person_age);
        }
        ~Person(){

            if(person_age != nullptr){

                delete person_age;
                person_age = nullptr;
            }
        }
        int* person_age;

        Person& operator=(Person p){

            //浅拷贝
            //this->person_age = p.person_age;

            //深拷贝
            if(person_age != nullptr){

                delete person_age;
                person_age = nullptr;
            }
            person_age = new int(*p.person_age);

            return *this;
        }
};

int main(){

    Person p1(18);
    Person p2(20);
    Person p3(30);
    p3 = p2 = p1;

    std::cout << *(p2.person_age) << std::endl;
    std::cout << *(p3.person_age) << std::endl;
    
    return 0;
}