#include <iostream>

//找到最后一个小于等于5的元素的index
bool function1(int number){

    return number <= 5;
}
//找到第一个大于5的元素的index
bool function2(int number){

    return number <= 5;
}
int main(){

    int array[8] = {3,3,4,5,5,5,6,7};

    int left = -1;
    int right = 8;
    while (left + 1 != right)
    {
        
        int mid = (left + right) / 2;
        if(function1(array[mid])){

            left = mid;
        }else{

            right = mid;
        }
    }
    std::cout << "最后一个小于等于5的数的index =  " << left << std::endl;

    left = -1;
    right = 8;
    while (left + 1 != right)
    {
        
        int mid = (left + right) / 2;
        if(function2(array[mid])){

            left = mid;
        }else{

            right = mid;
        }
    }

    std::cout << "第一个大于5的数的index = " << right << std::endl;
    return 0;
}