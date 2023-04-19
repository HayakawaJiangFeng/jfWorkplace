#include <iostream>

//多继承的用法
class Father1{

    public:

        Father1() : father_data(10) { 


        }
        int father_data;
};

class Father2{

    public:

        Father2() : father_data(20){


        }
        int father_data;
};

class Son : public Father1, public Father2{

    public:

        Son() : father_data(30){


        }
        int father_data;
};

int main(){

    Son s1;
    std::cout << s1.father_data << std::endl;
    std::cout << s1.Father1::father_data << std::endl;
    std::cout << s1.Father2::father_data << std::endl;

    return 0;
}