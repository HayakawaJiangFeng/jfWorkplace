#include <cstdio>
#include <algorithm>

char colors[10005];

int main(){

    scanf("%s",colors);

    int len = std::strlen(colors);
    std::sort(colors,colors + len);

    printf("%s\n",colors);

    int b = 0;
    int g = 0;
    int r = 0;
    for(int i = 0; i < len; i++){

        if(colors[i] == 'B'){
            
            b++;
        }else if(colors[i] == 'G'){

            g++;
        }else{

            r++;
        }
    }
    printf("%d\n",std::min(r,std::min(g / 2,b / 3)));

    return 0;
}