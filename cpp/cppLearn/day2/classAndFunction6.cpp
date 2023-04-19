#include <iostream>

//类对象作为类成员
class Student{

    public:

        Student(std::string name) : student_name(name){

            std::cout << "student有参构造函数" << std::endl;
        }
        ~Student(){

            std::cout << "student析构函数" << std::endl;
        }
    
        std::string student_name;
};

class Teacher{

    public:

        Teacher(std::string t_name, std::string s_name, int id) : teacher_name(t_name), student(s_name),teacher_id(id){

            std::cout << "teacher有参构造函数" << std::endl;
        }
        ~Teacher(){

            std::cout << "teacher析构函数" << std::endl;
        }
        std::string teacher_name;
        Student student;
        int teacher_id;
};

int main(){

    Teacher teacher("jiangfeng","luna",2002);

    return 0;
}
