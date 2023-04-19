#include <iostream>
#include <set>

class Person{

public :

    Person(std::string name, int age){

        this->name = name;
        this->age  = age;
    }
    std::string name;
    int age;
};

class personCompare{

public :

    bool operator()(const Person p1, const Person p2){

        return p1.age > p2.age;
    }
};

class MyCompare{

public:

    bool operator()(int x, int y){

        return x > y;
    }
};

void printSet(const std::set<int, MyCompare> s1){

    for(std::set<int,MyCompare>::iterator it = s1.begin(); it != s1.end(); it++){

        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
int main(){

    std::set<int,MyCompare> s1;
    for(int i = 0; i < 10; i++){

        s1.insert(i);
    }
    printSet(s1);

    std::set<Person,personCompare> s2;
    s2.insert(Person("jf",17));
    s2.insert(Person("cy",1));
    s2.insert(Person("fd",3));

    for(std::set<Person,personCompare>::iterator it = s2.begin(); it != s2.end(); it++){

        std::cout << it->name << " " << it->age << std::endl;
    }
    return 0;
}