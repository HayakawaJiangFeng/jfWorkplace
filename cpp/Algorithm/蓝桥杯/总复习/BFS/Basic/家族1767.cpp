#include <iostream>
#include <queue>

int n;
int length[500];
int next[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int map[500][500];
std::string str;
std::queue<std::pair<int, int> > q;

void bfs(int x, int y){

    map[x][y] = 0;
    q.push(std::make_pair(x,y));

    while (q.size())
    {
        
        std::pair<int, int> temp = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            
            int xx = temp.first + next[i][0];
            int yy = temp.second + next[i][1];

            if(xx > 0 && xx <= n && yy > 0 && yy <= length[xx] && map[xx][yy] == 1){

                map[xx][yy] = map[temp.first][temp.second];
                q.push(std::make_pair(xx,yy));
            }
        }
    }
}

int main(){

    std::cin >> n;
    getline(std::cin,str);

    for(int i = 1; i <= n; i++){

        getline(std::cin,str);
        int len = str.size();
        length[i] = len;
        for(int j = 1; j <= len; j++){

            if(str[j - 1] >= 'a' && str[j - 1] <= 'z'){

                map[i][j] = 1;
            }
        }
    }

    int res = 0;

    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= length[i]; j++){

            if(map[i][j]){

                res++;
                bfs(i,j);
            }
        }
    }
    
    /*
    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= length[i]; j++){

            std::cout << map[i][j] << " ";
        }
        std::cout << std::endl;
    }
    */

    std::cout << res << std::endl;

    return 0;
}