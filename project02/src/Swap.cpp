#include "Swap.h"

void swap::run()
{
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
}

void swap::printInfo()
{
    std::cout << "num1 = " << num1 << std::endl;
    std::cout << "num2 = " << num2 << std::endl;
}