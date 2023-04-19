#include <iostream>

//空指针访问成员函数
class Person{

    public:
        Person(){

            std::cout << "无参构造函数" << std::endl;
        }
        void call(){

            std::cout << "hello" << std::endl;
        }
        void visit(){
            
            if(this == nullptr){

                return;
            }
            std::cout << "person_age = " << person_age << std::endl;
        }
        int person_age;

};

int main(){

    Person* p = nullptr;
    p->call();
    p->visit();
    
    return 0;
}