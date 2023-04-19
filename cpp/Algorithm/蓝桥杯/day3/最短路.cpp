#include <iostream>
#include <cstring>
using namespace std;
const int N=200,n=19;
int dist[N];
int g[N][N];
void add(char x,char y,int c)
{
  int a=x-'A'+1;
  int b=y-'A'+1;
  g[a][b]=g[b][a]=c;
}
bool vis[N];
int dijkstra()
{
  memset(dist,0x3f,sizeof dist);
  dist[1]=0;
  for(int i=0;i<n;i++)
  {
    int t=-1;
    for(int j=1;j<=n;j++)
    {
      if(!vis[j]&&(t==-1||dist[j]<dist[t]))
        t=j;
    }
    vis[t]=1;

    for(int j=1;j<=n;j++)
    {
      dist[j]=min(dist[j],dist[t]+g[t][j]);
    }
  }
  return dist[n];
}
int main()
{
    memset(g,0x3f,sizeof g);
    add('A','B',2);
    add('A','C',1);
    add('A','D',1);
    add('A','D',1);
    add('B','J',2);
    add('B','G',1);
    add('C','D',3);
    add('C','F',3);
    add('C','G',3);
    add('D','E',1);
    add('D','G',2);
    add('D','H',1);
    add('D','I',2);
    add('E','H',1);
    add('E','I',3);
    add('F','G',1);
    add('F','J',1);
    add('G','F',1);
    add('G','I',3);
    add('G','K',2);
    add('H','I',1);
    add('H','L',2);
    add('I','M',3);
    add('J','S',2);
    add('K','N',1);
    add('K','L',3);
    add('K','P',2);
    add('L','M',1);
    add('L','R',1);
    add('M','N',2);
    add('M','Q',1);
    add('M','S',1);
    add('N','P',1);
    add('O','P',1);
    add('O','Q',1);
    add('O','R',3);
    add('R','S',1);
    cout<<dijkstra();
  return 0;
}