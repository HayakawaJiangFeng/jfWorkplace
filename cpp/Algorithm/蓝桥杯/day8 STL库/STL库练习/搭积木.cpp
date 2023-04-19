#include <iostream>
#include <cstdio>
#include <vector>

/*
n块积木(编号1-n)对应n个位置，m次移动，b位置的积木移动到a位置的积木上，输出位置(1-n)低到高的积木编号,
若该位置不存在积木，输出换行
*/

std::vector<int> v1[1005];

int main(){

    int n,m,a,b;
    std::cin >> n >> m;

    for(int i = 1; i <= n; i++){

        v1[i].push_back(i);
    }
    for(int i = 0; i < m; i++){

        std::cin >> a >> b;
        if(a == b){

            continue;
        }else{

            for(int j = 0; j < v1[b].size(); j++){

                v1[a].push_back(v1[b][j]);
            }
            std::vector<int>().swap(v1[b]);
        }
    }
    for(int i = 0; i < n; i++){

        for(int j = 0; j < v1[i].size(); j++){

            if(i != v1[i].size() - 1){

                printf("%d ",v1[i][j]);
            }else{

                printf("%d",v1[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
