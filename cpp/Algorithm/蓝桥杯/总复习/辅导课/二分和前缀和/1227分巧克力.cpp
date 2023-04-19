#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

std::vector<std::pair<int, int> > v;
int N,K;

bool check(int mid){

    int sum = 0;
    for(std::vector<std::pair<int, int> > :: iterator it = v.begin(); it != v.end(); it++){

        sum += (it->first / mid) * (it->second / mid);
    }
    if(sum >= K){

        return true;
    }else{
        
        return false;
    }
}
int main(){

    std::cin >> N >> K;

    for(int i = 0; i < N; i++){

        int h,w;
        std::cin >> h >> w;

        v.push_back(std::make_pair(h,w));
    }

    int left = 1;
    int right = 1e5;

    while (left < right)
    {
        int mid = (left + right + 1) / 2;

        if(check(mid)){

            left = mid;
        }else{

            right = mid - 1;
        }

    }
    std::cout << right << std::endl;

    return 0;
}