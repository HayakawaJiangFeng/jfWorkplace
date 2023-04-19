#pragma once
#include "worker.h"

class Boss : public Worker{

public :

    Boss(std::string name, int id, int wdtId);
    ~Boss();
    void showInfo();
    std::string getWdtName();
};