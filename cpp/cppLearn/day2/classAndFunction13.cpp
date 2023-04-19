#include <iostream>

//成员函数作为友元
class Teacher;
class Student{

    public:
        Student();
        Teacher* teacher;
        void visit();
};
class Teacher{

    friend void Student::visit();
    public:
        Teacher();
        std::string public_room;
    
    private:
        std::string private_room;
};
Teacher::Teacher(){

    public_room = "public_room";
    private_room = "private_room";
}
Student::Student(){

    teacher = new Teacher;
}
void Student::visit(){

    std::cout << teacher->public_room << std::endl;
    std::cout << teacher->private_room << std::endl;
}

int main(){

    Student student;
    student.visit();
    
    return 0;
}