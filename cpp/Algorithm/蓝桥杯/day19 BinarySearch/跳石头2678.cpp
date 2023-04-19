#include <iostream>

int L, N, M;
int numbers[50010];

bool check(int mid){

    int cnt = 0;
    int i = 0;
    int now = 0;

    while (i < N)
    {
        
        i++;
        while (numbers[i] - numbers[now] < mid)
        {

            cnt++;
            if(i < N){

                i++;
            }
            else{

                if(cnt <= M){

                    return true;
                }else{

                    return false;
                }
            }
        }
        now = i;
    }
    if(cnt <= M){

        return true;
    }else{

        return false;
    }
}
int main(){

    std::cin >> L >> N >> M;

    for(int i = 0 ; i < N; i++){

        std::cin >> numbers[i];
    }
    numbers[N] = L;
    int left = 0;
    int right = L + 1;
 
    while (left + 1 < right)
    {
        
        int mid = (left + right) / 2;
        if(check(mid)){

            left = mid;
        }else{

            right = mid;
        }
    }

    if(check(right)){

        std::cout << right << std::endl;
    }else{

        std::cout << left << std::endl;
    }
    return 0;
}