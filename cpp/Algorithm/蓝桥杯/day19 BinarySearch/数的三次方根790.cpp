#include <iostream>

double n;

bool check(double x){

    if(x * x * x <= n){

        return true;
    }
    return false;
}

int main(){

    std::cin >> n;
    double left = -100;
    double right = 100;

    while (right - left > 1e-8)
    {
        double mid = (right + left) / 2;
        if(check(mid)){
            
            left = mid;
        }else{

            right = mid;
        }
    }

    printf("%lf\n",left);
    printf("%lf",right);
    return 0;
}