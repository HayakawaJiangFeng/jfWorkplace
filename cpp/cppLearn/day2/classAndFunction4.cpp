#include <iostream>

//拷贝构造函数 浅拷贝带来的问题
class Person{

    public:
        Person(){

            std::cout << "默认无参构造函数" << std::endl;
        }
        Person(int age, int id){

            person_age = age;
            person_id  = new int(id);
        }
        //加入深拷贝
        //如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝的带来的问题
        Person(const Person &p){

            person_age = p.person_age;
            person_id  = new int(*p.person_id);
        }
        ~Person(){
            
            if(person_id != nullptr){

                delete person_id;
                person_id = nullptr;
            }
            std::cout << "析构函数" << std::endl;
        }
        int person_age;
        int* person_id;
};

int main(){

    Person p1(19, 2002);

    std::cout << "p1 age = " << p1.person_age << std::endl;
    std::cout << "p1 id  = " << *(p1.person_id) << std::endl;

    Person p2(p1);

    std::cout << "p2 age = " << p2.person_age << std::endl;
    std::cout << "p2 id  = " << *(p2.person_id) << std::endl;
    
    return 0;
}