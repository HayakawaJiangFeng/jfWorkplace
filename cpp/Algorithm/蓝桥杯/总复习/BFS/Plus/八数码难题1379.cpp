#include <iostream>
#include <queue>
#include <unordered_map>

std::string end = "123804765";
std::string start;
std::queue<std::string> q;
std::unordered_map<std::string, int> distance;
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

char matrix[3][3];

bool in(int xx, int yy){

    return xx >= 0 && xx < 3 && yy >= 0 && yy < 3;
}

int bfs(std::string start){

    distance[start] = 0;
    q.push(start);

    while (q.size())
    {
        std::string temp = q.front();
        if(temp == end){

            return distance[temp];
        }
        int dist = distance[temp];
        q.pop();

        for(int i = 0; i < 4; i++){

            int index0 = temp.find('0');
            int xx = index0 / 3 + next[i][0];
            int yy = index0 % 3 + next[i][1];

            if(in(xx,yy)){

                std::swap(temp[index0],temp[xx * 3 + yy]);
                
                if(!distance.count(temp)){

                    distance[temp] = dist + 1;
                    q.push(temp);
                }
                std::swap(temp[index0],temp[xx * 3 + yy]);
            }
        }
    }
    return -1;
}
int main(){

    std::cin >> start;

    std::cout << bfs(start) << std::endl;
    
    return 0;
}