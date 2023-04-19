#include <iostream>

int main(){

    int num = 0;
    int front, last;
    std::cin >> front >> last;

    if(front > last){

        std::swap(front, last);
    }
    for(int i = front; i <= last; i++){

        if(i == 1){
            
            continue;
        }
        bool isPrime = true;
        for(int j = 2; j < i; j++){

            if(i % j == 0){

                isPrime = false;
                std::cout << i << " is not prime" << std::endl;
                break;
            }
        }
        if(isPrime){
            
            std::cout << i << " is prime" << std::endl;
            num++;
        }
    }
    return 0;
}