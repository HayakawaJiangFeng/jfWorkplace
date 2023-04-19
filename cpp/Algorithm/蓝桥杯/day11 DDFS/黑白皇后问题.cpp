#include <iostream>

int n,ans;
int map[1005][1005];
int vy[1005],vd1[1005],vd2[1005];

void dfs(int x, int p){

    if(x == n && p == 2){

        ans++;
        return;
    }
    if(x == n){

        dfs(0, p + 1);
        return;
    }
    for(int i = 0; i < n; i++){

        if(map[x][i] && vy[i] != 3 && vy[i] != p && vd1[x + i] != 3 && vd1[x + i] != p && vd2[x - i + n] != 3 && vd2[x - i + n] != p){

            map[x][i] = 0;
            vy[i] += p;
            vd1[x + i] += p;
            vd2[x - i + n] += p;
            dfs(x + 1,  p);
            vy[i] -= p;
            vd1[x + i] -= p;
            vd2[x - i + n] -= p;
            map[x][i] = 1;
        }
    }
}
int main(){

    std::cin >> n;
    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){

            std::cin >> map[i][j];
        }
    }
    dfs(0,1);
    std::cout << ans << std::endl;
    
    return 0;
}