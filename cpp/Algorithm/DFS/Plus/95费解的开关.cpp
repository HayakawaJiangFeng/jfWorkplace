/*
在C++中，^表示按位异或运算符，它的操作数都必须是整数类型，它的计算规则是：对两个整数的二进制数，
从高位到低位逐位比较，如果相同则对应的结果为0，如果不同则对应的结果为1。
例如：5 ^ 3 的结果为 6，其二进制数表示为 101 ^ 011 = 110。

与之对应的，如果想要对一个整数的二进制数进行按位取反操作，应该使用位运算符 ~，
例如：~5 的结果是 -6，其二进制数表示为 ~(00000101) = 11111010。

&和|都是按位运算符。&表示按位与运算符，它的计算规则是：对两个整数的二进制数，
从高位到低位逐位比较，只有在相应位上的两个数都为 1 时，结果才为 1，否则结果为 0。
例如：5 & 3的结果为 1，其二进制数表示为101 & 011 = 001。

|表示按位或运算符，它的计算规则是：对两个整数的二进制数，从高位到低位逐位比较，只要在相应位上的两个数中有一个为1，
结果就为1，否则结果为0。例如：5 | 3的101 | 011 = 111。

这些按位运算符在处理二进制数据时非常有用。例如，使用按位与可以方便地从一个整数中提取某一位的值，
使用按位或可以方便地将某一位设置为1，等等。
*/

#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

int n;
int next[5][2] = {{0,0},{-1,0},{0,-1},{1,0},{0,1}};
char map[10][10];
char backups[10][10];

void turns(int x, int y)
{
    for(int i = 0; i < 5; i++)
    {
        int xx = x + next[i][0];
        int yy = y + next[i][1];

        if(xx >= 0 && xx < 5 && yy >= 0 && yy < 5) map[xx][yy] ^= 1;
    }
}
int main()
{
    std::cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        int cnt = 7;
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++) scanf(" %c", &map[i][j]);
        }

        memcpy(backups, map, sizeof(backups));

        for(int top = 0; top < (1 << 5); top++)
        {
            int step = 0;
            
            for(int i = 0; i < 5; i++)
            {
                if(top >> i & 1)
                {
                    step++;
                    turns(0,i);
                }
            }
            for(int i = 0; i < 4; i++)
            {
                for(int j = 0; j < 5; j++)
                {
                    if(map[i][j] == '0')
                    {
                        step++;
                        turns(i + 1,j);
                    }
                }
            }
            bool is_dark = false;
            for(int i = 0; i < 5; i++)
            {
                if(map[4][i] == '0')
                {

                    is_dark = true;
                    break;
                }
            }
            if(!is_dark && step < cnt) cnt = step;

            memcpy(map, backups, sizeof(map));
        }

        if(cnt <= 6) std::cout << cnt << std::endl;
        else std::cout << -1 << std::endl;
    }
    return 0;
}