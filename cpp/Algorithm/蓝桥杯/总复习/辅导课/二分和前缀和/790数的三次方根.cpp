#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

double n;

int main(){

    std::cin >> n;

    double left = -100.0;
    double right = 100.0;

    while (right - left > 1e-8)
    {
         double mid = (left + right) / 2;

         if(mid * mid * mid <= n){

            left = mid;
         }else{

            right = mid;
         }
    }
    printf("%lf",left);

    return 0;
}