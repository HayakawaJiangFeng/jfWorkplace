#include <iostream>

//多态例子

//抽象类
class AbstractDrinking{

public :
    virtual ~AbstractDrinking(){

    }
    virtual void step1() = 0;
    virtual void step2() = 0;
    virtual void step3() = 0;
    virtual void step4() = 0;

    void make(){

        step1();
        step2();
        step3();
        step4();
    }
};

class MakeTea : public AbstractDrinking{

public:

    void step1(){

        std::cout << "煮矿泉水" << std::endl;
    }
    void step2(){

        std::cout << "放入茶叶" << std::endl;
    }
    void step3(){

        std::cout << "冲茶叶" << std::endl;
    }
    void step4(){

        std::cout << "加入柠檬" << std::endl;
    }
};
class MakeCoffee : public AbstractDrinking{

public:

    void step1(){

        std::cout << "煮矿泉水" << std::endl;
    }
    void step2(){

        std::cout << "放入coffee粉" << std::endl;
    }
    void step3(){

        std::cout << "冲coffee" << std::endl;
    }
    void step4(){

        std::cout << "加入牛奶" << std::endl;
    }
};

void makeDrinking(AbstractDrinking* drinking){

    drinking->make();
    delete drinking;
}

int main(){

    std::cout << "煮coffee" << std::endl;
    makeDrinking(new MakeCoffee);

    std::cout << std::endl;

    std::cout << "煮tea" << std::endl;
    makeDrinking(new MakeTea);

    return 0;
}