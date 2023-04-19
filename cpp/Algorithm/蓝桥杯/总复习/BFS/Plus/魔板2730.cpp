#include <iostream>
#include <queue>
#include <unordered_map>

std::string end;
std::string start = "12345678";
std::queue<std::string> q;
std::unordered_map<std::string, int> distance;
std::unordered_map<std::string, std::pair<char, std::string> > load;

char matrix[2][4];

void strToMatrix(std::string str){
    
    for(int i = 0; i < 4; i++){

        matrix[0][i] = str[i];
    }
    for(int i = 3,j = 4; i >= 0; j++,i--){

        matrix[1][i] = str[j];
    }
}
std::string matrixToStr(){

    std::string res = "";
    for(int i = 0; i < 4; i++){

        res += matrix[0][i];
    }
    for(int i = 3; i >= 0; i--){

        res += matrix[1][i];
    }
    return res;
}
std::string moveA(std::string str){

    strToMatrix(str);
    std::swap(matrix[0],matrix[1]);

    std::string res = matrixToStr();

    return res;
}
std::string moveB(std::string str){

    strToMatrix(str);
    char tempU = matrix[0][3];
    char tempD = matrix[1][3];

    for(int i = 3; i >= 1; i--){

        matrix[0][i] = matrix[0][i - 1];
        matrix[1][i] = matrix[1][i - 1];
    }
    matrix[0][0] = tempU;
    matrix[1][0] = tempD;

    std::string res = matrixToStr();

    return res;
}
std::string moveC(std::string str){

    strToMatrix(str);
    char temp = matrix[0][1];
    matrix[0][1] = matrix[1][1];
    matrix[1][1] = matrix[1][2];
    matrix[1][2] = matrix[0][2];
    matrix[0][2] = temp;
    
    std::string res = matrixToStr();

    return res;
}

int bfs(std::string start){

    q.push(start);
    distance[start] = 0;
    
    while (q.size())
    {
        std::string temp = q.front();
        q.pop();

        if(temp == end){

            return distance[temp];
        }
        int dist = distance[temp];

        std::string strs[3] = {moveA(temp),moveB(temp),moveC(temp)};

        for(int i = 0; i < 3; i++){

            std::string str = strs[i];
            if(!distance.count(str)){

                distance[str] = dist + 1;
                load[str] = (std::make_pair(char('A' + i),temp));
                q.push(str);
            }
        }
    }
    return -1;
}
int main(){

    for(int i = 0; i < 8; i++){

        int temp;
        std::cin >> temp;
        end += temp + '0';
    }

    std::cout << bfs(start) << std::endl;

    std::string res = "";
    while (end != start)
    {
        res += load[end].first;
        end = load[end].second;
    }
    std::reverse(res.begin(),res.end());

    if(res.size()){

        std::cout << res << std::endl;
    }
    
    return 0;
}