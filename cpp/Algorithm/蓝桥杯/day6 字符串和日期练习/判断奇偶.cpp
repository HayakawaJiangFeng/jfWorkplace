#include <cstdio>
#include <cstring>

char number[] = {};

int main(){

    scanf("%s",number);

    int len = strlen(number);
    char last = number[len - 1];

    int lastNum = last - '0';

    if(lastNum % 2 == 0){

        printf("YES");
    }else{

        printf("NO");
    }

    return 0;
}