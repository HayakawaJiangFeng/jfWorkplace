#include <iostream>
#include <algorithm>

template<typename T>
void arraySort(T array[], int len){

    std::sort(array,array + len);
}

int main(){

    int array[] = {1, 3, 2, 5, 4};
    arraySort(array,5);

    char array1[] = "bcfdawi";
    arraySort(array1,5);

    for(int i = 0; i < 5; i++){

        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    for(int i = 0; i < 5; i++){

        std::cout << array1[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}