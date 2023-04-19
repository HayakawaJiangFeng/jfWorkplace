#pragma once
#include "worker.h"

class Manager : public Worker{

public : 

    Manager(std::string name, int id, int wdtId);
    ~Manager();

    void showInfo();
    std::string getWdtName();
};