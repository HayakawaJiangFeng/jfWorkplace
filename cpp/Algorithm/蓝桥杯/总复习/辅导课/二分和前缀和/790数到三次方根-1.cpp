#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

double n;

int main(){

    std::cin >> n;

    double left = -10000.0;
    double right = 10000.0;

    while (right - left > 1e-7)
    {
         double mid = (left + right) / 2;

         if(mid * mid * mid >= n){

            right = mid;
         }else{

            left = mid;
         }
    }
    printf("%lf\n",left);

    return 0;
}