#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm> 
#include <cmath>

const int Max = 100010;


int N, M, T;
int score[Max];
int last[Max];
bool st[Max];
std::pair<int, int> order[Max];

int main(){
    
    std::cin >> N >> M >> T;

    for(int i = 0; i < M; i++) std::cin >> order[i].first >> order[i].second;
    std::sort(order, order + M);
    
    for(int i = 0; i < M;){

        int j = i;
        while (j < M && order[i] == order[j]) j++;
        int t = order[i].first, id = order[i].second, cnt = j - i;
        i = j;
        
        score[id] -= t - last[id] - 1;
        if(score[id] < 0) score[id] = 0;
        if(score[id] <= 3) st[id] = false;

        score[id] += cnt * 2;
        if(score[id] > 5) st[id] = true;

        last[id] = t;
    }

    for(int i = 1; i <= N; i++){

        if(last[i] < T){

            score[i] -= T - last[i];
            if(score[i] <= 3) st[i] = false; 
        }
    }
    
    int res = 0;
    for(int i = 1; i <= N; i++){
        if(st[i]){
            res++;
        }
    }

    std::cout << res << std::endl;

    return 0;
}