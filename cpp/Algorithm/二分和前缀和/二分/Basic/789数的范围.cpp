#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

const int Max = 1e5 + 10;

int n,k;
int values[Max];

int binarySearch_first(int num)
{
    int left = 1;
    int right = n;
    
    while (left < right)
    {
        int mid = (left + right) / 2;

        if(values[mid] >= num)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    if(values[right] == num) return right;
    else return -1;
}
int binarySearch_last(int num)
{
    int left = 1;
    int right = n;

    while (left < right)
    {
         int mid = (left + right + 1) / 2;
         if(values[mid] <= num)
         {
            left = mid;
         }
         else
         {
            right = mid - 1;
         }
    }
    if(values[left] == num) return left;
    else return -1;
}
int main()
{
    std::cin >> n >> k;

    for(int i = 1; i <= n; i++) scanf("%d", &values[i]);

    for(int i = 1; i <= k; i++)
    {
        int num;
        std::cin >> num; 
        int first = binarySearch_first(num);
        if(first == -1)
        {
            std::cout << "-1 -1" << std::endl;
        }
        else
        {
            int last = binarySearch_last(num);
            std::cout << first - 1 << " " << last - 1 << std::endl;
        }
    }
    return 0;
}