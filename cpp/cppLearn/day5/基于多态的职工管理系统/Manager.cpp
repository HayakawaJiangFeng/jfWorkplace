#include "Manager.h"

Manager::Manager(std::string name, int id, int wdtId){

    this->name = name;
    this->id   = id;
    this->wdtId = wdtId;
}

Manager::~Manager(){

}
void Manager::showInfo(){

    std::cout << "worker id   = " << id;
    std::cout << "\t\tworker name = " << name;
    std::cout << "\t\tworker wdtId = " << wdtId;
    std::cout << "\t\tworker department name = " << getWdtName() << std::endl;
}

std::string Manager::getWdtName(){

    return (std::string)"经理";
}