#include <iostream>

int cnt;

int main(){

    for(int i = 2; i <= 2020; i++){

        int temp = i;
        while (temp)
        {
            int res = temp % 10;
            if(res == 2){

                cnt++;
            }
            temp /= 10;
        }
        
    }
    std::cout << cnt << std::endl;
    return 0;
}