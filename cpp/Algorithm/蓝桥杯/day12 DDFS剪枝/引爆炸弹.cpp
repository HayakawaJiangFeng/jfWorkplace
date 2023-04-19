#include <iostream>

int n,m,ans;
std::string map[1000];
bool mapX[1000];
bool mapY[1000];

void boom(int x, int y){

    map[x][y] = 0;
    if(!mapX[x]){

        mapX[x] = true;
        for(int i = 0; i < m; i++){

            if(map[x][i] == '1'){

                boom(x,i);
            }
        }
    }
    if(!mapY[y]){

        mapY[y] = true;
        for(int i = 0; i < n; i++){

            if(map[i][y] == '1'){

                boom(i,y);
            }
        }
    }
}

int main(){

    std::cin >> n >> m;
    for(int i = 0; i < n; i++){

        for(int j = 0; j < m; j++){

            std::cin >> map[i][j];
        }
    }

    for(int i = 0; i < n; i++){

        for(int j = 0; j < m; j++){

            if(map[i][j] == '1'){

                ans++;
                boom(i,j);
            }
        }
    }
    std::cout << ans << std::endl;
    
    return 0;
}