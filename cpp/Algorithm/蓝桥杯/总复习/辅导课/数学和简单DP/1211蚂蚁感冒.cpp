#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

const int Max = 55;

int n;
int values[Max];

int main(){

    std::cin >> n;
    for(int i = 0; i < n; i++){

        std::cin >> values[i];
    }

    int left = 0;
    int right = 0;

    for(int i = 1; i < n; i++){

        if(abs(values[i]) < abs(values[0]) && values[i] > 0){

            left++;
        }
        else if(abs(values[i]) > abs(values[0]) && values[i] < 0){

            right++;
        }
    }
    if(values[0] > 0 && right == 0 || values[0] < 0 && left == 0){
        
        std::cout << 1 << std::endl;
    }else{
        
        std::cout << left + right + 1 << std::endl;
    }

    return 0;
}