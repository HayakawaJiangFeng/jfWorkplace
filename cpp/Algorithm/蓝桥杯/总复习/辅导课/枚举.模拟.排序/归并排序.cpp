#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

const int Max = 100010;

int n;
int array[Max];
int temp[Max];

void merge_sort(int left, int right){

    if(left >= right) return;

    int mid = (left + right) >> 1;

    merge_sort(left, mid), merge_sort(mid + 1, right);

    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right)
    {
        if(array[i] < array[j]) temp[k++] = array[i++];
        else temp[k++] = array[j++];
    }
    while (i <= mid)
    {
        temp[k++] = array[i++];
    }
    while (j <= right)
    {
        temp[k++] = array[j++];
    }
    
    for(int i = left, j = 0; i <= right; i++, j++) array[i] = temp[j];
}
int main(){

    std::cin >> n;
    
    for(int i = 0; i < n; i++) scanf("%d", &array[i]);

    merge_sort(0, n -1);

    for(int i = 0; i < n; i++) printf("%d ",array[i]);

    puts("");

    return 0;
}