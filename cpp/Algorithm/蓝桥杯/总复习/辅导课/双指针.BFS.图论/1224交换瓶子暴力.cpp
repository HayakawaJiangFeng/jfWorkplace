#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>

const int Max = 1e4 + 10;

int values[Max];
int N;

int main(){

    std::cin >> N;

    int sum = 0;

    for(int i = 1; i <= N; i++) scanf("%d", &values[i]);

    for(int i = 1; i <= N; i++)
    {
        if(values[i] != i)
        {
            for(int j = i + 1; j <= N; j++)
            {
                if(values[j] == i)
                {
                    std::swap(values[i],values[j]);
                    sum++;
                }
            }
        }
    }
    std::cout << sum << std::endl;
    
    return 0;
}