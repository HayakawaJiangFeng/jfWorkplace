#include <iostream>

//函数调用重载
class MyAdd{

    public:

        int operator()(int num1,int num2){

            return num1 + num2;
        }
};

class MyPrint{

    public:

        void operator()(std::string str){

            std::cout << str << std::endl;
        }
};

int main(){

    MyAdd add;
    int result = add(3,4);
    std::cout << result << std::endl;

    MyPrint print;
    print("jiangfeng");

    return 0;
}