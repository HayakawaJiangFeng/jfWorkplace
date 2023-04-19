#include <iostream>

int main(){

    int result = 0;
    char str[105] = {};
    std::cin >> str;

    int strLen = std::strlen(str);

    for(int i = 0; i < strLen; i++){

        if(str[i] == 'A'){

            result++;
        }
    }
    std::cout << result;
    
    return 0;
}