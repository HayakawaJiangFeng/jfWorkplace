#include <iostream>

int N,C;
long long res;
int numbers[200010];

int binary_searchFirst(int A){

    int left = 0;
    int right = N + 1;

    while (left + 1 != right)
    {
        
        int mid = (left + right) / 2;
        if(numbers[mid] < A){

            left = mid;
        }else{

            right = mid;
        }
    }
    if(numbers[right] == A){

        return right;
    }else{

        return -1;
    }
}
int binary_searchLast(int A){

    int left = 0;
    int right = N + 1;

    while (left + 1 != right)
    {
        
        int mid = (left + right) / 2;
        if(numbers[mid] <= A){

            left = mid;
        }else{

            right = mid;
        }
    }
    if(numbers[left] == A){

        return left;
    }else{

        return -1;
    }
}
int main(){

    std::cin >> N >> C;

    for(int i = 1; i <= N; i++){

        std::cin >> numbers[i];
    }
    std::sort(numbers + 1, numbers + N + 1);
    for(int i = 1; i <= N; i++){

        int A = numbers[i] + C;

        int res1 = binary_searchFirst(A);

        if(res1 == -1){

            continue;
        }else{

            res += binary_searchLast(A) - res1 + 1;
        }
    }

    std::cout << res << std::endl;

    return 0;
}