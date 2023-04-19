#include <iostream>

int main(){

    std::string str1;
    str1 = "hello string";
    std::cout << str1 << std::endl;

    std::string str2 = str1;
    std::cout << str1 << std::endl;

    std::string str3;
    str3 = "A";
    std::cout << str3 << std::endl;

    std::string str4;
    str4.assign("hello string");
    std::cout << str4 << std::endl;

    std::string str5;
    str5.assign("hello",5);
    std::cout << str5 << std::endl;

    std::string str6;
    str6.assign(str5);
    std::cout << str6 << std::endl;

    std::string str7;
    str7.assign(7,'A');
    std::cout << str7 << std::endl;

    return 0;
}