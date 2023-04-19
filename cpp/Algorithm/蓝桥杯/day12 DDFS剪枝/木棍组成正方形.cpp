#include <iostream>

int n,sum;
int length[20];
int osls[4];
bool visit[20];
bool flag;
int osl;

void dfs(int cnt, int pos){

    if(cnt == 4){

        flag = true;
        return;
    }
    if(flag){

        return;
    }
    if(osls[cnt] > osl){
        
        return;
    }
    if(osls[cnt] == osl){

        dfs(cnt + 1, pos);
    }else{

        for(int i = pos; i <= n; i++){

            if(!visit[i]){

                visit[i] = true;
                osls[i] += length[i];
                dfs(cnt, i + 1);
                osls[i] -= length[i];
                visit[i] = false;
            }
        }
    }

}
int main(){

    std::cin >> n;

    for(int i = 0; i < n; i++){

        std::cin >> length[i];
    }
    int sum = 0;
    for(int i = 0; i < n; i++){

        sum += length[i];
    }
    osl = sum / 4;

    if(sum % 4 != 0){

        std::cout << "no" << std::endl;
    }else{

        dfs(1,1);
        if(flag){

            std::cout << "yes" << std::endl;
        }else{

            std::cout << "no" << std::endl;
        }
    }
}