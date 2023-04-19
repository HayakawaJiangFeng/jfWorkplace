#include <iostream>

//菱形继承
class Person{

    public :

        int age;
};

class JiangFeng : virtual public Person{

};

class Hina : virtual public Person{

};

class Kid : public JiangFeng, public Hina{

};

void lol(){

    Kid kid;
    kid.JiangFeng::age = 19;
    std::cout << kid.JiangFeng::age << std::endl;
    std::cout << kid.Hina::age << std::endl;
    std::cout << kid.age << std::endl;
}

int main(){

    lol();

    return 0;
}
