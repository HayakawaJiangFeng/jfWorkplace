#include <iostream>

const int Max = 1e5 + 10;

int array[Max];
int temp[Max];

void merge_sort(int array[], int left, int right)
{
    if(left >= right) return;

    int mid = (left + right) >> 1;
    merge_sort(array, left, mid);
    merge_sort(array, mid + 1, right);

    int cnt = 0;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right)
    {
        if(array[i] <= array[j])
        {
            temp[cnt++] = array[i++];
        }
        else
        {
            temp[cnt++] = array[j++];
        }
    }
    while (i <= mid)
    {
        temp[cnt++] = array[i++];
    }
    while (j <= right)
    {
        temp[cnt++] = array[j++];
    }
    for(i = left, j = 0; i <= right; j++,i++)
    {
        array[i] = temp[j];
    }   
}

int main()
{
    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        scanf("%d",&array[i]);
    }

    merge_sort(array, 0, n - 1);

    for(int i = 0; i < n; i++)
    {
        printf("%d ",array[i]);
    }
    puts("");

    return 0;
}