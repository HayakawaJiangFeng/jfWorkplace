#include <cstring>
#include <cstdio>

char str[1005] = {};

int main(){

    scanf("%s",str);
    int len = strlen(str);

    for(int i = len - 1; i >= 0; i--){

        printf("%c",str[i]);
    }
    printf("\n");

    return 0;
}