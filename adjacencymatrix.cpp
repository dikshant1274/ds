#include<iostream>
using namespace std;
#define MAX 100
int adj[MAX][MAX];
int maxedges;
int main()
{
  int i,j,choice,n;
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
  cout<<"the adjacency matrix is"<<endl;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      cout<<adj[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
