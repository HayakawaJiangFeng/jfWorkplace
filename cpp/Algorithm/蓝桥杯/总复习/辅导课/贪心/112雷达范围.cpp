#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

const int Max = 1e3 + 10;

struct node
{
    double left;
    double right;

    bool operator<(const node &n) const
    {
        return right < n.right;
    }
}nodes[Max];

int main()
{
    int n,d;
    std::cin >> n >> d;

    bool failed = false;
    for(int i = 1; i <= n; i++)
    {
        int x,y;
        std::cin >> x >> y;

        if(d < y) failed = true;
        else{

            double len = std::sqrt(d * d - y * y);
            nodes[i].left = x - len;
            nodes[i].right = x + len;
        }
    }
    if(failed) std::cout << -1 << std::endl;
    else
    {
        std::sort(nodes + 1, nodes + n + 1);
        int cnt = 0;
        double last = -1e18;

        for(int i = 1; i <= n; i++)
        {
            if(last < nodes[i].left)
            {
                last = nodes[i].right;
                cnt++;
            }
        }
        std::cout << cnt << std::endl;
    }

    return 0;
}