#include <iostream>

int cnt;
int main(){

    for(int i = 2; i <= 2020; i++){

        if(i / 1000  == 2){
            cnt++;
        }
        if(i / 100 % 10 == 2){
            cnt++;
        }
        if(i / 10 % 10 == 2){
            cnt++;
        }
        if(i % 10 == 2){
            cnt++;
        }
    }
    std::cout << cnt << std::endl;

    return 0;
}