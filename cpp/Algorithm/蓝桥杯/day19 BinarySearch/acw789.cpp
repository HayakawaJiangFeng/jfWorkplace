#include <iostream>

int n,q;
int array[100005];
int ans[2];

//第一个大于等于3的元素的index
bool function1(int value,int number){

    return value < number;
}
//最后一个大于等于3的元素的index
bool function2(int value, int number){

    return value <= number;
}

void binary_search(int number){

    int left = -1;
    int right = n;

    while (left + 1 != right)
    {
         
         int mid = (left + right) / 2;
         if(function1(array[mid],number)){

            left = mid;
         }else{

            right = mid;
         }
    }
    if(array[right] == number){
        
        ans[0] = right;
    }else{

        ans[0] = -1;
    }

    left = -1;
    right = n;

    while (left + 1 != right)
    {
        
        int mid = (left + right) / 2;
        if(function2(array[mid],number)){

            left = mid;
        }else{

            right = mid;
        }
    }
    if(array[left] == number){

        ans[1] = left;
    }else{

        ans[1] = -1;
    }
}

int main(){

    std::cin >> n >> q;
    for(int i = 0; i < n; i++){

        std::cin >> array[i];
    }

    for(int i = 0; i < q; i++){

        int k;
        std::cin >> k;
        binary_search(k);

        std::cout << ans[0] << " " << ans[1] << std::endl;
    }
    return 0;
}