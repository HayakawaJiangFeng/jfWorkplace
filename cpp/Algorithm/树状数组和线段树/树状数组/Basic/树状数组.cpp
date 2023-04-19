#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

const int Max = 1e5 + 10;

int len;
int my_cache[Max];

//lowbit()运算 : 非负整数n在二进制表示最低位1及其后面的0构成的十进制数值
//例如lowbit(44) = lowbit(101100) = 100 = 4;
//那么怎么取得最低位1以及后面的0构成的十进制数值？
//101100 按位取反再加一 ：  010100 再用这个数与101100按位与即可得到100
int lowbit(int num)
{
    return num & -num;
}
void add(int index, int value)
{
    while(index <= len)
    {
        index += lowbit(index);
        my_cache[index] += value;
    }
}
int query(int index)
{
    int res = 0;
    while (index)
    {
        index -= lowbit(index);
        res += my_cache[index];
    }
    return res;
}
int main()
{

}