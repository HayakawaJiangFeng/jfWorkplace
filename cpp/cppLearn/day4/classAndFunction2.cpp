#include <iostream>

//多态的使用

class Calculator{

public :
        
    virtual int calculator(){

        return 0;
    }
    int num1;
    int num2;
};

class Add : public Calculator{

public :

    int calculator(){

        return num1 + num2;
    }
};

class Sub : public Calculator{

public :

    int calculator(){

        return num1 - num2;
    }
};

class Mul : public Calculator{

public :
    
    int calculator(){
        
        return num1 * num2;
    }
};

class Div : public Calculator{

public : 

    int calculator(){

        return num1 / num2;
    }
};

void test(){

    int result;   

    //父类指针指向子类对象
    Calculator* c1 = new Add;
    c1->num1 = 10;
    c1->num2 = 7;
    result = c1->calculator();

    std::cout << "add = " << result << std::endl;
    delete c1;


    c1 = new Sub;
    c1->num1 = 10;
    c1->num2 = 7;
    result = c1->calculator();

    std::cout << "sub = " << result << std::endl;
    delete c1;
    
    c1 = new Mul;
    c1->num1 = 10;
    c1->num2 = 7;
    result = c1->calculator();

    std::cout << "mul = " << result << std::endl;
    delete c1;

    c1 = new Div;
    c1->num1 = 10;
    c1->num2 = 7;
    result = c1->calculator();
    
    std::cout << "div = " << result << std::endl;
    delete c1;
}

int main(){

    test();

    return 0;   
}