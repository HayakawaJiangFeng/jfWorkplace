#include <iostream>

int function(int x, int y){

    if(y == 0){

        return x;
    }else{

        return function(y, x % y);
    }
}
int main(){

    int x,y;
    std::cin >> x >> y;
    std::cout << function(x,y) << std::endl;
}