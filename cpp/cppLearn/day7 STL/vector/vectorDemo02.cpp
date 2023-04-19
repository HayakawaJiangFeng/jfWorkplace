#include <iostream>
#include <vector>
#include <algorithm>

class Robot{

public:
    
    Robot(int id, std::string name){

        this->id   = id;
        this->name = name;
    }

    int id;
    std::string name;
};

void myPrint1(Robot robot){

    std::cout << robot.id << " ";
    std::cout << robot.name << std::endl;
}
void myPrint2(Robot* robot){

    std::cout << robot->id << " ";
    std::cout << robot->name << std::endl;
}
int main(){

    std::vector<Robot> v1;

    Robot r1(18,"jf");
    Robot r2(16,"luna");
    Robot r3(17,"melina");

    v1.push_back(r1);
    v1.push_back(r2);
    v1.push_back(r3);

    for(std::vector<Robot>::iterator it = v1.begin(); it != v1.end(); it++){

        std::cout << "name = " << it->id << std::endl;
        std::cout << "id   = " << it->name   << std::endl;
    }

    std::vector<Robot*> v2;
    v2.push_back(&r1);
    v2.push_back(&r2);
    v2.push_back(&r3);

    for(std::vector<Robot*>::iterator it = v2.begin(); it != v2.end(); it++){

        std::cout << "name = " << (*(*it)).name << std::endl;
        std::cout << "id   = " << (*(*it)).id   << std::endl;
    }

    std::for_each(v1.begin(),v1.end(),myPrint1);
    std::for_each(v2.begin(),v2.end(),myPrint2);

    return 0;
}