#include <iostream>

int main(){

    char ch;
    std::cin >> ch;

    if(ch > 'A' && ch < 'Z'){

        for(int i = 1; i <= ch - 'A' + 1; i++){

            for(int j = 0; j < ch - 'A' + 1 - i; j++){

                std::cout << " ";
            }
            for(int j = 1; j <= i; j++){

                std::cout << (char)('A' + j - 1);
            }
            for(int j = i - 1; j >= 1; j--){

                std::cout << (char)('A' + j - 1);
            }
            std::cout << std::endl;
        }
    }else{

        for(int i = 1; i <= ch - '1' + 1; i++){

            for(int j = 0; j < ch - '1' + 1 - i; j++){

                std::cout << " ";
            }
            for(int j = 1; j <= i; j++){

                std::cout << (char)('1' + j - 1);
            }
            for(int j = i - 1; j >= 1; j--){

                std::cout << (char)('1' + j - 1);
            }
            std::cout << std::endl;
        }
    }
    
    return 0;
}