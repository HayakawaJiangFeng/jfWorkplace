#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

const int Max = 10010;

int n;
int values[Max];
int backups[Max];

int main(){

    std::cin >> n;

    int res = 0;

    for(int i = 1; i <= n; i++){

        scanf("%d", &values[i]);
    }

    for(int i = 1; i <= n; i++){

        memcpy(backups, values, sizeof(backups));
        for(int j = i; j <= n; j++){

            std::sort(values + i, values + j);
            
            bool flag = false;
            for(int k = i; k < j - i + 1; k++){

                if(values[k] + 1 != values[k + 1]){

                    flag = true;
                    break;
                }
            }
            if(!flag){

                res++;
            }
        }
        memcpy(values, backups, sizeof(values));
    }
    std::cout << res << std::endl;

    return 0;
}