#include <iostream>
#include <algorithm>

//cmp 作为一种排序规则
bool cmp1(int x, int y){

    return x > y;
}

bool cmp2(int x,int y){

    if(x % 3 != y % 3){

        return x % 3 > y % 3;
    }else{

        return x > y;
    }
    return x > y;
}

int main(){

    int numbers[5] = {};
    for(int i = 0; i < 5; i++){

        std::cin >> numbers[i];
    }
    std::sort(numbers,numbers + 5,cmp1);
    for(int i = 0; i < 5; i++){

        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
    
    for(int i = 0; i < 5; i++){

        std::cin >> numbers[i];
    }
    std::sort(numbers,numbers + 5, cmp2);
    for(int i = 0; i < 5; i++){

        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}