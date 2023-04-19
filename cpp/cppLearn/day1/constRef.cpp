#include <iostream>

//常量引用，防止误操作
void print(const int& number){

    //number = 1000;
    std::cout << number << std::endl;
}
int main(){

    int number = 100;
    print(number);

    return 0;   
}