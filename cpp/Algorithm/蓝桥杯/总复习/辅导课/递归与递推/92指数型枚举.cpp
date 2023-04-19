#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 20;

int n;
int st[N];
int ans[N];
vector<vector<int> > ways;

void dfs(int x){

    if(x > n){

        vector<int> way;
        for(int i = 1; i <= n; i++){

            if(st[i] == 2){

                way.push_back(i);
            }
        }
        ways.push_back(way);
        return;
    }

    //不选
    st[x] = 1;
    dfs(x + 1);
    st[x] = 0;

    //选
    st[x] = 2;
    dfs(x + 1);
    st[x] = 0;
}
int main(){

    cin >> n;
    
    dfs(1);

    for(int i = 0; i < ways.size(); i++){

        for(int j = 0; j < ways[i].size(); j++){

            printf("%d ",ways[i][j]);
        }
        puts("");
    }
    return 0;
}