#include <iostream>

int L,N,M;
int values[50005];

bool check(int mid){

    int sum = 0;
    int now = 0;
    int i = 0;
    while (i < N)
    {
        i++;
        while(values[i] - values[now] < mid){

            sum++;
            if(i < N){

                i++;
            }else{

                if(sum <= M){

                    return true;
                }else{

                    return false;
                }
            }
        }
        now = i;
    }
    if(sum <= M){

        return true;
    }else{

        return false;
    }
}
int main(){

    std::cin >> L >> N >> M;

    for(int i = 1; i <= N; i++){

        std::cin >> values[i];
    }
    values[N + 1] = L;
    values[0] = 0;

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
}