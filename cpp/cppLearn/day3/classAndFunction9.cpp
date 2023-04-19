#include <iostream>

//继承中构造和析构的顺序

class Father{

    public:

        Father(){

            std::cout << "Father的构造函数" << std::endl;
        }
        ~Father(){

            std::cout << "Father的析构函数" << std::endl;
        }
};

class Son : public Father{

    public:

        Son(){

            std::cout << "Son的构造函数" << std::endl;
        }
        ~Son(){

            std::cout << "Son的析构函数" << std::endl;
        }
};

int main(){

    Son s1;

    return 0;
}