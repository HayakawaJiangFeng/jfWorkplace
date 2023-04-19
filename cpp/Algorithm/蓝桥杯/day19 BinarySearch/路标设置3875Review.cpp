#include <iostream>

int L,N,K;
int longest;
int values[100010];
int s[100010];

bool check(int mid){

    int cnt = 0;
    
    for(int i = 1; i <= N + 1; i++){

        if (s[i] > mid)
        {
            cnt++;
            int temp = s[i] - mid;
            while (temp > mid)
            {
                
                cnt++;
                temp -= mid;
            }
        }
    }
    if(cnt <= K){

        return true;
    }else{

        return false;
    }
}
int main(){

    std::cin >> L >> N >> K;

    for(int i = 1; i <= N; i++){

        std::cin >> values[i];
        longest = std::max(longest, values[i]);
        s[i] = values[i] - values[i - 1];
    }
    values[0] = 0;
    values[N + 1] = L;
    s[N + 1] = values[N + 1] - values[N];

    int left = 0;
    int right = longest;

    while (left + 1 < right)
    {
        int mid = (left + right) / 2;
        if(check(mid)){

            right = mid;
        }else{

            left = mid;
        }
    }
    if(check(left)){

        std::cout << left << std::endl;
    }else{

        std::cout << right << std::endl;
    }
    
}