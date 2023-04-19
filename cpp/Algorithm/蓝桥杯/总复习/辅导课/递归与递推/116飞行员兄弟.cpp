#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

char map[5][5];
char backups[5][5];

int getIndex(int x, int y){

    return x * 4 + y;
}
void turnOne(int x, int y){

    if(map[x][y] == '+'){

        map[x][y] = '-';
    }else{

        map[x][y] = '+';
    }
}
void turnAll(int x, int y){

    turnOne(x,y);
    for(int i = 0; i < 4; i++){

        turnOne(x,i);
        turnOne(i,y);
    }
}
int main(){

    for(int i = 0; i < 4; i++){

        for(int j = 0; j < 4; j++){

            std::cin >> map[i][j];
        }
    }

    std::vector<std::pair<int, int> > res;

    for(int i = 0; i < (1 << 16); i++){

        memcpy(backups, map, sizeof(backups));
        std::vector<std::pair<int, int> > temp;

        for(int j = 0; j < 4; j++){

            for(int k = 0; k < 4; k++){

                if(i >>getIndex(j,k) & 1){

                    temp.push_back(std::make_pair(j,k));
                    turnAll(j,k);
                }
            }
        }

        bool is_closed = false;

        for(int i = 0; i < 4; i++){

            for(int j = 0; j < 4; j++){

                if(map[i][j] == '+'){

                    is_closed = true;
                }              
            }
        }

        if(!is_closed){

            if(res.empty() || temp.size() < res.size()){

                res = temp;
            }
        }

        memcpy(map, backups, sizeof(map));
    }

    std::cout << res.size() << std::endl;

    for(std::vector<std::pair<int, int> >::iterator it = res.begin(); it != res.end(); it++){

        std::cout << it->first + 1 << " " << it->second + 1 << std::endl;
    }

    return 0;
}