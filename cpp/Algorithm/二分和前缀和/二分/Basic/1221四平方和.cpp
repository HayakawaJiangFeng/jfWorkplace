#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

const int Max = 1e6 * 5 + 10;

int N;
struct  node
{
    bool operator<(const node &n) const 
    {   
        if(sum != n.sum) return sum < n.sum;
        else if(c != n.c) return c < n.c;
        else return d < n.d;
    }
    int c;
    int d;
    int sum;
}cds[Max];

int main()
{
    std::cin >> N;
    int cnt = 0;

    for(int c = 0; c * c <= N; c++)
    {
        for(int d = c; c * c + d * d <= N; d++)
        {
            struct node cd;
            cd.c = c;
            cd.d = d,
            cd.sum = c * c + d * d;
            cds[cnt++] = cd;
        }
    }
    std::sort(cds, cds + cnt);
    for(int a = 0; a * a <= N; a++)
    {
        for(int b = a; b * b + a * a <= N; b++)
        {
            int temp = N - (b * b + a * a);
            
            int left = 0;
            int right = cnt - 1;

            while (left < right)
            {
                 int mid = (left + right) / 2;
                 if(cds[mid].sum >= temp)
                 {
                    right = mid;
                 }
                 else
                 {
                    left = mid + 1;
                 }
            }
            if(cds[left].sum == temp)
            {
                std::cout << a << " " << b << " " << cds[left].c << " " << cds[left].d << std::endl;
                return 0;
            }
        }
    }
    return 0;
}