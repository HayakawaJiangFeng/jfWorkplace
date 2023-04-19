#include <iostream>
#include <vector>

void printVector(std::vector<int>& vector){

    for(std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++){

        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main(){

    std::vector<int> v1;

    for(int i = 0; i < 10; i++){

        v1.push_back(i);
    }
    printVector(v1);
    
    std::vector<int> v2;

    for(int i = 9; i >= 0; i--){

        v2.push_back(i);
    }
    printVector(v2);

    v1.swap(v2);
    printVector(v1);
    printVector(v2);

    std::vector<int> v3;

    for(int i = 0; i < 101; i++){

        v3.push_back(i);
    }

    std::cout << "capacity : " << v3.capacity() << std::endl;
    std::cout << "size : " << v3.size() << std::endl;

    v3.resize(3);

    std::cout << "capacity : " << v3.capacity() << std::endl;
    std::cout << "size : " << v3.size() << std::endl;

    std::vector<int>(v3).swap(v3);

    std::cout << "capacity : " << v3.capacity() << std::endl;
    std::cout << "size : " << v3.size() << std::endl;

    return 0;
}