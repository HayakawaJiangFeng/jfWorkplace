#include <iostream>
#include <algorithm>

struct Student{

    int s_no;
    std::string s_name;

    Student(){

    }
    Student(int no, std::string name) : s_no(no), s_name(name){

    } 
};

bool cmp_name(Student x, Student y){

    return x.s_name > y.s_name;
}
int main(){

    std::string name;
    int id;

    Student students[3] = {};
    for(int i = 0; i < 3; i++){

        std::cin >> name;
        std::cin >> id;
        Student student(id,name);
        students[i] = student;
    }
    for(int i = 0; i < 3; i++){

        std::cout << students[i].s_name << " " << students[i].s_no << std::endl;
    }

    std::sort(students,students + 3, cmp_name);
    for(int i = 0; i < 3; i++){

        std::cout << students[i].s_name << " " << students[i].s_no << std::endl;
    }

    return 0;
}