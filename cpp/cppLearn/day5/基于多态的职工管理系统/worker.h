#pragma once
#include <iostream>

class Worker{

public :

    virtual ~Worker(){

    }
    //show worker information
    virtual void showInfo() = 0;

    //get worker department name
    virtual std::string getWdtName() = 0;

    //name
    std::string name;

    //worker id
    int id;

    //worker department id
    int wdtId;
};