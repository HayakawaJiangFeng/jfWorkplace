#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

int n;

int main(){

    std::cin >> n;

    for(int a = 0; a * a <= n; a++){

        for(int b = a; b * b + a * a <= n; b++){

            for(int c = b; c * c + b * b + a * a <= n; c++){

                int dd = n - (a * a + b * b + c * c);

                int d = sqrt(dd);
                
                if(dd == d * d){

                    std::cout << a << " " << b << " " << c << " " << d << std::endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}