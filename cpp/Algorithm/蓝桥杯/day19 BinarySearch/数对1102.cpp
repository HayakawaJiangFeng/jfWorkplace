#include <iostream>
#include <algorithm>

long long res;
int N,C;
int numbers[200000];

int binary_searchFirst(int x){

    int left = -1;
    int right = N;

    while (left + 1 != right)
    {
         
         int mid = (left + right) / 2;

         if(numbers[mid] < x){

            left = mid;
         }else{

            right = mid;
         }
    }
    if(numbers[right] == x){

        return right;
    }else{

        return -1;
    }
}
int binary_searchLast(int x){

    int left = -1;
    int right = N;

    while (left + 1 != right)
    {
        
        int mid = (left + right) / 2;
        
        if(numbers[mid] <= x){

            left = mid;
        }else{

            right = mid;
        }
    }
    if(numbers[left] == x){

        return left;
    }else{

        return -1;
    }
}
int main(){

    std::cin >> N >> C;

    for(int i = 0; i < N; i++){

        std::cin >> numbers[i];
    }

    std::sort(numbers,numbers + N);
    
    for(int i = 0; i < N; i++){

        int A = numbers[i] + C;
        
        int res1 = binary_searchFirst(A);

        if(res1 == -1){

            continue;
        }else{

            res += binary_searchLast(A) - res1 + 1;
        }
    }

    printf("%lld",res);

    return 0;
}