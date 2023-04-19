#include "Employee.h"

Employee::Employee(std::string name, int id, int wdtId){

    this->name = name;
    this->id   = id;
    this->wdtId = wdtId;
}
Employee::~Employee(){

}
void Employee::showInfo(){

    std::cout << "worker id   = " << id;
    std::cout << "\t\tworker name = " << name;
    std::cout << "\t\tworker wdtId = " << wdtId;
    std::cout << "\t\tworker department name = " << getWdtName() << std::endl;
}

std::string Employee::getWdtName(){

    return (std::string)"员工";
}