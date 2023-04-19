#include <iostream>

int main()
{
    double num;
    std::cin >> num;

    double left = -100;
    double right = 100;

    while (right - left > 1e-8)
    {
         double mid = (left + right) / 2;
         if(mid * mid * mid >= num)
         {
            right = mid;
         }
         else
         {
            left = mid;
         }
    }
    printf("%lf\n", left);

    return 0;
}