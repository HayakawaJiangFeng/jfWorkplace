#include <iostream>

class MyAdd
{
public : 

    int operator()(int num1, int num2)
    {
        return num1 + num2;
    }
};

class MyPrint
{
public :

    MyPrint()
    {
        this->count = 0;
    }

    void operator()(std::string str)
    {
        this->count++;
        std::cout << str << std::endl;
    }
    
    int count;
};

//创建函数对象，函数对象类似函数
void test()
{
    MyAdd myAdd;
    std::cout << myAdd(20,10) << std::endl;
}

//函数对象可以有自己的状态
void test01()
{
    MyPrint myPrint;
    myPrint("Hello,World");
    myPrint("Hello,World");
    myPrint("Hello,World");
    myPrint("Hello,World");
    myPrint("Hello,World");

    std::cout << myPrint.count << std::endl;
}

//函数对象可以作为参数传递
void doPrint(MyPrint &myPrint, std::string str)
{
    myPrint(str);
}
void test03()
{
    MyPrint mp;
    doPrint(mp, "Hello,Cpp");
}

int main()
{
    // test();
    // test01();
    test03();
    return 0;
}