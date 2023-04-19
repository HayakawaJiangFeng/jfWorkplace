#include <iostream>

//常函数
class Person{

    public:

        Person(int age, int id){

            this->age = age;
            this->id  = id;
        }
        int age;
        //特殊变量，即使在常函数中也可以修改改值，加上关键字mutable即可
        mutable int id;
        
        //this的本质是指针常量，不可以修改指针的指向
        //在成员函数后面加上const，修饰的是this的指向，让指针指向的值也不可以修改
        void visit() const {   

            //age = 100;
            id  = 10;
            std::cout << "age = " << age << std::endl;
            std::cout << "id  = " << age << std::endl;
        }
};

int main(){

    Person p(18,2002);
    std::cout << p.age << std::endl;
    std::cout << p.id  << std::endl;

    p.visit();
    std::cout << p.age << std::endl;
    std::cout << p.id  << std::endl;

    //const 变常对象
    //常对象中的成员不可以被修改，除了mutable的特殊成员变量
    //常对象只可以调用常函数
    const Person p1(10,10);
    p1.id  = 5;
    std::cout << p1.age << std::endl;
    std::cout << p1.id  << std::endl;

    return 0;
}
