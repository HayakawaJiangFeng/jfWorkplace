#include <vector>
#include <iostream>

int main(){

    //std::vector<std::vector<int > > vec1(n , std::vector(m, 0));

    std::vector<std::vector<int > > vec1;

    for(int i = 0; i < 10; i++){

        std::vector<int> vec2(i + 1,1);
        vec1.push_back(vec2);
    }
    for(int i = 0; i < 10; i++){

        for(int j = 0; j < vec1[i].size(); j++){

            std::cout << vec1[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}