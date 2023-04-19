#include <algorithm>
#include <cstdio>
#include <cstring>

int score[35];

int main(){

    int number = 0;
    scanf("%d",&number);

    for(int i = 0; i < number; i++){

        scanf("%d",&score[i]);
    }

    int front;
    scanf("%d",&front);

    std::sort(score, score + front, std::greater<int>());
    int sum = 0;
    for(int i = 0; i < front; i++){

        sum += score[i];
    }

    printf("%.2f\n",1.0 * sum / front);

    return 0;
}