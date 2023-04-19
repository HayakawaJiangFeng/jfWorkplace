#include <iostream>

int main(){

    int sum = 2021;
    int i = 1;
    int temp1 = 0;
    int temp2 = 0;

    for(i = 1; ; i++){

        temp1 = i;
        while(temp1){

            temp2 = temp1 % 10;
            if(temp2 == 1 && sum > 0){

                sum -= 1;
            } 
            temp1 /= 10;
        }
        if(sum == 0){

            break;
        }
    }
    std::cout << i;
    return 0;
}