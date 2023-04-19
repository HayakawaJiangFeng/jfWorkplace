#include <iostream>
#include <vector>
#include <algorithm>

//容器vector
//算法for_each
//迭代器std::vector<>::iterator

void myPrint(int value){

    std::cout << value << std::endl;
}
int main(){

    std::vector<int> v1;
    for(int i = 1; i <= 10; i++){

        v1.push_back(i * 10);
    }

    for(std::vector<int>::iterator it = v1.begin(); it != v1.end(); it++){

        std::cout << *it << std::endl;
    }

    std::for_each(v1.begin(),v1.end(),myPrint);   

    return 0;
}