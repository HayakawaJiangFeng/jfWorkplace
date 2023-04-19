#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

const int Max = 10010;
int n;

int main(){

    std::cin >> n;

    int res = 0;
    for(int i = 1; i <= n; i++){

        int temp = i;
        while (temp)
        {
            if(temp % 10 == 2 || temp % 10 == 0 || temp % 10 == 1 || temp % 10 == 9){

                res += i;
                break;
            }
            temp /= 10;
        }
    }

    std::cout << res << std::endl;

    return 0;
}