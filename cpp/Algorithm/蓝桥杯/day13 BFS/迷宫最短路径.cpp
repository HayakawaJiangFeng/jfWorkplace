#include <iostream>
#include <queue>

int n,m;
char maze[100][100];
bool visit[100][100];
int steps[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

bool in(int x, int y){

    return x >= 0 && x < n && y >= 0 && y < m;
}
struct Node
{
    int x,y,step;
    Node(int x, int y, int step){

        this->x = x;
        this->y = y;
        this->step = step;
    }
};

int bfs(int x, int y){

    std::queue<Node> nodes;
    
    nodes.push(Node(x, y, 0));

    visit[x][y] = true;

    while (!nodes.empty())
    {
        Node temp = nodes.front();
        nodes.pop();

        for(int i = 0; i < 4; i++){

            int tx = temp.x + steps[i][0];
            int ty = temp.y + steps[i][1];           
            if(maze[tx][ty] != '*' && in(tx,ty) && !visit[tx][ty]){

                if(maze[tx][ty] == 'T'){

                    return temp.step + 1;
                }else{

                    visit[tx][ty] = true;
                    nodes.push(Node(tx,ty,temp.step + 1));
                }
            }
        }
    }
    return -1;
}

int main(){

    std::cin >> n >> m;

    for(int i = 0; i < n; i++){

        for(int j = 0; j < m; j++){

            std::cin >> maze[i][j];
        }
    }

    int x,y;
    
    for(int i = 0; i < n; i++){

        for(int j = 0; j < m; j++){

            if(maze[i][j] == 'S'){

                x = i;
                y = j;
            }
        }
    }

    std::cout << bfs(x, y) << std::endl;
    
    return 0;
}