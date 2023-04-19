#include <iostream>
#include <vector>

int main(){

    std::vector<int> v1;
    for(int i = 0; i < 10; i++){

        v1.push_back(i);
    }
    for(int i = 0; i < 10; i++){

        std::cout << v1[i] << " ";
    }
    std::cout << std::endl;

    for(int i = 0; i< 10; i++){

        std::cout << v1.at(i) << " ";
    }
    std::cout << std::endl;

    std::cout << v1.front() << std::endl;
    std::cout << v1.back() << std::endl;

    return 0;
}