#pragma once
#include "worker.h"

class Employee : public Worker{

public :

    Employee(std::string name, int id, int wdtId);
    ~Employee();
    
    void showInfo();
    std::string getWdtName();
};

