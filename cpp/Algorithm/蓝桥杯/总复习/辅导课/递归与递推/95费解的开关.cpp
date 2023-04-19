#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

const int N = 6;

char map[N][N];
char backups[N][N];
int next[5][2] = {{0,0},{1,0},{0,1},{-1,0},{0,-1}};

void turns(int x, int y){

    for(int i = 0; i < 5; i++){

        int xx = x + next[i][0];
        int yy = y + next[i][1];

        if(xx >= 0 && xx < 5 && yy >= 0 && yy < 5){

            map[xx][yy] ^= 1;
        }
    }
}
int main(){

    int t = 0;
    std::cin >> t;

    while (t--)
    {

        for(int i = 0; i < 5; i++){

            std::cin >> map[i];
        }

        int res = 10;
        
        for(int op = 0; op < 32; op++){

            memcpy(backups, map, sizeof(map));
            int step = 0;

            for(int i = 0; i < 5; i++){

                if(op >> i & 1){

                    step++;
                    turns(0,i);
                }
            }

            for(int i = 0; i < 4; i++){

                for(int j = 0; j < 5; j++){

                    if(map[i][j] == '0'){

                        step++;
                        turns(i + 1,j);
                    }
                }
            }

            bool dark = false;
            for(int i = 0; i < 5; i++){

                if(map[4][i] == '0'){

                    dark = true;
                    break;
                }
            }

            if(!dark){

                res = std::min(res, step);
            }

            memcpy(map, backups, sizeof(backups));
        }
        
        if(res > 6){

            std::cout << -1 << std::endl;
        }else{

            std::cout << res << std::endl;
        }
    }
    
    return 0;
}