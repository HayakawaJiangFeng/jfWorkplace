#include <iostream>
#include <cstdio>
#include <cstring>

char str[1005] = {};
int main(){

    scanf("%s",str);
    int len = strlen(str);

    for(int i = 0; i < len; i++){

        if(str[i] == 'z'){

            str[i] = 'a';
        }else if(str[i] == 'Z'){

            str[i] = 'A';
        }else if(str[i] >= 'a' && str[i] < 'z' || str[i] >= 'A' && str[i] < 'Z'){

            str[i]++;
        }
    }

    printf("%s",str);

    return 0;
}