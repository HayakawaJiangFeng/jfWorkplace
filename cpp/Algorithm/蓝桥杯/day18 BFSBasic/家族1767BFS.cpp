#include <iostream>
#include <queue>

int n;
int res;
int lengths[600];
int map[600][600];
int next[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};
std::string str;
std::queue<std::pair<int, int > > q;

void bfs(int x, int y){

    q.push(std::make_pair(x,y));
    map[x][y] = 0;

    while (!q.empty())
    {
        
        std::pair<int, int> temp = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            
            int xx = temp.first + next[i][0];
            int yy = temp.second + next[i][1];

            if(xx > 0 && xx <= n && yy > 0 && yy <= lengths[xx] && map[xx][yy] == 1){

                map[xx][yy] = 0;
                q.push(std::make_pair(xx,yy));
            }
        }
    }
    
}
int main(){

    std::cin >> n;
    getline(std::cin, str);

    for(int i = 1; i <= n; i++){

        getline(std::cin ,str);
        lengths[i] = str.length();

        for(int j = 1; j <= str.length(); j++){

            if(str[j - 1] >= 'a' && str[j - 1] <= 'z'){

                map[i][j] = 1;
            }
        }
    }
    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= lengths[i]; j++){

            if(map[i][j] == 1){

                bfs(i,j);
                res++;
            }
        }
    }

    std::cout << res << std::endl;

    return 0;
}
