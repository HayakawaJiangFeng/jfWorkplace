#include <iostream>

int main(){

    std::string str1 = "A";
    std::string str2 = "B";

    int cmp1 = str1.compare(str2);
    std::cout << cmp1 << std::endl;
    int cmp2 = str2.compare(str1);
    std::cout << cmp2 << std::endl;

    return 0;
}