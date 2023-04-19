#include <iostream>

int main(){

    std::string str1 = "jiang";
    str1 += "feng";
    str1 += str1;
    std::cout << str1 << std::endl;

    std::string str2 = "lu";
    str2.append("na");
    str2.append(str2);
    std::cout << str2 << std::endl;

    std::string str3 = "i";
    str3.append("loveU",4);
    std::cout << str3 << std::endl;

    std::string str4 = "jiangfeng";
    str4.append("UlunaA",1,4);
    std::cout << str4 << std::endl;

    return 0;
}