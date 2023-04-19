#include <iostream>

/*
10 12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.
*/
int N,M;
int cnt;
char map[110][110];
int next[8][2] = {{-1,0},{0,-1},{1,0},{0,1},{-1,-1},{1,1},{-1,1},{1,-1}};
bool st[110][110];

bool in(int x, int y){

    return x >= 0 && x < N && y >= 0 && y < M;
}

void dfs(int x, int y){

    for(int i = 0; i < 8; i++){

        int tx = x + next[i][0];
        int ty = y + next[i][1];

        if(map[tx][ty] == 'W' && in(tx,ty) && !st[tx][ty]){

            st[tx][ty] = true;
            dfs(tx, ty);
        }
    }
}

int main(){

    scanf("%d %d",&N,&M);

    for(int i = 0; i < N; i++){

        for(int j = 0; j < M; j++){

            scanf(" %c",&map[i][j]);
        }
    }

    for(int i = 0; i < N; i++){

        for(int j = 0; j < M; j++){

            if(map[i][j] == 'W' && !st[i][j]){

                cnt++;
                dfs(i,j);
            }
        }
    }

    std::cout << cnt << std::endl;

    return 0;
}