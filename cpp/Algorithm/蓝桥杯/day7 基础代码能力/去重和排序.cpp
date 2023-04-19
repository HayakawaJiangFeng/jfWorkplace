#include <iostream>
#include <algorithm>

int array[105],ans[105];

int main(){

    int number;
    int m = 0;
    std::cin >> number;

    for(int i = 0; i < number; i++){

        std::cin >> array[i];
    }
    std::sort(array, array + number);

    for(int i = 0; i < number; i++){

        if(i != 0 && array[i] != array[i - 1]){

            ans[m++] = array[i - 1];
        }
    }
    ans[m++] = array[number - 1];

    std::cout << m << std::endl;

    for(int i = 0; i < m; i++){

        if(i != m - 1){

            std::cout << ans[i] << " ";
        }else{

            std::cout << ans[i] << std::endl;
        }
    }
}