#include <iostream>
#include <vector>

int main(){


    int num = 0;
    int* p = nullptr;

    std::vector<int> v1;

    //利用reserve预留空间
    v1.reserve(1000);

    for(int i = 0; i < 1000; i++){

        v1.push_back(i);

        if(p != &v1[0]){

            p = &v1[0];
            num++;
        }
    }

    std::cout << num << std::endl;
    return 0;
}