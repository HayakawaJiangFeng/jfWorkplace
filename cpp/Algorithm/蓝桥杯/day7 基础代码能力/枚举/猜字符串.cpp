#include <iostream>
#include <ctime>
#include <cstdio>

int main(){

    srand(time(NULL));
    char str[10] = {};
    char ans[10] = {};
    for(int i = 0; i < 10; i++){

        str[i] = (char)(65 + rand() % 26);
        printf("%c ",str[i]);
    }
    printf("\n");
    for(int i = 0; i < 10; i++){

        for(int j = 0; j < 26; j++){

            if(str[i] == (char)(65 + j)){

                ans[i] = (char)(65 + j);
            }
        }
    }
    for(int i = 0; i < 10; i++){

        printf("%c ",ans[i]);
    }
    printf("\n");

    return 0;
}