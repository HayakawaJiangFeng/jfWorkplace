#pragma once
#include <string>
#include <iostream>

class Gun
{
private : 
    int _bullet_count;
    std::string _type;

public :
    Gun(std::string _type, int _bullet_count)
    {
        this->_bullet_count = _bullet_count;
        this->_type = _type;
    }

    void addBullet(int bullet_num);
    bool shoot();
};