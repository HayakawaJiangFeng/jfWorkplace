#include <iostream>

bool row[10],x1[20],x2[20];
int ans;

bool check(int r, int i){

    return !row[i] && !x1[r + i] && !x2[r - i + 8];
}

void dfs(int r){

    if(r == 8){

        ans++;
        return;
    }
    for(int i = 0; i < 8; i++){

        if(check(r, i)){

            row[i] = x1[r + i] = x2[r - i + 8] = true;
            dfs(r + 1);
            row[i] = x1[r + i] = x2[r - i + 8] = false;
        }
    }
}

int main(){

    dfs(0);
    std::cout << ans << std::endl;

    return 0;
}