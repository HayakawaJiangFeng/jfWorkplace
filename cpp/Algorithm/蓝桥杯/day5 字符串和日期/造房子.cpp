#include <iostream>

int main(){

    //行
    int row = 0;
    std::cin >> row;
    //列
    int arrange = 0;
    std::cin >> arrange;

    for(int i = 1; i <= row; i++){

        for(int i = 1; i <= arrange; i++){

            std::cout << "+-";
        }
        std::cout << "+" << std::endl;
        
        for(int j = 1; j <= arrange; j++){

            std::cout << "|*";
        }
        std::cout << "|" << std::endl;;
    }
    for(int i = 1; i <= arrange; i++){

        std::cout << "+-";
    }
    std::cout << "+";
}