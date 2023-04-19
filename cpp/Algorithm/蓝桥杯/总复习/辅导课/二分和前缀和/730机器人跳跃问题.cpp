#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

const int N = 100010;

int n;
int values[N];

bool check(int x){

    for(int i = 0; i <= n; i++){

        x = 2 * x - values[i + 1];
        if(x >= 1e5){

            return true;
        }
        if(x < 0){

            return false;
        }
    }
    return true;
}
int main(){

    std::cin >> n;

    values[0] = 0;

    for(int i = 1; i <= n; i++){

        std::cin >> values[i];
    }

    int left = -1;
    int right = 1e5 + 1;

    while (left + 1 != right)
    {
        
        int mid = (left + right) / 2;
        
        if(check(mid)){

            right = mid;
        }else{

            left = mid;
        }
    }
    std::cout << right << std::endl;
    
    return 0;
}