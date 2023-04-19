#include <algorithm>
#include <iostream>

struct Student{

    int id;
    int score;
};

bool cmp(Student x, Student y){

    return x.score > y.score;
}

Student students[105];

int main(){

    int num;
    std::cin >> num;

    for(int i = 0; i < num; i++){

        students[i].id = i + 1;
        std::cin >> students[i].score;
    }
    std::sort(students,students + num, cmp);

    for(int i = 0; i < num; i++){

        if(i != num - 1){

            std::cout << students[i].id << " "; 
        }else{

            std::cout << students[i].id << std::endl;
        }
    }

    return 0;
}