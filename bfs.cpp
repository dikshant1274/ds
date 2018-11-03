#include<iostream>
#include<queue>
using namespace std;
#define MAX 100
int adj[MAX][MAX];
#define initial 1
#define waiting 2
#define visited 3
int n;
int state[MAX];
int maxedges;
void bfs(int v)
{
  queue<int> q;
  q.push(v);
  state[v]=waiting;
  while(!q.empty())
  {
    v=q.front();
    q.pop();
    cout<<v<<" ";
    state[v]=visited;
    for(int i=0;i<n;i++)
    {
      if(adj[v][i]==1&&state[i]==1)
      {
        q.push(i);
        state[i]=waiting;
      }
    }
  }
}
void bf_traversal()
{
  int v;
  for(int i=0;i<n;i++)
  {
    state[i]=initial;
  }
  cin>>v;
  bfs(v);

}
int main()
{
  int i,j,choice;
  int origin,destin;
  cin>>n;
  cin>>choice;
  if(choice==1)
  {
    maxedges=n*(n-1)/2;
  }
  else
  {
    maxedges=n*(n-1);
  }
  for(i=0;i<maxedges;i++)
  {
    cin>>origin>>destin;
    if(origin==-1&&destin==-1)
    break;
    else if(origin>=n||destin>=n||origin<0||destin<0)
    {
      cout<<"invalid origin and destination"<<endl;
      i--;
    }
    else
    {
      adj[origin][destin]=1;
      if(choice==1)
      adj[destin][origin]=1;
    }
  }
bf_traversal();
  return 0;
}
