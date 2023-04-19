#include<iostream>
#include<algorithm>
using namespace std;

int main(){

    int value[4] = {3,1,1};
    sort(value, value + 3);

    for(int i = 0; i < 3; i++){

        std::cout << value[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}