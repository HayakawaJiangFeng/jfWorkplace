#include <iostream>

//多态
class Person{

    public:

        virtual void call(){

            std::cout << "i am a person" << std::endl;
        }
};

class Teacher : public Person{

    public:

        void call(){

            std::cout << "i am a teacher" << std::endl;
        }
};

class Student : public Person{

    public:

        void call(){

            std::cout << "i am a student" << std::endl;
        }
};

void call(Person& person){

    person.call();
}

int main(){

    //如果Person类中的call函数不是虚函数，则都是输出person
    //Person类中call函数不是虚函数则是地址早绑定
    //Person类中call函数是虚函数则是地址晚绑定
    Teacher teacher;
    call(teacher);

    Student student;
    call(student);

    Person person;
    call(person);

    return 0;
}