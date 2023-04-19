#include <iostream>
#include <algorithm>
#include <cstring>

int main(){

    int cnt = 2021;
    int start = 0;

    while (cnt)
    {
        start++;       
        int temp = start;
        while (temp)
        {
            if(temp % 10 == 1){

                cnt--;
            }
            temp /= 10;
        }
        
    }
    std::cout << start << std::endl;

    return 0;
}