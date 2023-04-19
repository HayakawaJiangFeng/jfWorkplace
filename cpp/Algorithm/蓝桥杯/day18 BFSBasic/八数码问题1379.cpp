#include <iostream>
#include <queue>
#include <unordered_map>

std::string start;
std::queue<std::string> q;
std::unordered_map<std::string, int> distance;
int next[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

bool in(int x, int y){

    return x >= 0 && x < 3 && y >= 0 && y < 3;
}
int bfs(std::string start){

    std::string end = "123804765";
    distance[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        std::string temp = q.front();
        q.pop();

        if(temp == end){

            return distance[temp];
        }
        int dist = distance[temp];

        int Index0 = temp.find('0');
        int x1 = Index0 / 3;
        int y1 = Index0 % 3;

        for(int i = 0; i < 4; i++){

            int xx = x1 + next[i][0];
            int yy = y1 + next[i][1];
            
            if(in(xx,yy)){

                int indexTemp = xx * 3 + yy;

                std::swap(temp[Index0],temp[indexTemp]);

                if(!distance.count(temp)){

                    distance[temp] = dist + 1;
                    q.push(temp);
                }
                std::swap(temp[Index0],temp[indexTemp]);
            }
        }
    }
    return -1;
}
int main(){

    std::cin >> start;
    int res = bfs(start);
    std::cout << res << std::endl;

    return 0;
}