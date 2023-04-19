#include <iostream>

//n根木棍，全部木棍都得用到，这些木棍组成等边三角形

int n;
int p[20];
bool visit[20];
int sum = 0;
bool flag = false;

void dfs(int cnt, int s, int st){

    if(flag){

        return;
    }
    if(cnt == 3){

        flag = true;
        return;
    }
    if(s == sum / 3){

        dfs(cnt + 1,0,0);
        return;
    }
    for(int i = st; i < n; i++){

        if(!visit[i]){

            visit[i] = true;
            dfs(cnt, s + p[i], i + 1);
            visit[i] = false;
        }
    }
}
int main(){

    std::cin >> n;
    for(int i = 0; i < n; i++){

        std::cin >> p[i];
        sum += p[i];
    }
    if(sum % 3 != 0){

        std::cout << "no" << std::endl;
    }else{

        dfs(0,0,0);
        if(flag){

            std::cout << "yes" << std::endl;
        }else{

            std::cout << "no" << std::endl;
        }
    }

    return 0;
}