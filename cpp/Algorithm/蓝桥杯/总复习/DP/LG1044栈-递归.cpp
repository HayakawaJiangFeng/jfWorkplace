#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

const int Max = 20;

int n;
int memory[Max][Max];

int dfs(int i, int j)
{
    if(memory[i][j]) return memory[i][j];
    if(i == 0) return 1;
    if(j > 0)   memory[i][j] += dfs(i , j - 1);
    memory[i][j] += dfs(i - 1, j + 1);
    return dfs(i,j);
}
int main()
{
    std::cin >> n;

    std::cout << dfs(n,0) << std::endl;   

    return 0;
}