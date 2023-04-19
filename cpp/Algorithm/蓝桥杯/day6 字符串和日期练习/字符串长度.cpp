#include <cstdio>
#include <cstring>

char str[105],ans[105];
int ansLen = 0;

int main(){

    int len, number;
    scanf("%d",&number);

    for(int i = 0; i < number; i++){

        scanf("%s",str);
        len = strlen(str);
        if(len > ansLen){

            ansLen = len;
            strcpy(ans,str);
        }
    }
    printf("%s",ans);
    
    return 0;
}