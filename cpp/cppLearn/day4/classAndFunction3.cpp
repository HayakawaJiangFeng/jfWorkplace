#include <iostream>

//纯虚函数和抽象类
//有纯虚函数的类叫做抽象类
//子类继承抽象类，必须实现抽象类的抽象方法，不然子类也变成抽象类
class Father{

public : 

    virtual ~Father(){

    }
    //纯虚函数的写法
    virtual void function() = 0;
};

class Son : public Father{

public:

    void function(){

        std::cout << "子类实现抽象类的抽象方法" << std::endl;
    }
};

int main(){

    //Father Father;
    //抽象类无法实例化对象

    Father* father = nullptr;
    father = new Son;

    father->function();
    delete father;

    return 0;
}