#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>

const int Max = 210;

std::queue<int> q;

int N,A,B;
int values[Max];
int dist[Max];

int bfs(int start)
{
    memset(dist, -1, sizeof(dist));
    dist[start] = 0;
    q.push(start);

    while (q.size())
    {
        int temp = q.front();
        if(temp == B) return dist[B];
        q.pop();

        if(temp + values[temp] <= N && dist[temp + values[temp]] < 0)
        {
            dist[temp + values[temp]] = dist[temp] + 1;
            q.push(temp + values[temp]);
        }
        if(temp - values[temp] >= 1 && dist[temp - values[temp]] < 0)
        {
            dist[temp - values[temp]] = dist[temp] + 1;
            q.push(temp - values[temp]);
        }
    }
    return dist[B];
}
int main()
{
    std::cin >> N >> A >> B;

    for(int i = 1; i <= N; i++) std::cin >> values[i];

    int res = bfs(A);
    std::cout << res << std::endl;

    return 0;
}