#include <iostream>

int n;
std::string words[30];
int used[30];
int load[30][30];
int res;

void dfs(std::string dragon, int x){

    res = std::max((int)dragon.size(), res);

    used[x]++;
    for(int i = 0; i < n; i++){

        if(load[x][i] && used[i] < 2){

            dfs(dragon + words[i].substr(load[x][i]), i);
        }
    }
    used[x]--;
}
int main(){

    std::cin >> n;

    for(int i = 0; i < n; i++){

        std::cin >> words[i];
    }
    char start;
    std::cin >> start;

    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){

            std::string a = words[i];
            std::string b = words[j];

            for(int k = 1; k < std::min(a.size(), b.size()); k++){

                if(a.substr(a.size() - k, k) == b.substr(0,k)){

                    load[i][j] = k;
                    break;
                }
            }
        }
    }
    for(int i = 0; i < n; i++){

        if(words[i][0] == start){
            
            dfs(words[i], i);
        }
    }
    std::cout << res << std::endl;

    return 0;
}