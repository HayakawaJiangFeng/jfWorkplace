#include "Gun.h"

void Gun::addBullet(int bullet_num)
{
    this->_bullet_count += bullet_num;
}

bool Gun::shoot()
{
    if(this->_bullet_count > 0)
    {
        this->_bullet_count --;
        return true;
    }
    else
    {
        std::cout << "empty!" << std::endl;
        return false;
    }
}
