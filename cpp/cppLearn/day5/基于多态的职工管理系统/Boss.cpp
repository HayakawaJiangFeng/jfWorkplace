#include "Boss.h"

Boss::Boss(std::string name, int id, int wdtId){

    this->name = name;
    this->id   = id;
    this->wdtId = wdtId;
}

void Boss::showInfo(){

    std::cout << "worker id   = " << id;
    std::cout << "\t\tworker name = " << name;
    std::cout << "\t\tworker wdtId = " << wdtId;
    std::cout << "\t\tworker department name = " << getWdtName() << std::endl;
}
Boss::~Boss(){

}
std::string Boss::getWdtName(){

    return (std::string)"老板";
}