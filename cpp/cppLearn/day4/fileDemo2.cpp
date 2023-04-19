#include <iostream>
#include <fstream>

//二进制写文件
//函数原型 ostream& write(const char* buffer, int len);
//字符指针buffer指向内存中一段存储空间，len是读写的字数

//二进制读文件
//函数原型 ostream& read(char* buffer, int len);
//字符指针buffer指向内存中一段存储空间，len是读写的字数

class Person{

public :

    Person(){
        
    }
    Person(std::string name, int age){

        this->name = name;
        this->age  = age;
    }

    std::string name;
    int age;
};

void test1(){

    std::ofstream ofs;
    ofs.open("Person.txt", std::ios::out | std::ios::binary);

    Person person("JiangFeng",19);

    ofs.write((const char*)& person, sizeof(Person));

    ofs.close();
}

void test2(){

    std::ifstream ifs;
    ifs.open("Person.txt", std::ios::in | std::ios::binary);

    if(!ifs.is_open()){

        std::cout << "无法打开文件" << std::endl;
    }

    Person person;
    ifs.read((char*) &person, sizeof(Person));

    std::cout << "Person name = " << person.name << std::endl;
    std::cout << "Person age = " << person.age << std::endl;

    ifs.close();
}
int main(){

    test1();
    test2();

    return 0;
}