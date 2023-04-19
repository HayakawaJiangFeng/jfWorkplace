#include <iostream>

//重载 == 和 !=

class Person{

    public:

        Person(){

        }
        Person(int age , std::string name){

            this->age = age;
            this->name = name;
        }
        int age;
        std::string name;

        bool operator==(Person p){

            if(age == p.age && name == p.name){

                return true;
            }else{

                return false;
            }
        }
        bool operator!=(Person p){

            if(age == p.age && name == p.name){

                return false;
            }else{

                return true;
            }
        }
};

int main(){

    Person p1(18,"luna");
    Person p2(18,"luna");
    Person p3(19,"feng");

    if(p1 == p2){
        
        std::cout << "p1 == p2" << std::endl;
    }else{

        std::cout << "p1 != p2" << std::endl;
    }

    if(p1 != p3){

        std::cout << "p1 != p3" << std::endl;
    }else{

        std::cout << "p1 == p3" << std::endl;
    }
    return 0;
}