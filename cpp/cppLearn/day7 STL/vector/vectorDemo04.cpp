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

    std::vector<int> v2(v1.begin(),v1.end());
    printVector(v2);

    std::vector<int> v3(10,1314);
    printVector(v3);

    std::vector<int> v4(v3);
    printVector(v4);

    std::vector<int> v5;
    v5 = v1;
    printVector(v5);

    std::vector<int> v6;
    v6.assign(v1.begin(), v1.end());
    printVector(v6);

    std::vector<int> v7;
    v7.assign(10,2002);
    printVector(v7);

    return 0;
}