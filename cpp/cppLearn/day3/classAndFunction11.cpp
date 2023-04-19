#include <iostream>

//继承中处理同名静态成员

class Father{

    public:

        static int data;

        static void call(){

            std::cout << "father call" << std::endl;
        }
};

int Father::data = 10;

class Son : public Father{

    public:

        static int data;

        static void call(){

            std::cout << "son call" << std::endl;
        }
};

int Son::data = 20;

int main(){

    //通过对象来调用静态成员
    Son son;
    std::cout << son.data << std::endl;
    std::cout << son.Father::data << std::endl;
    son.call();
    son.Father::call();

    //通过类名来调用静态成员
    std::cout << Son::data << std::endl;
    std::cout << Son::Father::data << std::endl;
    Son::call();
    Son::Father::call();

    return 0;
}