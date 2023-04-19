#include <iostream>

//重载前置递增和后置递增

class Person{

    friend std::ostream& operator<< (std::ostream& cout , Person p);
    public:

        Person(){

        }

        Person(int age){

            person_age = age;
        }

        //重载前置自增
        Person& operator++(){

            ++person_age;

            return *this;
        }

        //重载后置自增,后置自增在括号内加int
        Person operator++(int){

            Person temp = *this;
            this->person_age++;
        
            return temp;
        }
    private:
        
        int person_age;
};

std::ostream& operator<< (std::ostream& cout, Person p){

    std::cout << p.person_age << std::endl;
    return cout;
}

int main(){

    Person p(18);
    std::cout << p << std::endl;

    Person p1(17);
    std::cout << ++p1 << std::endl;

    Person p2(17);
    std::cout << p2++ << std::endl;
    std::cout << p2 << std::endl;

    return 0;
}