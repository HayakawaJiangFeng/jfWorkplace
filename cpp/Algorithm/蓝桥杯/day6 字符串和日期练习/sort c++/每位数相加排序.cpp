#include <algorithm>
#include <iostream>

int numbers[105];

bool cmp(int x, int y){

    int xx = x;
    int yy = y;
    int sumX = 0;
    int sumY = 0;

    while(x){

        sumX += x % 10;
        x /= 10;
    }
    while(y){

        sumY += y % 10;
        y /= 10;
    }
    if(sumX == sumY){

        return xx < yy;
    }else{

        return sumX < sumY;
    }
}
int main(){

    int number = 0;
    std::cin >> number;

    for(int i = 0; i < number; i++){

        std::cin >> numbers[i];
    }

    std::sort(numbers, numbers + number , cmp);

    for(int i = 0; i < number; i++){

        if(i != number - 1){

            std::cout << numbers[i] << " ";
        }else{

            std::cout << numbers[i] << std::endl;
        }
    }

    return 0;
}