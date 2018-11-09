#include<iostream>
#include<stack>
using namespace std;
#define MAX 100
int adj[MAX][MAX];
#define initial 1
#define visited 2
int n;
int state[MAX];
int maxedges;
void dfs(int v)
{
  stack <int> s;
  s.push(v);
  while(!s.empty())
  {
    v=s.top();
    s.pop();
    if(state[v]==initial)
    {
    cout<<v<<" ";
    state[v]=visited;
    }
    for(int i=n-1;i>=0;i--)
    {
      if(adj[v][i]==1&&state[i]==initial)
      {
        s.push(i);
      }
    }
  }
}
void df_traversal()
{
  for(int i=0;i<n;i++)
  {
    state[i]=initial;
  }
  int v;
  cin>>v;
  dfs(v);
  for(int i=0;i<n;i++)
  {
    if(state[i]==initial)
    {
      dfs(v);
    }
  }
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
df_traversal();
  return 0;
}
