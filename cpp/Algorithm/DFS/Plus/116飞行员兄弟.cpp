#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>

char map[20][20];
char backups[20][20];
std::vector<std::pair<int, int> > v;

void turnOne(int x,int y)
{
    if(map[x][y] == '+') map[x][y] = '-';
    else map[x][y] = '+';
}
void turnAll(int x, int y)
{
    turnOne(x,y);
    for(int i = 0; i < 4; i++)
    {
        turnOne(i,y);
        turnOne(x,i);
    }
}
/*
0 1 2 3         第0行
4 5 6 7           1
8 9 10 11         2
12 13 14 15       3
*/
int get_Index(int x, int y)
{
    return x * 4 + y;
}
int main()
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            scanf(" %c", &map[i][j]);
        }
    }

    memcpy(backups, map, sizeof(backups));

    for(int top = 0; top < (1 << 16); top++)
    {
        std::vector<std::pair<int, int> > temp;

        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                if(top >> get_Index(i,j) & 1)
                {
                    temp.push_back(std::make_pair(i,j));
                    turnAll(i,j);
                }
            }
        }
        bool is_close = false;
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                if(map[i][j] == '+')
                {
                    is_close = true;
                    break;
                }
            }
        }
        if(!is_close)
        {
            if(v.size() == 0 || temp.size() < v.size()) 
            {
                v = temp;
            }
        }
        memcpy(map, backups, sizeof(map));
    }
    std::cout << v.size() << std::endl;
    for(std::vector<std::pair<int, int> >::iterator it = v.begin(); it != v.end(); it++)
    {
        std::cout << (*it).first + 1 << " " << (*it).second + 1 << std::endl;
    }
    return 0;
}