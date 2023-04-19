#include <iostream>

//类作为友元
class Teacher{

friend class Student;
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

class Student{

    public:

        Student();
        void visit();
        Teacher* teacher;
};
Student::Student(){

    teacher = new Teacher;
}
void Student::visit(){

    std::cout << teacher->public_room << std::endl;
    std::cout << teacher->private_room << std::endl;
}
int main(){

    //Teacher teacher1;
    //std::cout << teacher1.public_room << std::endl;
    Student student;
    student.visit();
    
    return 0;
} 