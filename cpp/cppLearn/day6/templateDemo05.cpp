#include <iostream>

class Person{

public:

    Person(int age, std::string name) : person_age(age),person_name(name){

    }

    int person_age;
    std::string person_name;
};
template <typename T>
bool myCompare(T& x, T& y){

    if(x == y){

        return true;
    }else{

        return false;
    }
}

//具体化
template<> bool myCompare(Person& p1, Person& p2){

    if(p1.person_age == p2.person_age && p1.person_name == p2.person_name){

        return true;
    }else{

        return false;
    }
}
int main(){

    int x = 10;
    int y = 20;

    if(myCompare(x,y)){

        std::cout << "==" << std::endl;
    }else{

        std::cout << "!=" << std::endl;
    }

    Person p1(18,"jiangfeng");
    Person p2(16,"luna");

    
    if(myCompare(p1,p2)){

        std::cout << "==" << std::endl;
    }else{

        std::cout << "!=" << std::endl;
    }

    return 0;
}