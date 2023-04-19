#include <iostream>
#include <algorithm>

struct Student{

    char name[105];
    int score[4];
};

Student students[105];

bool cmp1(Student x, Student y){

    if(x.score[0] != y.score[0]){

        return x.score[0] > y.score[0];
    }else{

        return strcmp(x.name , y.name) < 0;
    }
}
bool cmp2(Student x, Student y){

    if(x.score[1] != y.score[1]){

        return x.score[1] > y.score[1];
    }else{

        return strcmp(x.name , y.name) < 0;
    }
}
bool cmp3(Student x, Student y){

    if(x.score[2] != y.score[2]){

        return x.score[2] > y.score[2];
    }else{

        return strcmp(x.name , y.name) < 0;
    }
}
bool cmp4(Student x, Student y){

    if(x.score[3] != y.score[3]){

        return x.score[3] > y.score[3];
    }else{

        return strcmp(x.name , y.name) < 0;
    }
}
bool cmp5(Student x, Student y){

    int sumX = 0, sumY = 0;
    for(int i = 0; i < 4; i++){

        sumX += x.score[i];
        sumY += y.score[i];
    }
    if(sumX != sumY){

        return sumX > sumY;
    }else{

        return strcmp(x.name, y.name) < 0;
    }
}

void my_printf(){

    for(int i = 0; i < 3; i++){
        
        std::cout << students[i].name << " ";
    }
    std::cout << students[3].name  << std::endl;
}
int main(){

    int number;
    std::cin >> number;

    for(int i = 0; i < number; i++){

       std::cin >> students[i].name;
       std::cin >> students[i].score[0];
       std::cin >> students[i].score[1];
       std::cin >> students[i].score[2];
       std::cin >> students[i].score[3];
    }

    std::sort(students,students + number, cmp1);
    my_printf();

    std::sort(students,students + number, cmp2);
    my_printf();

    std::sort(students,students + number, cmp3);
    my_printf();

    std::sort(students,students + number, cmp4);
    my_printf();

    std::sort(students,students + number, cmp5);
    my_printf();

    return 0;
}