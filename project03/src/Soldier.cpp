#include "Soldier.h"

Soldier::Soldier(std::string _soldier_name)
{
    this->_soldier_name = _soldier_name;
    this->_ptr_guns = nullptr;
}

void Soldier::addGun(Gun* _ptr_guns)
{
    this->_ptr_guns = _ptr_guns;
}

bool Soldier::fire()
{
    if(this->_ptr_guns == nullptr)
    {
        std::cout << "no guns!" << std::endl;
        return false;
    }
    if(!this->_ptr_guns->shoot())
    {
        return false;
    }
    return true;
}

void Soldier::addBulletToGun(int bullet_num)
{
    if(this->_ptr_guns == nullptr)
    {
        std::cout << "no gun!" << std::endl;
        return;
    }
    this->_ptr_guns->addBullet(bullet_num);
}