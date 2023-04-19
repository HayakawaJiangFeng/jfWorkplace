#include <iostream>

//虚析构和纯虚析构
//解决父类指针释放子类对象
//都需要具体的函数实现

class Person{

public :
    
    Person(){

        std::cout << "Person构造函数" << std::endl;
    }

    //父类的析构函数不加virtual，子类的析构函数不会执行
    virtual ~Person(){

        std::cout << "Person虚析构函数" << std::endl;
    }
    //纯虚析构函数
    //virtual ~Person() = 0;
    virtual void call() = 0;
};

//纯虚析构函数需要在类外实现
/*Person::~Person(){

    std::cout << "Person纯虚析构函数" << std::endl;
}*/

class Student : public Person{

public :

    Student(std::string name){

        this->name = new std::string(name);
        std::cout << "Student构造函数" << std::endl;
    }
    ~Student(){

        if(name != nullptr){

            delete name;
            name = nullptr;
        }
        std::cout << "Student析构函数" << std::endl;
    }
    void call(){

        std::cout << "i am " << *name << std::endl;
    }
    std::string* name;
};

void test(){

    Person* p1 = new Student("JiangFeng");
    p1->call();
    delete p1;
}
int main(){

    test();
    return 0;
}