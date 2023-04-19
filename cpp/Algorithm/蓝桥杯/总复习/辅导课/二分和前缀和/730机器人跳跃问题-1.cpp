#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int Max = 100010;

int N;
int values[Max];

bool check(int x){

    for(int i = 1; i <= N; i++){

        x = 2 * x - values[i];
        if(x > 100000){

            return true;
        }
        if(x < 0){

            return false;
        }
    }
    return true;
}
int main(){

    std::cin >> N;

    for(int i = 1; i <= N; i++){

        std::cin >> values[i];
    }

    int left = 1;
    int right = 100000;

    while (left < right)
    {
        int mid = (left + right) >> 1;

        if(check(mid)){

            right = mid;
        }else{

            left = mid + 1;
        }
    }
    std::cout << left << std::endl;

    return 0;
}