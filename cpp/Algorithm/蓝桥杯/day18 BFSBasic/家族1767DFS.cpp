/*
4
*zlw**pxh
l*zlwk*hx*
w*tyy**yyy
        zzl

3
*/

#include <iostream>

int n;
int res;
std::string str;
int lengths[500];
int map[500][500];
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

void dfs(int x, int y){

    map[x][y] = 0;
    for(int i = 0; i < 4; i++){

        int xx = x + next[i][0];
        int yy = y + next[i][1];

        if(xx > 0 && xx <= n && yy > 0 && yy <= lengths[x] && map[xx][yy] == 1){

            dfs(xx,yy);
        }
    }
}
int main(){

    std::cin >> n;
    getline(std::cin, str);
    for(int i = 1; i <= n; i++){

        getline(std::cin, str);
        lengths[i] = str.size();
        for(int j = 1; j <= str.size(); j++){

            if(str[j - 1] >= 'a' && str[j - 1] <= 'z'){

                map[i][j] = 1;
            }
        }
    }

    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= lengths[i]; j++){

            if(map[i][j]){

                dfs(i,j);
                res++;
            }
        }
    }
    std::cout << res << std::endl;

    return 0;
}