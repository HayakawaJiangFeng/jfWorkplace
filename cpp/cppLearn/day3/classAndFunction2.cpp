#include <iostream>

//左移运算符重载
class Person{

    //将全局函数添加为该类的友元
    friend std::ostream& operator<< (std::ostream &cout , Person p);
    public :
        Person(int age, int id);
    private:

        int person_age;
        int person_id;
};
Person::Person(int age,int id) : person_age(age) , person_id(id){

}

//全局函数重载左移运算符
std::ostream& operator<< (std::ostream &cout , Person p){

    std::cout << p.person_age << std::endl;
    std::cout << p.person_id << std::endl;

    return std::cout;
}

int main(){

    Person p1(18,2002);
    Person p2(19,2001);
    std::cout << p1 << p2;

    return 0;
}