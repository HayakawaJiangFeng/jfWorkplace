#include <iostream>

int array[205][205];

int main(){

    int row, column;
    std::cin >> row >> column;

    for(int i = 0; i < row; i++){

        for(int j = 0; j < column; j++){

            std::cin >> array[i][j];
        }
    }
    
    for(int i = 0; i < row; i++){

        for(int j = 0; j < column; j++){

            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for(int i = 0; i < column; i++){

        for(int j = 0; j < row; j++){

            std::cout << array[row - 1 - j][i] << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}