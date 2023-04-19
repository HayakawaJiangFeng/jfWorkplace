#include <iostream>

const int Max = 1e5 + 10;

int n,k;
int array[Max];

int binary_searchFirst(int num)
{
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
         int mid =  (left + right) >> 1;
         if(array[mid] >= num)
         {
            right = mid;
         }
         else
         {
            left = mid + 1;
         }
    }
    if(array[right] == num)
    {
        return right;
    }
    else 
    {
        return -1;
    }
}

int binary_searchLast(int num)
{
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        int mid = (left + right + 1) >> 1;
        if(array[mid] <= num)
        {
            left = mid;
        }
        else
        {
            right = mid - 1;
        }
    }
    if(array[left] == num)
    {
        return left;
    }
    else
    {
        return -1;
    }
}
int main()
{
    std::cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    for(int i = 0; i < k; i++)
    {
        int num;
        int res1 = binary_searchFirst(num);
        if(res1 == -1)
        {
            std::cout << "-1 -1" << std::endl;
        }
        else
        {
            std::cout << res1 << " " << binary_searchLast(num) << std::endl;
        }
    }
    return 0;
}