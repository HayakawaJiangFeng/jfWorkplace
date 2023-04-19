#include <iostream>
#include <queue>

char numberFirst[4];
char numberLast[4];
int visit[10][10][10][10];
struct Node
{
    int num[4];
    int step;
}first, last;

void bfs(){

    Node a,next;
    std::queue<Node> q;
    a = first;
    a.step = 0;
    q.push(a);
    memset(visit,0,sizeof(visit));
    visit[a.num[0]][a.num[1]][a.num[2]][a.num[3]] = 1;
    
    while (!q.empty())
    {
        a = q.front();
        q.pop();
        if(a.num[0] == last.num[0] && a.num[1] == last.num[1] && a.num[2] == last.num[2] && a.num[3] == last.num[3]){

            std::cout << a.step << std::endl;
            return;
        }
        for(int i = 0; i < 4; i++){

            next = a;
            next.num[i]++;
            if(next.num[i] == 10){
                
                next.num[i] = 1;
            }
            if(!visit[next.num[0]][next.num[1]][next.num[2]][next.num[3]]){

                visit[next.num[0]][next.num[1]][next.num[2]][next.num[3]] = 1;
                next.step++;
                q.push(next);
            }
        }
        for(int i = 0; i < 4; i++){

            next = a;
            next.num[i]--;
            if(next.num[i] == 0){
                
                next.num[i] = 9;
            }
            if(!visit[next.num[0]][next.num[1]][next.num[2]][next.num[3]]){

                visit[next.num[0]][next.num[1]][next.num[2]][next.num[3]] = 1;
                next.step++;
                q.push(next);
            }
        }
        for(int i = 0; i < 3; i++){

            next = a;
            next.num[i] = a.num[i + 1];
            next.num[i + 1] = a.num[i];

            if(!visit[next.num[0]][next.num[1]][next.num[2]][next.num[3]]){

                visit[next.num[0]][next.num[1]][next.num[2]][next.num[3]] = 1;
                next.step++;
                q.push(next);
            }
        }
    }
    
}
int main(){

    std::cin >> numberFirst;
    std::cin >> numberLast;

    for(int i = 0; i < 4; i++){

        first.num[i] = numberFirst[i] - '0';
        last.num[i]  = numberLast[i] - '0';
    }

    bfs();

    return 0;
}