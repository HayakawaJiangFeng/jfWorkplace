#include <iostream>

int gcd(int x, int y)
{
    return y ? gcd(y, x % y) : x;
}

int main()
{
    int num1, num2;
    std::cin >> num1 >> num2;

    std::cout << gcd(num1, num2) << std::endl;

    return 0;
}