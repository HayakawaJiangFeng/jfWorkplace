#include <iostream>

int main(){

    char str1[1005];
    char str2[1005];

    fgets(str1,1004,stdin);
    fgets(str2,1004,stdin);

    int len1 = std::strlen(str1) - 1;
    int len2 = std::strlen(str2) - 1;
    
    int ans = 0;

    for(int i = 0; i + len2 - 1 < len1; i++){

        bool matched = true;
        for(int j = 0; j < len2; j++){

            if(str1[i + j] != str2[j]){

                matched = false;
                break;
            }
        }
        if(matched){
            ans++;
        }
    }
    std::cout << ans << std::endl;
}