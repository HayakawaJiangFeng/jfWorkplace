#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

const int Max = 1e5 + 10;

std::vector<std::pair<int, int> > v[Max];
int dist[Max];

void dfs(int u, int father, int distance){

    dist[u] = distance;
    for(std::vector<std::pair<int, int> >::iterator it = v[u].begin(); it != v[u].end(); it++){

        if((*it).first != father)
        {
            dfs((*it).first, u, distance + (*it).second);
        }
    }
}
int main(){

    int N;
    std::cin >> N;

    for(int i = 0; i < N - 1; i++){

        int start,end,value;
        std::cin >> start >> end >> value;

        v[start].push_back(std::make_pair(end,value));
        v[end].push_back(std::make_pair(start,value));
    }
    dfs(1, -1, 0);

    int u = 1;
    for(int i = 1; i <= N; i++)
    {
        if(dist[i] > dist[u]) u = i;
    }
    
    dfs(u, -1, 0);

    for(int i = 1; i <= N; i++)
    {
        if(dist[i] > dist[u]) u = i;
    }
    int res = dist[u];

    printf("%lld\n", res * 10 + res * (res + 1ll) / 2);

    return 0;
}