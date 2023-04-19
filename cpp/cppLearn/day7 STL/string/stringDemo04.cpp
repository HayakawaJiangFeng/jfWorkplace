#include <iostream>

int main(){

    std::string str1 = "jiangfeng";
    int pos = str1.find("feng");
    std::cout << pos << std::endl;
    int pos1 = str1.find("luna");
    std::cout << pos1 << std::endl;

    std::string str2 = "jiangfeng";
    str2.replace(5,4,"luna");
    std::cout << str2 << std::endl;

    return 0;
}