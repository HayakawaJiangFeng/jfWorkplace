#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

int n,start,end;

int main(){

    std::cin >> n >> start >> end;

    start--,end--;
    int x1 = start / n, x2 = end / n;
    int y1 = start % n, y2 = end % n;

    if(x1 % 2){
        y1 = n - 1 - y1;
    }
    if(x2 % 2){

        y2 = n - 1 - y2;
    }

    std::cout << abs(x1 - x2) + abs(y1 - y2) << std::endl;
}