#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

const int Max = 1e4 + 10;

int N;
int values[Max];
bool st[Max];

int main(){

    std::cin >> N;
    
    for(int i = 1; i <= N; i++) scanf("%d", &values[i]);

    int cnt = 0;
    for(int i = 1; i <= N; i++){

        if(!st[i]){
            
            cnt++;
            for(int j = i; !st[j]; j = values[j]){

                st[j] = true;
            }
        }
    }
    std::cout << N - cnt << std::endl;
    
    return 0;
}