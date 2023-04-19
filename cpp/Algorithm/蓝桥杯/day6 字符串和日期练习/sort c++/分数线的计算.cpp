#include <cstdio>
#include <algorithm>

int num[100005];

int main(){

    int number = 0;
    int ans = 0;
    scanf("%d",&number);

    for(int i = 0; i < number; i++){

        scanf("%d",&num[i]);
    }
    std::sort(num,num + number, std::greater<int>());
    for(int i = 0; i < number; i++){

        if(num[i] >= num[(number - 1) / 2]){

            ans++;
        }else{
            
            break;
        }
    }
    printf("%d ",num[(number - 1) / 2]);
    printf("%d",ans);
}