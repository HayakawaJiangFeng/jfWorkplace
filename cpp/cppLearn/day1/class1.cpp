#include <iostream>

class Student{

    //public类内可以访问，类外可以访问，子类可以访问
    //protected类内可以访问，类外不可以访问，子类可以访问
    //private类内可以访问，类外不可以访问，子类不可以访问
    public:
        
        std::string student_name;
        int student_id;

        void set_name(std::string name){

            student_name = name;
        }
        void set_id(int id){

            student_id = id;
        }
};
int main(){

    Student s1;
    s1.set_id(1314);
    s1.set_name("luna");

    std::cout << s1.student_id << std::endl;
    std::cout << s1.student_name << std::endl;

    return 0;
}