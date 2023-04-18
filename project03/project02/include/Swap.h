#pragma once
#include <iostream>

class swap
{
public:
    swap(int num1, int num2)
    {
        this->num1 = num1;
        this->num2 = num2;
    }
    void run();
    void printInfo();

private:
    int num1;
    int num2;
};