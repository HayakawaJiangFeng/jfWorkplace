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

    std::cout << "size : " << v1.size() << std::endl;
    std::cout << "capacity : " << v1.capacity() << std::endl;

    v1.resize(15,1314);

    std::cout << "size : " << v1.size() << std::endl;
    std::cout << "capacity : " << v1.capacity() << std::endl;

    printVector(v1);
    return 0;
}