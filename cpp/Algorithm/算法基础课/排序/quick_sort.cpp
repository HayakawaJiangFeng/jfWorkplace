#include <iostream>

const int Max = 1e5 + 10;

int array[Max];

void quick_sort(int array[], int left, int right)
{
    if(left >= right) return;

    int temp = array[(left + right) >> 1];
    int i = left - 1;
    int j = right + 1;

    while (i < j)
    {
        do i++; while (array[i] < temp);
        do j--; while (array[j] > temp);

        if(i < j) std::swap(array[i], array[j]);
    }
    
    quick_sort(array, left, j);
    quick_sort(array, j + 1, right);
}

int main()
{
    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        scanf("%d",&array[i]);
    }

    quick_sort(array, 0, n - 1);

    for(int i = 0; i < n; i++)
    {
        printf("%d ",array[i]);
    }   
    puts("");   

    return 0;
}