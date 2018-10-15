#include<iostream>
#include<stack>
#include<queue>
using namespace std;
void rev(queue<int> &q,int k,int i=0)
{
  stack<int> s;
  if(i!=k)
  {
    s.push(q.front());
    q.pop();
    i++;
    rev(q,k,i);

  }
  else
  {
    return;
  }
  int l=s.top();
  q.push(l);
  s.pop();

}
void disp(queue<int> q)
{
  for(int i=0;i<q.size();i++)
  {
    cout<<q.front()<<endl;
    q.pop();
  }
}
int main()
{
  queue<int> q;
  int i,n,val;
  cin>>n;
  for(i=0;i<n;i++)
  {
    cin>>val;
    q.push(val);
  }
  int k;
  cin>>k;
  rev(q,k);
  disp(q);
}
