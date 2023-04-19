#include <iostream>
#include <vector>

int main(){

    std::vector<std::vector<int> > v1(9, std::vector<int>());
    
    for(int i = 0; i < 9; i++){

        for(int j = 0; j <= i; j++){

            v1[i].push_back((i+1) * (j+1));
        }
    }
    for(int i = 0; i < 9; i++){

        for(int j = 0; j < v1[i].size(); j++){

            std::cout << i + 1 << " * " << j + 1 << " = " << v1[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    return 0;
}