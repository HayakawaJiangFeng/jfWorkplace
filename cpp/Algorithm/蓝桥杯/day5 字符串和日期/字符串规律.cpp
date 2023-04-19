#include <iostream>

//A
//ABA
//ABACABA
//ABACABADABACABA

char res[5000000];
int main(){

    int n;
    std::cin >> n;
    int len = 0;

    for(int i = 1; i <= n; i++){

        std::strcat(res + len + 1, res);
        res[len] = 'A' + i - 1;
        len = std::strlen(res);
    }
    printf("%s\n",res);
    return 0;
}