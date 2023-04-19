#include <iostream>

/*
11 9
.#.........
.#.#######.
.#.#.....#.
.#.#.###.#.
.#.#..@#.#.
.#.#####.#.
.#.......#.
.#########.
...........
*/
int W,H;
int cnt;
char map[30][30];
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
bool st[30][30];

bool in(int x, int y){

    return x >= 0 && x < H && y >= 0 && y < W;
}

void dfs(int x, int y){

    for(int i = 0; i < 4; i++){

        int tx = x + next[i][0];
        int ty = y + next[i][1];

        if(in(tx,ty) && map[tx][ty] != '#' && !st[tx][ty]){

            st[tx][ty] = true;
            cnt++;
            dfs(tx,ty);
        }
    }
}

int main(){

    std::cin >> W >> H;

    for(int i = 0; i < H; i++){

        scanf("%s",map[i]);
    }

   /*for(int i = 1; i <= H; i++){

        for(int j = 1; j <= W; j++){

            printf("%c",map[i][j]);
        }
        printf("\n");
    }*/

    int x; int y;
    for(int i = 0; i < H; i++){

        for(int j = 0; j < W; j++){

            if(map[i][j] == '@'){

                x = i;
                y = j;
            }
        }
    }

    st[x][y] = true;
    dfs(x,y);
    cnt++;
    printf("%d\n",cnt);

    return 0;
}