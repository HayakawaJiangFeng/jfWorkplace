#pragma once
#include <iostream>
#include <string>
#include "Gun.h"

class Soldier
{
private :
    std::string _soldier_name;
    Gun* _ptr_guns;

public :
    Soldier(std::string _soldier_name);
    void addGun(Gun* _ptr_guns);
    bool fire();
    void addBulletToGun(int bullet_num);
};