#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

const int N = 100010;
bool checkSecond(int x, int num){


    if(values[x] <= num){

        return true;
    }else{

        return false;
    }
};

int n;
int q;
int values[N];

bool checkFirst(int x, int num){

    if(values[x] < num){

        return true;
    }
    return false;
}

int binary_searchFirst(int num){

    int left = -1;
    int right = n;

    while (left + 1 < right)
    {
         int mid = (left + right) / 2;
         
         if(checkFirst(mid, num)){

            left = mid;
         }else{

            right = mid;
         }
    }
    if(values[right] == num){

        return right;
    }else{

        return -1;
    }
}
int binary_searchLast(int num){

    int left = -1;
    int right = n;

    while (left + 1 != right)
    {
         
         int mid = (left + right) / 2;

         if(values[mid] <= num){

            left = mid;
         }else{

            right = mid;
         }
    }

    if(values[left] == num){
        
        return left;
    }else{

        return -1;
    }
}
int main(){

    std::cin >> n >> q;

    for(int i = 0; i < n; i++){

        std::cin >> values[i];
    }
    std::sort(values, values + n);
    for(int i = 0; i < q; i++){

        int num = 0;
        std::cin >> num;

        int first = binary_searchFirst(num);

        if(first == -1){

            std::cout << -1 << " " << -1 << std::endl;
        }else{

            std::cout << first << " " << binary_searchLast(num) << std::endl;
        }
    }

    return 0;
}