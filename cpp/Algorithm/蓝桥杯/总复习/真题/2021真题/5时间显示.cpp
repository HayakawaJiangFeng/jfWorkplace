#include <iostream>

long long int n;

int main(){

    std::cin >> n;

    n = n / 1000;
    n = n % (60 * 60 * 24);

    int h = n / 3600;
    n = n % 3600;

    int min = n / 60;
    n = n % 60;

    int s = n % 60;

    printf("%02d:%02d:%02d\n",h,min,s);

    return 0;
}