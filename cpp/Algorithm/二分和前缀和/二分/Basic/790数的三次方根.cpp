#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

int main()
{
    double n;
    std::cin >> n;

    double left = -1000;
    double right = 1000;

    while (right - left > 1e-7)
    {
        double mid = (left + right) / 2;
        if(mid * mid * mid >= n)
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }
    printf("%lf\n",left);
    return 0;
}
