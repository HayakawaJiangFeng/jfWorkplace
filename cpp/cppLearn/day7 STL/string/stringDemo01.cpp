#include <iostream>

int main(){

    std::string s1;
    
    const char* s2 = "hello string";

    std::string s3(s2);
    
    std::string s4(10,'A');

    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;
    std::cout << s4 << std::endl;

    return 0;
}