#include <iostream>
#include <algorithm>

int main(){

    int arr[] = {10,1,11,8,7,2,0,0,2};
    //从小到大
    std::sort(arr, arr + 9);

    for(int i = 0; i < 9; i++){
        
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    //从大到小
    std::sort(arr, arr + 9, std::greater<int>());

    for(int i = 0; i < 9; i++){
        
        std::cout << arr[i] << " ";
    }

    return 0;
}