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
    v1.pop_back();
    printVector(v1);
    v1.insert(v1.begin(),1314);
    printVector(v1);
    v1.insert(v1.begin(),3,1314);
    printVector(v1);
    v1.erase(v1.begin());
    printVector(v1);
    v1.erase(v1.begin(),v1.end());
    printVector(v1);
    v1.clear();
    return 0;
}