#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

const int Max = 1e5 + 10;

int N,D,K;
int cnt[Max];
bool st[Max];
std::pair<int, int> logs[Max];

int main(){

    std::cin >> N >> D >> K;

    for(int i = 0; i < N; i++) scanf("%d %d", &logs[i].first, &logs[i].second);

    std::sort(logs, logs + N);

    for(int i = 0, j = 0; i < N; i++){

        int id = logs[i].second;
        cnt[id]++;

        while (logs[i].first - logs[j].first >= D)
        {
            cnt[logs[j].second]--;
            j++;
        }
        if(cnt[id] >= K){

            st[id] = true;
        }
    }
    for(int i = 0; i < 100000; i++)
    {
        if(st[i]) printf("%d\n",i);
    }
    return 0;
}