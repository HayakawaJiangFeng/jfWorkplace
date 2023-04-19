#include <iostream>

int n,m;
int numbers[1000005];

int binary_search(int x){

    int left = -1;
    int right = n;

    while (left + 1 != right)
    {
        int mid = (left + right) / 2;
        
        if(numbers[mid] < x){

            left = mid;
        }else{

            right = mid;
        }
    }
    if(numbers[right] == x){

        return right;
    }else{

        return -1;
    }
}
int main(){

    scanf("%d %d",&n,&m);

    for(int i = 0; i < n; i++){

        scanf("%d",&numbers[i]);
    }

    for(int i = 0; i < m; i++){

        int num;
        scanf("%d",&num);
        if(binary_search(num) == -1){

            if(i != m - 1){

                printf("-1 ");
            }else{

                printf("-1\n");
            }
        }else{

            if(i != m - 1){

                printf("%d ",binary_search(num) + 1);
            }else{

                printf("%d\n",binary_search(num) + 1);
            }
        }
    }

    return 0;
}