#include <iostream>

//继承中处理同名成员

class Father{

    public:

        Father(){

            data = 10;
        }
        int data;

        void call(){

            std::cout << "i am father" << std::endl;
        }
};

class Son : public Father{

    public:

        Son(){

            data = 20;
        }
        int data;
        
        void call(){

            std::cout << "i am son" << std::endl;
        }
};

int main(){

    Son s1;
    std::cout << s1.data << std::endl;

    //访问父类的data
    std::cout << s1.Father::data << std::endl;

    s1.call();
    
    //访问父类的visit
    s1.Father::call();

    return 0;
}