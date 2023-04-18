#include "Gun.h"
#include "Soldier.h"

void test()
{
    Soldier s1("jiangfeng");
    s1.addGun(new Gun("M4a1",0));
    s1.addBulletToGun(30);
    
    int cnt = 0;
    while (s1.fire())
    {
        std::cout << "shoot successfully : " << ++cnt << std::endl;
    }
}

int main()
{
    test();
    return 0;
}