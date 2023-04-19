#include <cstdio>
#include <stack>

int numbers[10];

int* my_quickSort(int array[], int size){

    int pivot;

    std::stack<int> less;
    std::stack<int> greater;
    int newArray[size];

    if(size < 2){

        return array;
    }else{

        pivot = array[0];
        for(int i = 1; i < size; i++){

            if(array[i] <= pivot){

                less.push(array[i]);
            }
        }       
        for(int i = 1; i < size; i++){

            if(array[i] > pivot){

                greater.push(array[i]);
            }
        }
        int i = 0;
        while (less.top())
        {
            newArray[i++] = less.top();
            less.pop();
        }

        newArray[i] = pivot;

        int j = i + 1;
        while (greater.top())
        {
            newArray[j++] = less.top();
            greater.pop();
        }
        
        return my_quickSort(newArray, j - 1);
    }
}
int main(){

    for(int i = 0; i < 10; i++){

        scanf("%d",&numbers[i]);
    }
    my_quickSort(numbers,10);

    for(int i = 0; i < 10; i++){

        printf("%d ",numbers[i]);
    }
}