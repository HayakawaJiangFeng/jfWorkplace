#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>


std::string start;
std::string end;

void turns(int x)
{
    if(start[x] == 'o') start[x] = '*';
    else start[x] = 'o';
    if(start[x + 1] == 'o') start[x + 1] = '*';
    else start[x + 1] = 'o';
}

int main()
{
    int step = 0;

    std::cin >> start >> end;

    for(int i = 0; i < start.size() - 2; i++)
    {
        if(start[i] != end[i])
        {
            step++;
            turns(i);
        }
        if(start == end) break;
    }

    std::cout << step << std::endl;

    return 0;
}
