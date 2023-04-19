#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

const int Max = 100010;

int n,m;
int values[Max];
int my_cache[Max];

int main(){

    std::cin >> n >> m;

    for(int i = 1; i < n; i++){

        std::cin >> values[i];
        my_cache[i] = my_cache[i - 1] + values[i];
    }

    while (m--)
    {
        
        int left,right;

        std::cin >> left >> right;

        //std::cout << my_cache[left] << ' ' << my_cache[right];
        std::cout << my_cache[right] - my_cache[left - 1] << std::endl;
    }
    
    return 0;
}