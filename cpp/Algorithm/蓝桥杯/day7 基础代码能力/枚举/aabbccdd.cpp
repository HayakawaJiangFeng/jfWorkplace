#include <iostream>
#include <cmath>

int main(){

    int number, d;
    std::cin >> number;

    for(int a = 0; a * a < number; a++){
        
        for(int b = 0; a * a + b * b < number; b++){

            for (int c = 0; a * a + b * b + c * c < number; c++){

                d = sqrt(number - a * a - b * b - c * c);
                if(a * a + b * b + c * c + d * d == number){

                    std::cout << a << " " << b << " " << c << " " << d << std::endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}