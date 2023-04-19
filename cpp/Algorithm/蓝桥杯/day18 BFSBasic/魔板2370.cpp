#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

std::string end;
std::string start;
std::queue<std::string> q;
std::unordered_map<std::string, int> distance;
std::unordered_map<std::string, std::pair<char, std::string> > load;

char matrix24[2][4];

void stringToMatrix(std::string str){

    for(int i = 0; i < 4; i++){

        matrix24[0][i] = str[i];
    }
    for(int i = 3,j = 4; i >= 0; i--,j++){

        matrix24[1][i] = str[j];
    }
}
std::string matrixToString(){

    std::string temp;
    for(int i = 0; i < 4; i++){

        temp += matrix24[0][i];
    }
    for(int i = 3; i >= 0; i--){

        temp += matrix24[1][i];
    }
    return temp;
}
std::string moveA(std::string str){

    stringToMatrix(str);
    std::swap(matrix24[0],matrix24[1]);

    std::string res = matrixToString();

    return res;
}
std::string moveB(std::string str){

    stringToMatrix(str);
    char tempU = matrix24[0][3];
    char tempD = matrix24[1][3];

    for(int i = 0; i < 2; i++){

        for(int j = 3; j >= 0; j--){

            matrix24[i][j] = matrix24[i][j - 1];
        }
    }
    matrix24[0][0] = tempU;
    matrix24[1][0] = tempD;

    std::string res = matrixToString();

    return res;
}
std::string moveC(std::string str){

    stringToMatrix(str);
    char temp = matrix24[0][1];
    matrix24[0][1] = matrix24[1][1];
    matrix24[1][1] = matrix24[1][2];
    matrix24[1][2] = matrix24[0][2];
    matrix24[0][2] = temp;

    std::string res = matrixToString();
    
    return res;
}

int bfs(std::string start, std::string end){

    q.push(start);
    distance[start] = 0;

    while (q.size())
    {
        
        std::string temp = q.front();
        q.pop();

        if(temp == end){

            return distance[end];
        }

        std::string moveWay[3] = {moveA(temp), moveB(temp), moveC(temp)};

        for(int i = 0; i < 3; i++){

            std::string str = moveWay[i];
            if(!distance.count(str)){

                distance[str] = distance[temp] + 1;
                load[str] = (std::make_pair(char(i + 'A'),temp));
                if(str == end){

                    return distance[end];
                }
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
    start = "12345678";

    /*
    for(int i = 0; i < 2; i++){

        for(int j = 0; j < 4; j++){

            std::cout << matrix24[i][j] << " ";
        }
        std::cout << std::endl;
    }
    */
    int res = bfs(start, end);
    std::cout << res << std::endl;

    std::string res2;
    while (end != start)
    {
        res2 += load[end].first;
        end = load[end].second;
    }
    std::reverse(res2.begin(),res2.end());

    if(res2.size()){

        std::cout << res2 << std::endl;
    }
    
    return 0;
}